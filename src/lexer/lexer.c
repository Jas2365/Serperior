#include <lexer/lexer.h>
#include <ptr/ptr.h>
#include <lists/my_list.h>
#include <lexer/lexer_defs.h>
#include <lexer/lexer_util.h>

#include <stdlib.h>
#include <stdio.h>

Lexer* sLexer;
List(Token)* sToken;

// =========================================================
// ======================== HELPER ========================= 
// =========================================================

static inline b8 is_eof() {
    return sLexer->current >= sLexer->_end;
}
static inline i8 peek() {
    return *sLexer->current;
}
static inline i8 peek_next() {
    if(is_eof()) return 0;
    else return *(sLexer->current + 1);
}
static inline i8 advance() {
    i8 c = *sLexer->current++;
    sLexer->col++;
    return c;
}

static inline null lexer_newline() {
    sLexer->line++;
    sLexer->col = 0;
}

static inline b8 is_alnum() {
    return char_is(peek(), char_alpha | char_digit);
}

static inline b8 skip_comments() {
    if(peek_next() == char_sl) {
        while(!is_eof() && !char_is(peek(), char_newline))
            advance();
        return true;
    }

    if(peek_next() == char_star) {
        advance(); advance(); // for /*
        while(!is_eof()) {
            if(char_is(peek(), char_newline)) lexer_newline();
            if(peek() == char_star && peek_next() == char_sl) {
                advance(); advance(); break;
            }
            advance();
        }
        return true;
    }
    return false; // lone slash
}

static null skip_whitespaces() {
    while(!is_eof()) {
        char c = peek();
        if      (char_is(c, char_space))     advance();
        else if (char_is(c, char_newline)) { lexer_newline(); advance(); }
        else if (char_is(c, char_slash))   { if(!skip_comments()) break; }
        else break;
    }
}

static inline string lex_string() {
    return (string) {
        .str = sLexer->start,
        .length = (p64)(sLexer->current - sLexer->start),
    };
}
static Token make_token(Token_Type t) {
    return (Token) {
        .type = t,
        .name = lex_string(),
        .line = sLexer->line,
        .col  = sLexer->col,
    };
}

static Token lexer_scan_ident() {
    while(!is_eof() && is_alnum()) advance();

    string temp = {
        .length = (s64)(sLexer->current - sLexer->start),
        .str = sLexer->start,
    };

    for(s64 i = 0; i < keyword_scan_count; i++) {
        Token_info* kw = keyword_scan_table[i];
        if(is_string_eq(&temp, &kw->name)) {
           return make_token(kw->type);   
        }
    }
    return make_token(TOKEN_IDENT);

}

static Token lexer_scan_number() {
    while(!is_eof() && char_is(peek(), char_digit)) advance();
    if(advance() == char_dot) {
        while(!is_eof() && char_is(peek(), char_digit)) advance();
        return make_token(TOKEN_FLOAT_LIT);
    }
    return make_token(TOKEN_INT_LIT);
}

static Token lexer_scan_string() {
    advance(); // opening "
    while(!is_eof()) {
        char c = peek();
        if(char_is(c, char_newline)) return make_token(TOKEN_ERROR);
        if(char_is(c, char_escape)) { advance(); advance(); continue; }
        if(char_is(c, char_string)) break; // closing "
        advance();
    } 
    if(is_eof()) return make_token(TOKEN_ERROR);
    advance(); // " consuming
    return make_token(TOKEN_STRING_LIT);
}
static Token lexer_scan_char() {
    advance(); // opening '
    if(is_eof() || char_is(peek(), char_newline))
        return make_token(TOKEN_ERROR);
        
    while(!is_eof()) {
        char c = peek();
        if(char_is(c, char_newline)) return make_token(TOKEN_ERROR);
       if(char_is(c, char_escape)) { advance(); advance(); continue; }
       if(char_is(c, char_tick)) break;// closing '
       advance(); 
    }
    if(is_eof()) return make_token(TOKEN_ERROR);    
    
    advance(); // consuming '
    return make_token(TOKEN_CHAR_LIT);    
}
static Token lexer_scan_symbol() {

    char c1 = advance(); char c2 = peek();

    for(i32 i = 0; i < double_char_table_count; i++) {
        const double_char* dc = &Double_char_Table[i];
        if(c1 == dc->a && c2 == dc->b) {
            advance();
            return make_token(dc->compound);
        }
    }
    


    // char c = advance();
    // // double char table
    // for(i32 i = 0; i < double_char_table_count; i++) {
    //     const double_char* dc = &Double_char_Table[i];
    //     if(dc->a == c){
    //         if(peek() == dc->b) {
    //             advance();
    //             return make_token(dc->compound);
    //         }
    //         return make_token(dc->single);
    //     }
    // }

    // single char table
    
    Token_Type type = Char_table[(u8)c1];
    if(type) return make_token(type);
    return make_token(TOKEN_ERROR);
}

Token lexer_next() {
    skip_whitespaces();
    sLexer->start = sLexer->current;
    char c = peek();

    if(is_eof()) return make_token(TOKEN_EOF);
    if(char_is(c, char_alpha))  return lexer_scan_ident();
    if(char_is(c, char_digit))  return lexer_scan_number();
    if(char_is(c, char_tick))   return lexer_scan_char();
    if(char_is(c, char_string)) return lexer_scan_string();
    if(char_is(c, char_symbol)) return lexer_scan_symbol();

    return make_token(TOKEN_ERROR);
}

// =========================================================
// ======================== COMMENT ========================
// =========================================================

// =========================================================

null lexer_init(string source_file) {

    sLexer = (Lexer*)malloc(sizeof(Lexer));
    sToken = list_alloc(Token);
    
    sLexer->source  = source_file;
    sLexer->start   = source_file.str;
    sLexer->current = source_file.str;

    sLexer->_end = source_file.str + source_file.length;

    sLexer->line = 1;
    sLexer->col  = 1;
}

null Lexer_free() {
    if(sLexer) {
        free(sLexer);
        sLexer = nullptr;
    }
    list_destroy(sToken);
}

null lex_prnt() {
    
    for(;; sLexer->current++) {
        if(is_eof()) {printf("eof"endl); break;}
        printf("%c"endl, *sLexer->current);
    }
}



null lexer_tokenize() {
    /**
     * scan token 
     * push token
     * break at eof || error
     */
    while(true) { 

        Token token = lexer_next();
        list_push(sToken, token);
        if(token.type == TOKEN_EOF || token.type == TOKEN_ERROR) break;
    }
}

null print_token(Token t) {
    printf(
        "Type: %d" endl  
        "Name: %.*s" endl  
        "line: %d" endl 
        "col : %d" endl, 
        t.type, 
        t.name.length, 
        t.name.str, 
        t.line, 
        t.col
    );
}

null lexer_token_log() {
    printf("Tokens Size: %d"endl, sToken->size);
}

null lexer_print_tokens() {
    
    printf("  %-3s | %-25s | %s" endl, "line", "type", "name");
    printf("---------------------------------------------------"endl);
    for(i32 i = 0; i < sToken->size; i++) {
        
        printf("   %-3d" " | " "%-25.*s" " | " fmt_str  endl,
            sToken->buffer[i].line,
            token_name[sToken->buffer[i].type].length,
            token_name[sToken->buffer[i].type].str,
            sToken->buffer[i].name.length, 
            sToken->buffer[i].name.str
        );   
    }
    
}