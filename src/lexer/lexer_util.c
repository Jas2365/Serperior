
#include <lexer/lexer_util.h>
#include <lexer/lexer_defs.h>

Token_info Token_Table[] = {
    
    #define TOKEN_LITERAL(t_name, t_lex) [t_name] = { .name = { .str = t_lex, .length = sizeof(t_lex) -1}, .type = t_name},
    #define TOKEN_KEYWORD(t_name, t_lex) [t_name] = { .name = { .str = t_lex, .length = sizeof(t_lex) -1}, .type = t_name},
    #define TOKEN_SYMBOL(t_name, t_lex)  [t_name] = { .name = { .str = t_lex, .length = sizeof(t_lex) -1}, .type = t_name},
    #define TOKEN_SPECIAL(t_name, t_lex) [t_name] = { .name = { .str = t_lex, .length = sizeof(t_lex) -1}, .type = t_name},

    #include <token_defs.h>
};

s64 Token_Table_count = sizeof(Token_Table) / sizeof(Token_Table[0]);

Token_info* keyword_scan_table[] = {
    #define TOKEN_KEYWORD(t_name, t_lex) &Token_Table[t_name],
    
    #include <token_defs.h>
};
s64 keyword_scan_count = sizeof(keyword_scan_table) / sizeof(keyword_scan_table[0]);

Token_Type Char_table[] = {
    
    [ char_parenl    ] = TOKEN_PAREN_L,
    [ char_parenr    ] = TOKEN_PAREN_R,
    [ char_bracesl   ] = TOKEN_BRACES_L,
    [ char_bracesr   ] = TOKEN_BRACES_R,
    [ char_bracketl  ] = TOKEN_BRACKET_L,
    [ char_bracketr  ] = TOKEN_BRACKET_R,
    [ char_dot       ] = TOKEN_DOT,
    [ char_comma     ] = TOKEN_COMMA,
    [ char_colon     ] = TOKEN_COLON,
    [ char_semicolon ] = TOKEN_SEMICOLON,
    [ char_plus      ] = TOKEN_PLUS,
    [ char_minus     ] = TOKEN_MINUS,
    [ char_star      ] = TOKEN_STAR,
    [ char_slash     ] = TOKEN_SLASH,
    [ char_percent   ] = TOKEN_PERCENT,
    [ char_tilde     ] = TOKEN_BIT_TILDE,
    [ char_caret     ] = TOKEN_BIT_CARET,
};
s64 char_table_count = sizeof(Char_table) / sizeof(Char_table[0]);

double_char Double_char_Table[] = {
    { .a = char_eq   , .b = char_eq   , .single = TOKEN_ASSIGN,   .compound = TOKEN_EQ          },
    { .a = char_bang , .b = char_eq   , .single = TOKEN_BANG,     .compound = TOKEN_NEQ         },
    { .a = char_lt   , .b = char_eq   , .single = TOKEN_LT,       .compound = TOKEN_LTE         },
    { .a = char_gt   , .b = char_eq   , .single = TOKEN_GT,       .compound = TOKEN_GTE         },
    { .a = char_lt   , .b = char_lt   , .single = TOKEN_LT,       .compound = TOKEN_BIT_SHIFT_L },
    { .a = char_gt   , .b = char_gt   , .single = TOKEN_GT,       .compound = TOKEN_BIT_SHIFT_R },
    { .a = char_amp  , .b = char_amp  , .single = TOKEN_BIT_AMP,  .compound = TOKEN_AND         },
    { .a = char_pipe , .b = char_pipe , .single = TOKEN_BIT_PIPE, .compound = TOKEN_OR          },
};

s64 double_char_table_count = sizeof(Double_char_Table) / sizeof(Double_char_Table[0]);

