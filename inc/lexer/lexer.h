/*
 * Copyright 2026 Jas2365
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by law or agreed to in writing, software distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
 * OR CONDITIONS OF ANY KIND, either express or implied.
 */


#include <ints.h>
#include <defs.h>
#include <file/my_file.h>
#include <lists/my_list.h>

typedef enum Token_Type {

    // identifier
    TOKEN_IDENT,

    // literals
    TOKEN_BOOL_LIT,
    TOKEN_INT_LIT,
    TOKEN_FLOAT_LIT,
    TOKEN_CHAR_LIT,
    TOKEN_STRING_LIT,

    // keywords
    TOKEN_MODULE,
    TOKEN_IMPORT,
    
    TOKEN_FN,
    TOKEN_RETURN,
    
    TOKEN_INTERNAL,
    TOKEN_PERSIST,
    
    TOKEN_STRUCT,
    TOKEN_UNION,
    TOKEN_ENUM,
    
    TOKEN_WHILE,
    TOKEN_FOR,
    TOKEN_SWITCH,
    TOKEN_IF,
    TOKEN_ELSE,
    
    TOKEN_BREAK,
    TOKEN_CONTINUE,
    
    TOKEN_TYPEOF,
    TOKEN_TYPE,
    
    TOKEN_TRUE,
    TOKEN_FALSE,
    
    TOKEN_CONST,

    // data types
    TOKEN_NULL,

    TOKEN_I8,
    TOKEN_I16,
    TOKEN_I32,
    TOKEN_I64,
    
    TOKEN_U8,
    TOKEN_U16,
    TOKEN_U32,
    TOKEN_U64,
    
    TOKEN_F32,
    TOKEN_F64,

    TOKEN_BOOL,
    TOKEN_CHAR,
    TOKEN_STRING,

    // Symbols
    TOKEN_PAREN_L,      // ()
    TOKEN_PAREN_R,
    TOKEN_BRACKET_L,    // []
    TOKEN_BRACKET_R,
    TOKEN_BRACES_L,     // {}
    TOKEN_BRACES_R,

    TOKEN_DOT,
    TOKEN_COMMA,

    TOKEN_COLON,
    TOKEN_SEMICOLON,

    TOKEN_ASSIGN,

    // Arithmetic
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_PERCENT,

    // Comparasion
    TOKEN_EQ,
    TOKEN_NEQ,
    TOKEN_LT,
    TOKEN_GT,
    TOKEN_LTE,
    TOKEN_GTE,

    // Logical
    TOKEN_AND,      // &&
    TOKEN_OR,       // ||
    TOKEN_BANG,     // !

    // Bitwise
    TOKEN_BIT_AMP,      // &
    TOKEN_BIT_PIPE,     // |
    TOKEN_BIT_TILDE,    // ~
    TOKEN_BIT_CARET,    // ^
    TOKEN_BIT_SHIFT_L,  // <<
    TOKEN_BIT_SHIFT_R,  // >>

    // Special
    TOKEN_EOF,          // end of file
    TOKEN_ERROR,

    TOTAL_TOKENS

} Token_Type;

typedef struct Token {

    Token_Type type;
    string     name;

    // 1-base
    i32        line;
    i32        col;

} Token;


typedef struct Lexer {

    string    source;  // full source
    const i8* start;   // start of the current token
    const i8* current; // current scan position

    i8* _end;
    i32 line;
    i32 col;

} Lexer;

DEFINE_LIST(Token);

// =======================================

// _LEXER_
extern Lexer* sLexer;
extern List(Token)* sToken;

// =======================================

null lexer_init(string source_file);
null lexer_tokenize();
null lexer_print_tokens();
null Lexer_free();
string token_name(Token_Type type);

// =======================================
null lex_prnt();
// =======================================