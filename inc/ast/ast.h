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
#include <lists/my_list.h>
#include <lexer/lexer.h>
#include <ast/ast_defs.h>

typedef enum node_type {

    #define X(node) tok,
        NODE_LITERAL_TABLE     (X)
        NODE_OPERATION_TABLE   (X)
        NODE_STATEMENT_TABLE   (X)
        NODE_DECLARATION_TABLE (X)
    #undef X

} node_type;

// _Node_Structs_

typedef struct Node Node;

DEFINE_LIST(Node);

// _Expr_
typedef struct Ident { Token name; } Ident;

typedef struct Int_lit    { Token token; u64 val; } Int_lit;
typedef struct Float_lit  { Token token; f64 val; } Float_lit;
typedef struct String_lit { Token token;          } String_lit;
typedef struct Char_lit   { Token token;          } Char_lit;
typedef struct Bool_lit   { Token token; b8 val;  } Bool_lit;

typedef struct Binary {
    Token op;
    Node* left;
    Node* right;
} Binary;

typedef struct Unary {
    Token op;
    Node* operand;
} Unary;

typedef struct Call {
    Token callee;
    List(Node) args;
} Call;

typedef struct Index {
    Node* array;
    Node* idx;
} Index;

typedef struct Field {
    Node* object;
    Token field;
} Field;

// _Stmt_