u16 char_class[256] = {
    // whitespaces
    [ char_sp  ] = char_space,
    [ char_tab ] = char_space,
    [ char_cr  ] = char_space,
    [ char_nl  ] = char_newline,
    [ char_sl  ] = char_slash  | char_symbol,
    [ char_es  ] = char_escape | char_symbol,
    
    // letters
    [ char_a ] = char_alpha, [ char_b ] = char_alpha, [ char_c ] = char_alpha, [ char_d ] = char_alpha,
    [ char_e ] = char_alpha, [ char_f ] = char_alpha, [ char_g ] = char_alpha, [ char_h ] = char_alpha,
    [ char_i ] = char_alpha, [ char_j ] = char_alpha, [ char_k ] = char_alpha, [ char_l ] = char_alpha,
    [ char_m ] = char_alpha, [ char_n ] = char_alpha, [ char_o ] = char_alpha, [ char_p ] = char_alpha,
    [ char_q ] = char_alpha, [ char_r ] = char_alpha, [ char_s ] = char_alpha, [ char_t ] = char_alpha,
    [ char_u ] = char_alpha, [ char_v ] = char_alpha, [ char_w ] = char_alpha, [ char_x ] = char_alpha,
    [ char_y ] = char_alpha, [ char_z ] = char_alpha,
    
    [ char_A ] = char_alpha, [ char_B ] = char_alpha, [ char_C ] = char_alpha, [ char_D ] = char_alpha,
    [ char_E ] = char_alpha, [ char_F ] = char_alpha, [ char_G ] = char_alpha, [ char_H ] = char_alpha,
    [ char_I ] = char_alpha, [ char_J ] = char_alpha, [ char_K ] = char_alpha, [ char_L ] = char_alpha,
    [ char_M ] = char_alpha, [ char_N ] = char_alpha, [ char_O ] = char_alpha, [ char_P ] = char_alpha,
    [ char_Q ] = char_alpha, [ char_R ] = char_alpha, [ char_S ] = char_alpha, [ char_T ] = char_alpha,
    [ char_U ] = char_alpha, [ char_V ] = char_alpha, [ char_W ] = char_alpha, [ char_X ] = char_alpha,
    [ char_Y ] = char_alpha, [ char_Z ] = char_alpha,
    
    [ char_us ] = char_alpha,
    
    // digit
    [ char_0 ] = char_digit, 
    [ char_1 ] = char_digit, 
    [ char_2 ] = char_digit, 
    [ char_3 ] = char_digit, 
    [ char_4 ] = char_digit,
    [ char_5 ] = char_digit, 
    [ char_6 ] = char_digit, 
    [ char_7 ] = char_digit, 
    [ char_8 ] = char_digit, 
    [ char_9 ] = char_digit,
    
    // symbols
    [ char_parenl    ] = char_symbol, 
    [ char_parenr    ] = char_symbol,
    [ char_bracesl   ] = char_symbol, 
    [ char_bracesr   ] = char_symbol,
    [ char_bracketl  ] = char_symbol, 
    [ char_bracketr  ] = char_symbol,
    [ char_dot       ] = char_symbol, 
    [ char_comma     ] = char_symbol,
    [ char_colon     ] = char_symbol, 
    [ char_semicolon ] = char_symbol,
    [ char_plus      ] = char_symbol, 
    [ char_minus     ] = char_symbol,
    [ char_star      ] = char_symbol, 
    [ char_percent   ] = char_symbol,
    [ char_tilde     ] = char_symbol, 
    [ char_caret     ] = char_symbol,

    [ char_eq   ] = char_symbol,
    [ char_bang ] = char_symbol,
    [ char_lt   ] = char_symbol,
    [ char_gt   ] = char_symbol,
    [ char_amp  ] = char_symbol,
    [ char_pipe ] = char_symbol,
    
    // character
    [ char_quote  ] = char_tick,
    [ char_dquote ] = char_string,
};


string token_name[] = {
    #define TOKEN_LITERAL(t_name, t_lex) [t_name] = { .str = #t_name, .length = sizeof(#t_name) -1 },
    #define TOKEN_KEYWORD(t_name, t_lex) [t_name] = { .str = #t_name, .length = sizeof(#t_name) -1 },
    #define TOKEN_SYMBOL(t_name, t_lex) [t_name] = { .str = #t_name, .length = sizeof(#t_name) -1 },
    #define TOKEN_SPECIAL(t_name, t_lex) [t_name] = { .str = #t_name, .length = sizeof(#t_name) -1 },

    #include <token_defs.h>
};

s64 token_name_count = sizeof(token_name) / sizeof(token_name[0]);

null lexer_util_info() {
     printf(
        "Lexer Util Info"                   endl
        "token table count          : %d"   endl 
        "token name count           : %d"   endl 
        "keywords count             : %d"   endl 
        "char_table count           : %d"   endl
        "double char table count    : %d"   endl,
        Token_Table_count,
        token_name_count,
        keyword_scan_count,
        char_table_count,
        double_char_table_count
    );
}
