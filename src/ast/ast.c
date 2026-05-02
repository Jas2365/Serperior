
#include <ast/ast.h>
#include <ast/ast_util.h>

#include <stdlib.h> // calloc

static inline Node* alloc_node() {
    return (Node*)calloc(1, sizeof(Node));
}

// _Literal_Constructors_
Node* make_ident(Token name) {
    Node* n = alloc_node();
    n->type = NODE_IDENT;
    n->ident = (Ident){ .name = name };
    return n;
}

Node* make_int_lit(Token token, u64 val) {
    Node* n = alloc_node();
    n->type = NODE_INT_LIT;
    n->int_lit = (Int_lit) { .token = token, .val = val };
    return n;
}

Node* make_float_lit(Token token, f64 val) {
    Node* n = alloc_node();
    n->type = NODE_FLOAT_LIT;
    n->float_lit = (Float_lit) { .token = token, .val = val };
    return n;
}

Node* make_char_lit(Token token) {
    Node* n = alloc_node();
    n->type = NODE_CHAR_LIT;
    n->char_lit = (Char_lit) { .token = token };
    return n;
}

Node* make_string_lit(Token token) {
    Node* n = alloc_node();
    n->type = NODE_STRING_LIT;
    n->string_lit = (String_lit) { .token = token };
    return n;
}

Node* make_bool_lit(Token token, b8 val) {
    Node* n = alloc_node();
    n->type = NODE_BOOL_LIT;
    n->bool_lit = (Bool_lit) { .token = token, .val = val };
    return n;
}

Node* make_binary(Token op, Node* left, Node* right) {
    Node* n = alloc_node();
    n->type = NODE_BINARY;
    n->binary = (Binary) {.op = op, .left = left, .right = right};
    return n;
}

Node* make_unary(Token op, Node* operand) {
    Node* n = alloc_node();
    n->type = NODE_UNARY;
    n->unary = (Unary) {.op = op, .operand = operand};
    return n;
}

Node* make_call(Token callee, List(Node) args) {
    Node* n = alloc_node();
    n->type = NODE_CALL;
    n->call = (Call) {.callee = callee, .args = args};
    return n;
}

Node* make_index(Node* array, Node* idx) {
    Node* n = alloc_node();
    n->type = NODE_INDEX;
    n->index = (Index) {.array = array, .idx = idx};
    return n;
}

Node* make_field(Node* object, Token field) {
    Node* n = alloc_node();
    n->type = NODE_FIELD;
    n->field = (Field) { .object = object, .field = field };    
    return n;
}

// _Statement_Constructors_
Node* make_block(List(Node) statements) {
    Node* n = alloc_node();
    n->type = NODE_BLOCK;
    n->block = (Block) {.Stmts = statements};
    return n;
}
Node* make_return(Token token, Node* expr) {
    Node* n = alloc_node();
    n->type = NODE_RETURN;
    n->ret = (Return) {.token = token, .expr = expr };
    return n;
}
Node* make_if(Token token, Node* cond, Node* then_branch, Node* else_branch) {
    Node* n = alloc_node();
    n->type = NODE_IF;
    n->if_stmt = (If) {.token = token, .cond = cond, .then_branch = then_branch, .else_branch = else_branch};
    return n;
}
Node* make_while(Token token, Node* cond, Node* body) {
    Node* n = alloc_node();
    n->type = NODE_WHILE;
    n->while_stmt = (While) {.token = token, .cond = cond, .body = body};
    return n;
}
Node* make_for(Token token, Node* init, Node* cond, Node* step, Node* body) {
    Node* n = alloc_node();
    n->type = NODE_FOR;
    n->for_stmt = (For) {.token = token, .init = init, .cond = cond, .step = step, .body = body};
    return n;
}
Node* make_break(Token token) {
    Node* n = alloc_node();
    n->type = NODE_BREAK;
    n->break_stmt = (Break) {.token = token };
    return n;
}
Node* make_continue(Token token) {
    Node* n = alloc_node();
    n->type = NODE_CONTINUE;
    n->continue_stmt = (Continue) {.token = token};
    return n;
}

