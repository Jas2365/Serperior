
#include <lexer/lexer_util.h>
#include <lexer/lexer_defs.h>

Token_info Token_Table[] = {

    [ TOKEN_IDENT   ] = { .name = { .str = "ident",   .length = sizeof("ident")   -1 }, .type = TOKEN_IDENT   },
    
    [ TOKEN_BOOL_LIT   ] = { .name = { .str = "bool_lit",   .length = sizeof("bool_lit")   -1 }, .type = TOKEN_BOOL_LIT   },
    [ TOKEN_CHAR_LIT   ] = { .name = { .str = "char_lit",   .length = sizeof("char_lit")   -1 }, .type = TOKEN_CHAR_LIT   },
    [ TOKEN_INT_LIT    ] = { .name = { .str = "int_lit",    .length = sizeof("int_lit")    -1 }, .type = TOKEN_INT_LIT    },
    [ TOKEN_FLOAT_LIT  ] = { .name = { .str = "float_lit",  .length = sizeof("float_lit")  -1 }, .type = TOKEN_FLOAT_LIT  },
    [ TOKEN_STRING_LIT ] = { .name = { .str = "string_lit", .length = sizeof("string_lit") -1 }, .type = TOKEN_STRING_LIT },
    
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
    

    // symbols
    [ TOKEN_PAREN_L   ] = { .name = { .str = "(", .length = 1 }, .type = TOKEN_PAREN_L   },
    [ TOKEN_PAREN_R   ] = { .name = { .str = ")", .length = 1 }, .type = TOKEN_PAREN_R   },
    [ TOKEN_BRACKET_L ] = { .name = { .str = "[", .length = 1 }, .type = TOKEN_BRACKET_L },
    [ TOKEN_BRACKET_R ] = { .name = { .str = "]", .length = 1 }, .type = TOKEN_BRACKET_R },
    [ TOKEN_BRACES_L  ] = { .name = { .str = "{", .length = 1 }, .type = TOKEN_BRACES_L  },
    [ TOKEN_BRACES_R  ] = { .name = { .str = "}", .length = 1 }, .type = TOKEN_BRACES_R  },

    [ TOKEN_DOT       ] = { .name = { .str = ".", .length = 1 }, .type = TOKEN_DOT       },
    [ TOKEN_COMMA     ] = { .name = { .str = ",", .length = 1 }, .type = TOKEN_COMMA     },
    [ TOKEN_COLON     ] = { .name = { .str = ":", .length = 1 }, .type = TOKEN_COLON     },
    [ TOKEN_SEMICOLON ] = { .name = { .str = ";", .length = 1 }, .type = TOKEN_SEMICOLON },
    [ TOKEN_ASSIGN    ] = { .name = { .str = "=", .length = 1 }, .type = TOKEN_ASSIGN    },
    
    [ TOKEN_PLUS      ] = { .name = { .str = "+", .length = 1 }, .type = TOKEN_PLUS      },
    [ TOKEN_MINUS     ] = { .name = { .str = "-", .length = 1 }, .type = TOKEN_MINUS     },
    [ TOKEN_STAR      ] = { .name = { .str = "*", .length = 1 }, .type = TOKEN_STAR      },
    [ TOKEN_SLASH     ] = { .name = { .str = "/", .length = 1 }, .type = TOKEN_SLASH     },
    [ TOKEN_PERCENT   ] = { .name = { .str = "%", .length = 1 }, .type = TOKEN_PERCENT   },

    [ TOKEN_EQ        ] = { .name = { .str = "==", .length = 2 }, .type = TOKEN_EQ        },
    [ TOKEN_NEQ       ] = { .name = { .str = "!=", .length = 2 }, .type = TOKEN_NEQ       },
    [ TOKEN_LT        ] = { .name = { .str = "<",  .length = 1 }, .type = TOKEN_LT        },
    [ TOKEN_GT        ] = { .name = { .str = ">",  .length = 1 }, .type = TOKEN_GT        },
    [ TOKEN_LTE       ] = { .name = { .str = "<=", .length = 2 }, .type = TOKEN_LTE       },
    [ TOKEN_GTE       ] = { .name = { .str = ">=", .length = 2 }, .type = TOKEN_GTE       },

    [ TOKEN_AND       ] = { .name = { .str = "&&", .length = 2 }, .type = TOKEN_AND       },
    [ TOKEN_OR        ] = { .name = { .str = "||", .length = 2 }, .type = TOKEN_OR        },
    [ TOKEN_BANG      ] = { .name = { .str = "!",  .length = 1 }, .type = TOKEN_BANG      },
    
    [ TOKEN_BIT_AMP     ] = { .name = { .str = "&",  .length = 1 }, .type = TOKEN_BIT_AMP     },
    [ TOKEN_BIT_PIPE    ] = { .name = { .str = "|",  .length = 1 }, .type = TOKEN_BIT_PIPE    },
    [ TOKEN_BIT_TILDE   ] = { .name = { .str = "~",  .length = 1 }, .type = TOKEN_BIT_TILDE   },
    [ TOKEN_BIT_CARET   ] = { .name = { .str = "^",  .length = 1 }, .type = TOKEN_BIT_CARET   },
    [ TOKEN_BIT_SHIFT_L ] = { .name = { .str = "<<", .length = 2 }, .type = TOKEN_BIT_SHIFT_L },
    [ TOKEN_BIT_SHIFT_R ] = { .name = { .str = ">>", .length = 2 }, .type = TOKEN_BIT_SHIFT_R },

    [ TOKEN_EOF   ] = { .name = { .str = "eof",   .length = sizeof("eof")   -1 }, .type = TOKEN_EOF   },
    [ TOKEN_ERROR ] = { .name = { .str = "error", .length = sizeof("error") -1 }, .type = TOKEN_ERROR },

};

