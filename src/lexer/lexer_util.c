
#include <lexer/lexer_util.h>
#include <lexer/lexer_defs.h>

Token_info Keywords[] = {

    [ TOKEN_MODULE   ] = { .name = { .str = "module",   .length = sizeof("module")   -1 }, .type = TOKEN_MODULE   },
    [ TOKEN_IMPORT   ] = { .name = { .str = "import",   .length = sizeof("import")   -1 }, .type = TOKEN_IMPORT   },
    
    [ TOKEN_FN       ] = { .name = { .str = "fn",       .length = sizeof("fn")       -1 }, .type = TOKEN_FN       },
    [ TOKEN_RETURN   ] = { .name = { .str = "return",   .length = sizeof("return")   -1 }, .type = TOKEN_RETURN   },
    
    [ TOKEN_INTERNAL ] = { .name = { .str = "internal", .length = sizeof("internal") -1 }, .type = TOKEN_INTERNAL },
    [ TOKEN_PERSIST  ] = { .name = { .str = "persist",  .length = sizeof("persist")  -1 }, .type = TOKEN_PERSIST  },
    
    [ TOKEN_STRUCT   ] = { .name = { .str = "struct",   .length = sizeof("struct")   -1 }, .type = TOKEN_STRUCT   },
    [ TOKEN_UNION    ] = { .name = { .str = "union",    .length = sizeof("union")    -1 }, .type = TOKEN_UNION    },
    [ TOKEN_ENUM     ] = { .name = { .str = "enum",     .length = sizeof("enum")     -1 }, .type = TOKEN_ENUM     },
    
    [ TOKEN_WHILE    ] = { .name = { .str = "while",    .length = sizeof("while")    -1 }, .type = TOKEN_WHILE    },
    [ TOKEN_FOR      ] = { .name = { .str = "for",      .length = sizeof("for")      -1 }, .type = TOKEN_FOR      },
    [ TOKEN_SWITCH   ] = { .name = { .str = "switch",   .length = sizeof("switch")   -1 }, .type = TOKEN_SWITCH   },
    [ TOKEN_IF       ] = { .name = { .str = "if",       .length = sizeof("if")       -1 }, .type = TOKEN_IF       },
    [ TOKEN_ELSE     ] = { .name = { .str = "else",     .length = sizeof("else")     -1 }, .type = TOKEN_ELSE     },
    
    [ TOKEN_BREAK    ] = { .name = { .str = "break",    .length = sizeof("break")    -1 }, .type = TOKEN_BREAK    },
    [ TOKEN_CONTINUE ] = { .name = { .str = "continue", .length = sizeof("continue") -1 }, .type = TOKEN_CONTINUE },
    
    [ TOKEN_TYPEOF   ] = { .name = { .str = "typeof",   .length = sizeof("typeof")   -1 }, .type = TOKEN_TYPEOF   },
    [ TOKEN_TYPE     ] = { .name = { .str = "type",     .length = sizeof("type")     -1 }, .type = TOKEN_TYPE     },
    
    [ TOKEN_TRUE     ] = { .name = { .str = "true",     .length = sizeof("true")     -1 }, .type = TOKEN_TRUE     },
    [ TOKEN_FALSE    ] = { .name = { .str = "false",    .length = sizeof("false")    -1 }, .type = TOKEN_FALSE    },
    
    [ TOKEN_CONST    ] = { .name = { .str = "const",    .length = sizeof("const")    -1 }, .type = TOKEN_CONST    },
    
    [ TOKEN_NULL     ] = { .name = { .str = "null",     .length = sizeof("null")     -1 }, .type = TOKEN_NULL     },
    
    [ TOKEN_I8       ] = { .name = { .str = "i8",       .length = sizeof("i8")       -1 }, .type = TOKEN_I8       },
    [ TOKEN_I16      ] = { .name = { .str = "i16",      .length = sizeof("i16")      -1 }, .type = TOKEN_I16      },
    [ TOKEN_I32      ] = { .name = { .str = "i32",      .length = sizeof("i32")      -1 }, .type = TOKEN_I32      },
    [ TOKEN_I64      ] = { .name = { .str = "i64",      .length = sizeof("i64")      -1 }, .type = TOKEN_I64      },

    [ TOKEN_U8       ] = { .name = { .str = "u8",       .length = sizeof("u8")       -1 }, .type = TOKEN_U8       },
    [ TOKEN_U16      ] = { .name = { .str = "u16",      .length = sizeof("u16")      -1 }, .type = TOKEN_U16      },
    [ TOKEN_U32      ] = { .name = { .str = "u32",      .length = sizeof("u32")      -1 }, .type = TOKEN_U32      },
    [ TOKEN_U64      ] = { .name = { .str = "u64",      .length = sizeof("u64")      -1 }, .type = TOKEN_U64      },
    
    [ TOKEN_F32      ] = { .name = { .str = "f32",      .length = sizeof("f32")      -1 }, .type = TOKEN_F32      },
    [ TOKEN_F64      ] = { .name = { .str = "f64",      .length = sizeof("f64")      -1 }, .type = TOKEN_F64      },
    
    [ TOKEN_BOOL     ] = { .name = { .str = "bool",     .length = sizeof("bool")     -1 }, .type = TOKEN_BOOL     },
    [ TOKEN_CHAR     ] = { .name = { .str = "char",     .length = sizeof("char")     -1 }, .type = TOKEN_CHAR     },
    [ TOKEN_STRING   ] = { .name = { .str = "string",   .length = sizeof("string")   -1 }, .type = TOKEN_STRING   },

};
s64 keyword_count = sizeof(Keywords) / sizeof(Keywords[0]);

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