// _Declaration_Constructors_
Node* make_fn_decl(Token return_type, Token name, List(Param) params, Node* body) {
    Node* n = alloc_node();
    n->type = NODE_FN_DECL;
    n->fn_decl = (Fn_Decl) {.return_type = return_type, .name = name, .params = params, .body = body};
    return n;
}
Node* make_struct_decl(Token name, List(Param) fields) {
    Node* n = alloc_node();
    n->type = NODE_STRUCT_DECL;
    n->struct_decl = (Struct_Decl) {.name = name, .fields = fields};
    return n;
}
Node* make_union_decl(Token name, List(Param) fields) {
    Node* n = alloc_node();
    n->type = NODE_UNION_DECL;
    n->union_decl = (Union_Decl) {.name = name, .fields = fields};
    return n;
}
Node* make_enum_decl(Token name, List(Token) variants) {
    Node* n = alloc_node();
    n->type = NODE_ENUM_DECL;
    n->enum_decl = (Enum_Decl) {.name = name, .variants = variants};
    return n;
}
Node* make_import(Token module) {
    Node* n = alloc_node();
    n->type = NODE_IMPORT;
    n->impt = (Import) {.module = module};
    return n;
}

static null free_binary(Node* n) {
    node_free_recursive(n->binary.left);
    node_free_recursive(n->binary.right);
}

static null free_unary(Node* n) {
    node_free_recursive(n->unary.operand);
}

static null free_call(Node* n) {
    list_each(n->call.args, i) {
        node_free_recursive(&list_get(n->call.args, i));
    }
    list_free(n->call.args);
}

static null free_index(Node* n) {
    node_free_recursive(n->index.array);
    node_free_recursive(n->index.idx);
}

static null free_field(Node* n) {
    node_free_recursive(n->field.object);
}

static null free_block(Node* n) {
    list_each(n->block.Stmts, i) {
        node_free_recursive(&list_get(n->block.Stmts, i));
    }
    list_free(n->block.Stmts);
}

static null free_return(Node* n) {
    node_free_recursive(n->ret.expr);
}

static null free_if(Node* n) {
    node_free_recursive(n->if_stmt.cond);
    node_free_recursive(n->if_stmt.then_branch);
    node_free_recursive(n->if_stmt.else_branch);
}

static null free_while(Node* n) {
    node_free_recursive(n->while_stmt.cond);
    node_free_recursive(n->while_stmt.body);
}

static null free_for(Node* n) {
    node_free_recursive(n->for_stmt.init);
    node_free_recursive(n->for_stmt.cond);
    node_free_recursive(n->for_stmt.step);
    node_free_recursive(n->for_stmt.body);
}

static null free_fn_decl(Node* n) {
    list_free(n->fn_decl.params);
    node_free_recursive(n->fn_decl.body);
}

static null free_struct_decl(Node* n) {
    list_free(n->struct_decl.fields);
}
static null free_union_decl(Node* n) {
    list_free(n->union_decl.fields);
}
static null free_enum_decl(Node* n) {
    list_free(n->enum_decl.variants);
}


static node_free_fn node_free_table[] = {
    [   NODE_BINARY         ] = free_binary      ,
    [   NODE_UNARY          ] = free_unary       ,
    [   NODE_CALL           ] = free_call        ,
    [   NODE_INDEX          ] = free_index       ,
    [   NODE_FIELD          ] = free_field       ,
    [   NODE_BLOCK          ] = free_block       ,
    [   NODE_RETURN         ] = free_return      ,
    [   NODE_IF             ] = free_if          ,
    [   NODE_WHILE          ] = free_while       ,
    [   NODE_FOR            ] = free_for         ,
    [   NODE_FN_DECL        ] = free_fn_decl     ,
    [   NODE_STRUCT_DECL    ] = free_struct_decl ,
    [   NODE_UNION_DECL     ] = free_union_decl  ,
    [   NODE_ENUM_DECL      ] = free_enum_decl   ,
};

null node_free_recursive(Node* n) {
    if(!n) return;
    if(node_free_table[n->type]) {
        node_free_table[n->type](n);
    }
    free(n);
}

null ast_destroy(Node* root) {
    node_free_recursive(root);
}