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

/**
 *  Include this file mulitple times with differnt file macro definitions.
 *  Macros default to no-op if not defined before including.
 *  all macro #undef'd at the bottom. 
 */

 #pragma once

#define NODE_LITERAL_TABLE(X)\
    X(   NODE_IDENT         )\
    X(   NODE_INT_LIT       )\
    X(   NODE_FLOAT_LIT     )\
    X(   NODE_CHAR_LIT      )\
    X(   NODE_STRING_LIT    )\
    X(   NODE_BOOL_LIT      )\
    X(   NODE_NULL_LIT      )

/**
 * BINARY   a + b
 * UNARY    ~a !a
 * CALL     add(a, b)
 * INDEX    arr[i]
 * FIELD    obj.field
 */

#define NODE_OPERATION_TABLE(X)\
    X(  NODE_BINARY           )\
    X(  NODE_UNARY            )\
    X(  NODE_CALL             )\
    X(  NODE_INDEX            )\
    X(  NODE_FIELD            )

#define NODE_STATEMENT_TABLE(X)\
    X(  NODE_BLOCK            )\
    X(  NODE_RETURN           )\
    X(  NODE_IF               )\
    X(  NODE_WHILE            )\
    X(  NODE_FOR              )\
    X(  NODE_BREAK            )\
    X(  NODE_CONTINUE         )

#define NODE_DECLARATION_TABLE(X)\
    X(  NODE_FN_DECL            )\
    X(  NODE_PARAM              )\
    X(  NODE_STRUCT_DECL        )\
    X(  NODE_UNION_DECL         )\
    X(  NODE_ENUM_DECL          )\
    X(  NODE_IMPORT             )\
    X(  NODE_PROGRAM            )
