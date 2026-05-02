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

#include <ast/ast.h>

typedef null (*node_free_fn)(Node*);

null node_free_recursive(Node*);

// _Literal_Constructors_
Node* make_ident       (Token name);
Node* make_int_lit     (Token token, u64 val);
Node* make_float_lit   (Token token, f64 val);
Node* make_string_lit  (Token token);
Node* make_char_lit    (Token token);
Node* make_bool_lit    (Token token, b8 val);

// _Operation_Constructors_
Node* make_binary      (Token op, Node* left, Node* right);
Node* make_unary       (Token op, Node* operand);
Node* make_call        (Token callee, List(Node) args);
Node* make_index       (Node* array, Node* idx);
Node* make_field       (Node* object, Token field);

// _Statement_Constructors_
Node* make_block       (List(Node) statements);
Node* make_return      (Token token, Node* expr);
Node* make_if          (Token token, Node* cond, Node* then_branch, Node* else_branch);
Node* make_while       (Token token, Node* cond, Node* body);
Node* make_for         (Token token, Node* init, Node* cond, Node* step, Node* body);
Node* make_break       (Token token);
Node* make_continue    (Token token);

// _Declaration_Constructors_
Node* make_fn_decl     (Token return_type, Token name, List(Param) params, Node* body);
Node* make_struct_decl (Token name, List(Param) fields);
Node* make_union_decl  (Token name, List(Param) fields);
Node* make_enum_decl   (Token name, List(Token) variants);
Node* make_import      (Token module);

// _Destruction_
null ast_destroy(Node* root);