u8 char_class[256] = {
    // whitespaces
    [ char_sp    ] = char_space,
    [ char_tab   ] = char_space,
    [ char_cr    ] = char_space,
    [ char_nl    ] = char_newline,
    [ char_slash ] = char_slash | char_symbol,
    
    // letters
    [ char_a ] = char_alpha | char_ident, 
    [ char_b ] = char_alpha | char_ident, 
    [ char_c ] = char_alpha | char_ident, 
    [ char_d ] = char_alpha | char_ident,
    [ char_e ] = char_alpha | char_ident, 
    [ char_f ] = char_alpha | char_ident, 
    [ char_g ] = char_alpha | char_ident, 
    [ char_h ] = char_alpha | char_ident,
    [ char_i ] = char_alpha | char_ident, 
    [ char_j ] = char_alpha | char_ident, 
    [ char_k ] = char_alpha | char_ident, 
    [ char_l ] = char_alpha | char_ident,
    [ char_m ] = char_alpha | char_ident, 
    [ char_n ] = char_alpha | char_ident, 
    [ char_o ] = char_alpha | char_ident, 
    [ char_p ] = char_alpha | char_ident,
    [ char_q ] = char_alpha | char_ident, 
    [ char_r ] = char_alpha | char_ident, 
    [ char_s ] = char_alpha | char_ident, 
    [ char_t ] = char_alpha | char_ident,
    [ char_u ] = char_alpha | char_ident, 
    [ char_v ] = char_alpha | char_ident, 
    [ char_w ] = char_alpha | char_ident, 
    [ char_x ] = char_alpha | char_ident,
    [ char_y ] = char_alpha | char_ident, 
    [ char_z ] = char_alpha | char_ident,
    
    [ char_A ] = char_alpha | char_ident, 
    [ char_B ] = char_alpha | char_ident, 
    [ char_C ] = char_alpha | char_ident, 
    [ char_D ] = char_alpha | char_ident,
    [ char_E ] = char_alpha | char_ident, 
    [ char_F ] = char_alpha | char_ident, 
    [ char_G ] = char_alpha | char_ident, 
    [ char_H ] = char_alpha | char_ident,
    [ char_I ] = char_alpha | char_ident, 
    [ char_J ] = char_alpha | char_ident, 
    [ char_K ] = char_alpha | char_ident, 
    [ char_L ] = char_alpha | char_ident,
    [ char_M ] = char_alpha | char_ident, 
    [ char_N ] = char_alpha | char_ident, 
    [ char_O ] = char_alpha | char_ident, 
    [ char_P ] = char_alpha | char_ident,
    [ char_Q ] = char_alpha | char_ident, 
    [ char_R ] = char_alpha | char_ident, 
    [ char_S ] = char_alpha | char_ident, 
    [ char_T ] = char_alpha | char_ident,
    [ char_U ] = char_alpha | char_ident, 
    [ char_V ] = char_alpha | char_ident, 
    [ char_W ] = char_alpha | char_ident, 
    [ char_X ] = char_alpha | char_ident,
    [ char_Y ] = char_alpha | char_ident, 
    [ char_Z ] = char_alpha | char_ident,
    
    [ char_us ] = char_alpha | char_ident,
    
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
    

};




null lexer_util_info() {
     printf(
        "Lexer Util Info"                   endl
        "keywords count             : %d"   endl 
        "char_table count           : %d"   endl
        "double char table count    : %d"   endl,
        keyword_count,
        char_table_count,
        double_char_table_count
    );
}
