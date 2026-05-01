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

typedef struct AST_Visitor {

    null (*visit_fn_decl    )     (Fn_Decl*, null* ctx);
    null (*visit_struct_decl) (Struct_Decl*, null* ctx);
    null (*visit_union_decl )  (Union_Decl*, null* ctx);
    null (*visit_enum_decl  )   (Enum_Decl*, null* ctx);
    null (*visit_import     )      (Import*, null* ctx);
    null (*visit_binary     )      (Binary*, null* ctx);
    null (*visit_unary      )       (Unary*, null* ctx);
    null (*visit_call       )        (Call*, null* ctx);
    null (*visit_block      )       (Block*, null* ctx);
    null (*visit_return     )      (Return*, null* ctx);
    null (*visit_if         )          (If*, null* ctx);
    null (*visit_while      )       (While*, null* ctx);
    null (*visit_for        )         (For*, null* ctx);

} AST_Visitor;

// walk individual nodes
null ast_walk(Node* node, AST_Visitor* visitor, null* ctx);

// walk compilation units
null ast_walk_module_interface (Module_Interface*      iface , AST_Visitor* visitor, null* ctx);
null ast_walk_module_impl      (Module_Implementation* impl  , AST_Visitor* visitor, null* ctx);
null ast_walk_entry            (Entry_Point*           entry , AST_Visitor* visitor, null* ctx);
null ast_walk_ast              (AST*                   ast   , AST_Visitor* visitor, null* ctx);