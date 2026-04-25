#include <lexer/lexer.h>
#include <ptr/ptr.h>
#include <lists/my_list.h>
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
static inline b8 peek() {
    return *sLexer->current;
}
static inline b8 peek_next() {
    if(is_eof) return 0;
    else return *(sLexer->current + 1);
}
static inline i8 advance() {
    i8 c = *sLexer->current++;
    sLexer->col++;
    return c;
}

// =========================================================
// ======================== COMMENT ========================= 
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

    Token t = {
        .name = { 
            .length = 5, 
            .str = "hello" 
        }
    };
    Token t2 = {
        .name = {
            .length = 5, 
            .str = "world" 
        }
    };

    list_push(sToken, t);
    list_push(sToken, t2);


}


null lexer_print_tokens() {
    
    for(i32 i = 0; i < sToken->size; i++) {
        
        printf("token %.*s"endl, 
            sToken->buffer[i].name.length, 
            sToken->buffer[i].name.str
        );   
    }
    
}