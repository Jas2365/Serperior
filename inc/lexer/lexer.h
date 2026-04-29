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

#pragma once

#include <ints.h>
#include <defs.h>
#include <file/my_file.h>
#include <lists/my_list.h>
#include <lexer/token_defs.h>

typedef enum Token_Type {

    #define X(name, lex) name,
    TOKEN_LITERAL_TABLE  (X)
    TOKEN_KEYWORD_TABLE  (X)
    TOKEN_SYMBOL_TABLE   (X)
    TOKEN_SPECIAL_TABLE  (X)
    #undef X
    TOKEN_COUNT
    
} Token_Type;

typedef struct Token {

    Token_Type type;
    string     name;

    // 1-base
    i32        line;
    i32        col;

} Token;


typedef struct Lexer {

    string  source;  // full source
    i8*     start;   // start of the current token
    i8*     current; // current scan position

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
null lexer_token_log();
null print_token(Token t);


// =======================================
null lex_prnt();
// =======================================