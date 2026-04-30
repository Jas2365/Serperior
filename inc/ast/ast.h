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

typedef enum Node_Type {

    #define X(node) node,
        NODE_LITERAL_TABLE     (X)
        NODE_OPERATION_TABLE   (X)
        NODE_STATEMENT_TABLE   (X)
        NODE_DECLARATION_TABLE (X)
    #undef X

} Node_Type;

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
typedef struct Block {
    List(Node) Stmts;
} Block;

typedef struct Return {
    Token token;
    Node* expr;
} Return;

typedef struct If {
    Token token;
    Node* cond;
    Node* then_branch;
    Node* else_branch;
} If;

typedef struct While {
    Token token;
    Node* cond;
    Node* body;
} While;

typedef struct For {
    Token token;
    Node* init;
    Node* cond;
    Node* step;
    Node* body;
} For;

typedef struct Break {
    Token token;
} Break;

typedef struct Continue {
    Token token;
} Continue;

// _Decl_

typedef struct Param {
    Token type;
    Token name;
} Param;

DEFINE_LIST(Param);

typedef struct Fn_Decl {
    Token return_type;
    Token name;
    List(Param) params;
    Node* body;
} Fn_Decl;

typedef struct Struct_field {
    Token type;
    Token name;
} Struct_field;

DEFINE_LIST(Struct_field);

typedef struct Struct_Decl {
    Token name;
    List(Struct_field) fields;
} Struct_Decl;

typedef struct Union_Decl {
    Token name;
    List(Struct_field) fields;
} Union_Decl;

typedef struct Enum_member {
    Token name;
    u64 value;
} Enum_member;

DEFINE_LIST(Enum_member);

typedef struct Enum_Decl {
    Token name;
    List(Enum_member) members;
} Enum_Decl;

typedef struct Import {
    Token module;
} Import;

typedef struct Program {

    List(Node) declarations;

} Program;

// _Node_

struct Node {
    Node_Type type;
    union {
        // _Expr_
        Ident       ident;
        Int_lit     int_lit;
        Float_lit   float_lit;
        String_lit  string_lit;
        Char_lit    char_lit;
        Bool_lit    bool_lit;

        Binary      binary;
        Unary       unary;
        Call        call;
        Index       index;
        Field       field;

        // _Stmt_
        Block       block;
        Return      ret;
        If          if_stmt;
        While       while_stmt;
        For         for_stmt;
        Break       break_stmt;
        Continue    continue_stmt;

        // _Decl_
        Fn_Decl     fn_decl;
        Struct_Decl struct_decl;
        Union_Decl  union_decl;
        Enum_Decl   enum_decl;
        Import      impt;
        Program     program;
    };
};