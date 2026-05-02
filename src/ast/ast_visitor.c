#include <ast/ast_visitor.h>

null ast_walk(Node* node, AST_Visitor* visitor, null* ctx) {
    if(!node) return;

    switch (node->type) {
        case NODE_FN_DECL:
            if(visitor->visit_fn_decl)
                visitor->visit_fn_decl(&node->fn_decl, ctx);
            if(node->fn_decl.body)
                ast_walk(node->fn_decl.body, visitor, ctx);
            break;

        case NODE_STRUCT_DECL:
            if(visitor->visit_struct_decl)
                visitor->visit_struct_decl(&node->struct_decl, ctx);
            break;
            
        case NODE_UNION_DECL:
            if(visitor->visit_union_decl)
                visitor->visit_union_decl(&node->union_decl, ctx);
            break;

        case NODE_ENUM_DECL:
            if(visitor->visit_enum_decl)
                visitor->visit_enum_decl(&node->enum_decl, ctx);
            break;
        
        case NODE_IMPORT:
            if(visitor->visit_import)
                visitor->visit_import(&node->impt, ctx);
            break;

        case NODE_BINARY:
            if(visitor->visit_binary)
                visitor->visit_binary(&node->binary, ctx);
            ast_walk(node->binary.left,  visitor, ctx);
            ast_walk(node->binary.right, visitor, ctx);
            break;
        
        case NODE_UNARY:
            if(visitor->visit_unary)
                visitor->visit_unary(&node->unary, ctx);
            ast_walk(node->unary.operand, visitor, ctx);
            break;

        case NODE_CALL:
            if(visitor->visit_call)
                visitor->visit_call(&node->call, ctx);
            list_each(node->call.args, i) {
                ast_walk(&list_get(node->call.args, i), visitor, ctx);
            }
            break;
        
        case NODE_BLOCK:
            if(visitor->visit_block)
                visitor->visit_block(&node->block, ctx);
            list_each(node->block.Stmts, i) {
                ast_walk(&list_get(node->block.Stmts, i), visitor, ctx);
            }
            break;
        
        case NODE_RETURN:
            if(visitor->visit_return)
                visitor->visit_return(&node->ret, ctx);
            if(node->ret.expr)
                ast_walk(node->ret.expr, visitor, ctx);
            break;
        
        case NODE_IF:
            if(visitor->visit_if)
                visitor->visit_if(&node->if_stmt, ctx);
            ast_walk(node->if_stmt.cond, visitor, ctx);
            ast_walk(node->if_stmt.then_branch, visitor, ctx);

            if(node->if_stmt.else_branch)
                ast_walk(node->if_stmt.else_branch, visitor, ctx);
            break;

        case NODE_WHILE:
            if(visitor->visit_while)
                visitor->visit_while(&node->while_stmt, ctx);
            ast_walk(node->while_stmt.cond, visitor, ctx);
            ast_walk(node->while_stmt.body, visitor, ctx);
            break;
        
        case NODE_FOR:
            if(visitor->visit_for)
                visitor->visit_for(&node->for_stmt, ctx);
            if(node->for_stmt.init)
                ast_walk(node->for_stmt.init, visitor, ctx);
            if(node->for_stmt.cond)
                ast_walk(node->for_stmt.cond, visitor, ctx);
            if(node->for_stmt.step)
                ast_walk(node->for_stmt.step, visitor, ctx);
            ast_walk(node->for_stmt.body, visitor, ctx);
            break;

        case NODE_DECL_STMT:
            if(node->decl_stmt.init)
                ast_walk(node->decl_stmt.init, visitor, ctx);
            break;

        case NODE_EXPR_STMT:
            if(node->expr_stmt.expr)
                ast_walk(node->expr_stmt.expr, visitor, ctx);
            break;

        case NODE_INDEX:
            ast_walk(node->index.array, visitor, ctx);
            ast_walk(node->index.idx, visitor, ctx);
            break;
        
        case NODE_FIELD:
            ast_walk(node->field.object, visitor, ctx);
            break;
        
        default:
            break;
    }
}

null ast_walk_module_interface(Module_Interface* iface, AST_Visitor* visitor, null* ctx) {
    list_each(iface->imports, i) {
        ast_walk(&list_get(iface->imports, i), visitor, ctx);
    }
    list_each(iface->declarations, i) {
        ast_walk(&list_get(iface->declarations, i), visitor, ctx);
    }
}

null ast_walk_module_impl(Module_Implementation* impl, AST_Visitor* visitor, null* ctx) {
    list_each(impl->imports, i) {
        ast_walk(&list_get(impl->imports, i), visitor, ctx);
    }
    list_each(impl->decls, i) {
        ast_walk(&list_get(impl->decls, i), visitor, ctx);
    }
}

null ast_walk_entry(Entry_Point* entry, AST_Visitor* visitor, null* ctx) {
    list_each(entry->imports, i) {
        ast_walk(&list_get(entry->imports, i), visitor, ctx);
    }
    list_each(entry->decls, i) {
        ast_walk(&list_get(entry->decls, i), visitor, ctx);
    }
    if(entry->main_fn) {
        ast_walk(entry->main_fn, visitor, ctx);
    }
}