s64 Token_Table_count = sizeof(Token_Table) / sizeof(Token_Table[0]);

Token_info* keyword_scan_table[] = {

    &Token_Table[ TOKEN_MODULE   ],
    &Token_Table[ TOKEN_IMPORT   ],
    &Token_Table[ TOKEN_FN       ],
    &Token_Table[ TOKEN_RETURN   ],
    &Token_Table[ TOKEN_INTERNAL ],
    &Token_Table[ TOKEN_PERSIST  ],
    &Token_Table[ TOKEN_STRUCT   ],
    &Token_Table[ TOKEN_UNION    ],
    &Token_Table[ TOKEN_ENUM     ],
    &Token_Table[ TOKEN_WHILE    ],
    &Token_Table[ TOKEN_FOR      ],
    &Token_Table[ TOKEN_SWITCH   ],
    &Token_Table[ TOKEN_IF       ],
    &Token_Table[ TOKEN_ELSE     ],
    &Token_Table[ TOKEN_BREAK    ],
    &Token_Table[ TOKEN_CONTINUE ],
    &Token_Table[ TOKEN_TYPEOF   ],
    &Token_Table[ TOKEN_TYPE     ],
    &Token_Table[ TOKEN_TRUE     ],
    &Token_Table[ TOKEN_FALSE    ],
    &Token_Table[ TOKEN_CONST    ],
    &Token_Table[ TOKEN_NULL     ],
    &Token_Table[ TOKEN_I8       ],
    &Token_Table[ TOKEN_I16      ],
    &Token_Table[ TOKEN_I32      ],
    &Token_Table[ TOKEN_I64      ],
    &Token_Table[ TOKEN_U8       ],
    &Token_Table[ TOKEN_U16      ],
    &Token_Table[ TOKEN_U32      ],
    &Token_Table[ TOKEN_U64      ],
    &Token_Table[ TOKEN_F32      ],
    &Token_Table[ TOKEN_F64      ],
    &Token_Table[ TOKEN_BOOL     ],
    &Token_Table[ TOKEN_CHAR     ],
    &Token_Table[ TOKEN_STRING   ],
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

u8 char_class[256] = {
    // whitespaces
    [ char_sp  ] = char_space,
    [ char_tab ] = char_space,
    [ char_cr  ] = char_space,
    [ char_nl  ] = char_newline,
    [ char_sl  ] = char_slash | char_symbol,
    
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
    [ TOKEN_IDENT       ] =  { .str = "TOKEN_IDENT",        .length = sizeof("TOKEN_IDENT")         -1 },
    [ TOKEN_BOOL_LIT    ] =  { .str = "TOKEN_BOOL_LIT",     .length = sizeof("TOKEN_BOOL_LIT")      -1 },
    [ TOKEN_CHAR_LIT    ] =  { .str = "TOKEN_CHAR_LIT",     .length = sizeof("TOKEN_CHAR_LIT")      -1 },
    [ TOKEN_INT_LIT     ] =  { .str = "TOKEN_INT_LIT",      .length = sizeof("TOKEN_INT_LIT")       -1 },
    [ TOKEN_FLOAT_LIT   ] =  { .str = "TOKEN_FLOAT_LIT",    .length = sizeof("TOKEN_FLOAT_LIT")     -1 },
    [ TOKEN_STRING_LIT  ] =  { .str = "TOKEN_STRING_LIT",   .length = sizeof("TOKEN_STRING_LIT")    -1 },
    [ TOKEN_MODULE      ] =  { .str = "TOKEN_MODULE",       .length = sizeof("TOKEN_MODULE")        -1 },
    [ TOKEN_IMPORT      ] =  { .str = "TOKEN_IMPORT",       .length = sizeof("TOKEN_IMPORT")        -1 },
    [ TOKEN_FN          ] =  { .str = "TOKEN_FN",           .length = sizeof("TOKEN_FN")            -1 },
    [ TOKEN_RETURN      ] =  { .str = "TOKEN_RETURN",       .length = sizeof("TOKEN_RETURN")        -1 },
    [ TOKEN_INTERNAL    ] =  { .str = "TOKEN_INTERNAL",     .length = sizeof("TOKEN_INTERNAL")      -1 },
    [ TOKEN_PERSIST     ] =  { .str = "TOKEN_PERSIST",      .length = sizeof("TOKEN_PERSIST")       -1 },
    [ TOKEN_STRUCT      ] =  { .str = "TOKEN_STRUCT",       .length = sizeof("TOKEN_STRUCT")        -1 },
    [ TOKEN_UNION       ] =  { .str = "TOKEN_UNION",        .length = sizeof("TOKEN_UNION")         -1 },
    [ TOKEN_ENUM        ] =  { .str = "TOKEN_ENUM",         .length = sizeof("TOKEN_ENUM")          -1 },
    [ TOKEN_WHILE       ] =  { .str = "TOKEN_WHILE",        .length = sizeof("TOKEN_WHILE")         -1 },
    [ TOKEN_FOR         ] =  { .str = "TOKEN_FOR",          .length = sizeof("TOKEN_FOR")           -1 },
    [ TOKEN_SWITCH      ] =  { .str = "TOKEN_SWITCH",       .length = sizeof("TOKEN_SWITCH")        -1 },
    [ TOKEN_IF          ] =  { .str = "TOKEN_IF",           .length = sizeof("TOKEN_IF")            -1 },
    [ TOKEN_ELSE        ] =  { .str = "TOKEN_ELSE",         .length = sizeof("TOKEN_ELSE")          -1 },
    [ TOKEN_BREAK       ] =  { .str = "TOKEN_BREAK",        .length = sizeof("TOKEN_BREAK")         -1 },
    [ TOKEN_CONTINUE    ] =  { .str = "TOKEN_CONTINUE",     .length = sizeof("TOKEN_CONTINUE")      -1 },
    [ TOKEN_TYPEOF      ] =  { .str = "TOKEN_TYPEOF",       .length = sizeof("TOKEN_TYPEOF")        -1 },
    [ TOKEN_TYPE        ] =  { .str = "TOKEN_TYPE",         .length = sizeof("TOKEN_TYPE")          -1 },
    [ TOKEN_TRUE        ] =  { .str = "TOKEN_TRUE",         .length = sizeof("TOKEN_TRUE")          -1 },
    [ TOKEN_FALSE       ] =  { .str = "TOKEN_FALSE",        .length = sizeof("TOKEN_FALSE")         -1 },
    [ TOKEN_CONST       ] =  { .str = "TOKEN_CONST",        .length = sizeof("TOKEN_CONST")         -1 },
    [ TOKEN_NULL        ] =  { .str = "TOKEN_NULL",         .length = sizeof("TOKEN_NULL")          -1 },
    [ TOKEN_I8          ] =  { .str = "TOKEN_I8",           .length = sizeof("TOKEN_I8")            -1 },
    [ TOKEN_I16         ] =  { .str = "TOKEN_I16",          .length = sizeof("TOKEN_I16")           -1 },
    [ TOKEN_I32         ] =  { .str = "TOKEN_I32",          .length = sizeof("TOKEN_I32")           -1 },
    [ TOKEN_I64         ] =  { .str = "TOKEN_I64",          .length = sizeof("TOKEN_I64")           -1 },
    [ TOKEN_U8          ] =  { .str = "TOKEN_U8",           .length = sizeof("TOKEN_U8")            -1 },
    [ TOKEN_U16         ] =  { .str = "TOKEN_U16",          .length = sizeof("TOKEN_U16")           -1 },
    [ TOKEN_U32         ] =  { .str = "TOKEN_U32",          .length = sizeof("TOKEN_U32")           -1 },
    [ TOKEN_U64         ] =  { .str = "TOKEN_U64",          .length = sizeof("TOKEN_U64")           -1 },
    [ TOKEN_F32         ] =  { .str = "TOKEN_F32",          .length = sizeof("TOKEN_F32")           -1 },
    [ TOKEN_F64         ] =  { .str = "TOKEN_F64",          .length = sizeof("TOKEN_F64")           -1 },
    [ TOKEN_BOOL        ] =  { .str = "TOKEN_BOOL",         .length = sizeof("TOKEN_BOOL")          -1 },
    [ TOKEN_CHAR        ] =  { .str = "TOKEN_CHAR",         .length = sizeof("TOKEN_CHAR")          -1 },
    [ TOKEN_STRING      ] =  { .str = "TOKEN_STRING",       .length = sizeof("TOKEN_STRING")        -1 },
    [ TOKEN_PAREN_L     ] =  { .str = "TOKEN_PAREN_L",      .length = sizeof("TOKEN_PAREN_L")       -1 },
    [ TOKEN_PAREN_R     ] =  { .str = "TOKEN_PAREN_R",      .length = sizeof("TOKEN_PAREN_R")       -1 },
    [ TOKEN_BRACKET_L   ] =  { .str = "TOKEN_BRACKET_L",    .length = sizeof("TOKEN_BRACKET_L")     -1 },
    [ TOKEN_BRACKET_R   ] =  { .str = "TOKEN_BRACKET_R",    .length = sizeof("TOKEN_BRACKET_R")     -1 },
    [ TOKEN_BRACES_L    ] =  { .str = "TOKEN_BRACES_L",     .length = sizeof("TOKEN_BRACES_L")      -1 },
    [ TOKEN_BRACES_R    ] =  { .str = "TOKEN_BRACES_R",     .length = sizeof("TOKEN_BRACES_R")      -1 },
    [ TOKEN_DOT         ] =  { .str = "TOKEN_DOT",          .length = sizeof("TOKEN_DOT")           -1 },
    [ TOKEN_COMMA       ] =  { .str = "TOKEN_COMMA",        .length = sizeof("TOKEN_COMMA")         -1 },
    [ TOKEN_COLON       ] =  { .str = "TOKEN_COLON",        .length = sizeof("TOKEN_COLON")         -1 },
    [ TOKEN_SEMICOLON   ] =  { .str = "TOKEN_SEMICOLON",    .length = sizeof("TOKEN_SEMICOLON")     -1 },
    [ TOKEN_ASSIGN      ] =  { .str = "TOKEN_ASSIGN",       .length = sizeof("TOKEN_ASSIGN")        -1 },
    [ TOKEN_PLUS        ] =  { .str = "TOKEN_PLUS",         .length = sizeof("TOKEN_PLUS")          -1 },
    [ TOKEN_MINUS       ] =  { .str = "TOKEN_MINUS",        .length = sizeof("TOKEN_MINUS")         -1 },
    [ TOKEN_STAR        ] =  { .str = "TOKEN_STAR",         .length = sizeof("TOKEN_STAR")          -1 },
    [ TOKEN_SLASH       ] =  { .str = "TOKEN_SLASH",        .length = sizeof("TOKEN_SLASH")         -1 },
    [ TOKEN_PERCENT     ] =  { .str = "TOKEN_PERCENT",      .length = sizeof("TOKEN_PERCENT")       -1 },
    [ TOKEN_EQ          ] =  { .str = "TOKEN_EQ",           .length = sizeof("TOKEN_EQ")            -1 },
    [ TOKEN_NEQ         ] =  { .str = "TOKEN_NEQ",          .length = sizeof("TOKEN_NEQ")           -1 },
    [ TOKEN_LT          ] =  { .str = "TOKEN_LT",           .length = sizeof("TOKEN_LT")            -1 },
    [ TOKEN_GT          ] =  { .str = "TOKEN_GT",           .length = sizeof("TOKEN_GT")            -1 },
    [ TOKEN_LTE         ] =  { .str = "TOKEN_LTE",          .length = sizeof("TOKEN_LTE")           -1 },
    [ TOKEN_GTE         ] =  { .str = "TOKEN_GTE",          .length = sizeof("TOKEN_GTE")           -1 },
    [ TOKEN_AND         ] =  { .str = "TOKEN_AND",          .length = sizeof("TOKEN_AND")           -1 },
    [ TOKEN_OR          ] =  { .str = "TOKEN_OR",           .length = sizeof("TOKEN_OR")            -1 },
    [ TOKEN_BANG        ] =  { .str = "TOKEN_BANG",         .length = sizeof("TOKEN_BANG")          -1 },
    [ TOKEN_BIT_AMP     ] =  { .str = "TOKEN_BIT_AMP",      .length = sizeof("TOKEN_BIT_AMP")       -1 },
    [ TOKEN_BIT_PIPE    ] =  { .str = "TOKEN_BIT_PIPE",     .length = sizeof("TOKEN_BIT_PIPE")      -1 },
    [ TOKEN_BIT_TILDE   ] =  { .str = "TOKEN_BIT_TILDE",    .length = sizeof("TOKEN_BIT_TILDE")     -1 },
    [ TOKEN_BIT_CARET   ] =  { .str = "TOKEN_BIT_CARET",    .length = sizeof("TOKEN_BIT_CARET")     -1 },
    [ TOKEN_BIT_SHIFT_L ] =  { .str = "TOKEN_BIT_SHIFT_L",  .length = sizeof("TOKEN_BIT_SHIFT_L")   -1 },
    [ TOKEN_BIT_SHIFT_R ] =  { .str = "TOKEN_BIT_SHIFT_R",  .length = sizeof("TOKEN_BIT_SHIFT_R")   -1 },
    [ TOKEN_EOF         ] =  { .str = "TOKEN_EOF",          .length = sizeof("TOKEN_EOF")           -1 },
    [ TOKEN_ERROR       ] =  { .str = "TOKEN_ERROR",        .length = sizeof("TOKEN_ERROR")         -1 },

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
