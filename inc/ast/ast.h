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
    NODE_COUNT
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

typedef struct Decl_Stmt {
    Token type;
    Token name;
    u8 flags;
    Node* init;
} Decl_Stmt;
typedef struct Expr_Stmt {
    Node* expr;
} Expr_Stmt;

// _Decl_

typedef struct Param {
    Token type;
    Token name;
    b8 is_array;
} Param;

DEFINE_LIST(Param);

typedef struct Fn_Decl {
    Token return_type;
    Token name;
    List(Param) params;
    Node* body;
    b8 is_internal;
    b8 has_body;
} Fn_Decl;

typedef struct Aggregate_Decl {
    Token name;
    List(Param) fields;
    u8 is_internal;
    b8 is_opaque;
} Aggregate_Decl;
// typedef struct Struct_Decl {
//     Token name;
//     List(Param) fields;
//     u8 is_internal;
//     b8 is_opaque;
// } Struct_Decl;

// typedef struct Union_Decl {
//     Token name;
//     List(Param) fields;
//     b8 is_internal;
//     b8 is_opaque;
// } Union_Decl;

typedef struct Enum_Decl {
    Token name;
    List(Token) variants;
    b8 is_internal;
} Enum_Decl;

typedef struct Import {
    Token module;
} Import;


// _Compilation_Units_
// .sm file- module public interface
typedef struct Module_Interface {
    Token module_name;
    List(Node) imports;
    List(Node) declarations;
} Module_Interface;

// .si file module implementations
typedef struct Module_Implementation {
    Token module_name;
    List(Node) imports;
    List(Node) decls;
} Module_Implementation;

// .ser file entry point
typedef struct Entry_Point {
    List(Node) imports;
    List(Node) decls;
    Node* main_fn;
} Entry_Point;

// Root AST node
typedef enum AST_Kind {
    AST_MODULE_INTERFACE, // .sm
    AST_MODULE_IMPL,      // .si
    AST_ENTRY_POINT,      // .ser
} AST_Kind;

typedef struct AST {
    AST_Kind kind;
    union {
        Module_Interface        interface;
        Module_Implementation   impl;
        Entry_Point             entry;
    };
} AST;

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
        Decl_Stmt   decl_stmt;
        Expr_Stmt   expr_stmt;

        // _Decl_
        Fn_Decl     fn_decl;
        Aggregate_Decl aggregate_decl;
        // Struct_Decl struct_decl;
        // Union_Decl  union_decl;
        Enum_Decl   enum_decl;
        Import      impt;
    };
};