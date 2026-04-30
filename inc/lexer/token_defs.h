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

//             NAME                LEX_NAME
// Literals
#define TOKEN_LITERAL_TABLE(X)            \
    X( TOKEN_IDENT      ,  "ident"      ) \
    X( TOKEN_INT_LIT    ,  "int_lit"    ) \
    X( TOKEN_FLOAT_LIT  ,  "float_lit"  ) \
    X( TOKEN_CHAR_LIT   ,  "char_lit"   ) \
    X( TOKEN_STRING_LIT ,  "string_lit" )

// Keyword
#define TOKEN_KEYWORD_TABLE(X)          \
    X( TOKEN_MODULE    ,   "module"    )\
    X( TOKEN_IMPORT    ,   "import"    )\
    X( TOKEN_FN        ,   "fn"        )\
    X( TOKEN_RETURN    ,   "return"    )\
    X( TOKEN_INTERNAL  ,   "internal"  )\
    X( TOKEN_PERSIST   ,   "persist"   )\
    X( TOKEN_STRUCT    ,   "struct"    )\
    X( TOKEN_UNION     ,   "union"     )\
    X( TOKEN_ENUM      ,   "enum"      )\
    X( TOKEN_WHILE     ,   "while"     )\
    X( TOKEN_FOR       ,   "for"       )\
/*X( TOKEN_SWITCH    ,   "switch"    ) */\
    X( TOKEN_IF        ,   "if"        )\
    X( TOKEN_ELSE      ,   "else"      )\
    X( TOKEN_BREAK     ,   "break"     )\
    X( TOKEN_CONTINUE  ,   "continue"  )\
    X( TOKEN_TYPEOF    ,   "typeof"    )\
    X( TOKEN_TYPE      ,   "type"      )\
    X( TOKEN_TRUE      ,   "true"      )\
    X( TOKEN_FALSE     ,   "false"     )\
    X( TOKEN_CONST     ,   "const"     )\
    X( TOKEN_NULL      ,   "null"      )\
    X( TOKEN_I8        ,   "i8"        )\
    X( TOKEN_I16       ,   "i16"       )\
    X( TOKEN_I32       ,   "i32"       )\
    X( TOKEN_I64       ,   "i64"       )\
    X( TOKEN_U8        ,   "u8"        )\
    X( TOKEN_U16       ,   "u16"       )\
    X( TOKEN_U32       ,   "u32"       )\
    X( TOKEN_U64       ,   "u64"       )\
    X( TOKEN_F32       ,   "f32"       )\
    X( TOKEN_F64       ,   "f64"       )\
    X( TOKEN_BOOL      ,   "bool"      )\
    X( TOKEN_CHAR      ,   "char"      )\
    X( TOKEN_STRING    ,   "string"    )

// Symbol
#define TOKEN_SYMBOL_TABLE(X)      \
    X( TOKEN_PAREN_L     , "("    )\
    X( TOKEN_PAREN_R     , ")"    )\
    X( TOKEN_BRACKET_L   , "["    )\
    X( TOKEN_BRACKET_R   , "]"    )\
    X( TOKEN_BRACES_L    , "{"    )\
    X( TOKEN_BRACES_R    , "}"    )\
    X( TOKEN_DOT         , "."    )\
    X( TOKEN_COMMA       , ","    )\
    X( TOKEN_COLON       , ":"    )\
    X( TOKEN_SEMICOLON   , ";"    )\
    X( TOKEN_ASSIGN      , "="    )\
    X( TOKEN_PLUS        , "+"    )\
    X( TOKEN_MINUS       , "-"    )\
    X( TOKEN_STAR        , "*"    )\
    X( TOKEN_SLASH       , "/"    )\
    X( TOKEN_PERCENT     , "%"    )\
    X( TOKEN_EQ          , "=="   )\
    X( TOKEN_NEQ         , "!="   )\
    X( TOKEN_LT          , "<"    )\
    X( TOKEN_GT          , ">"    )\
    X( TOKEN_LTE         , "<="   )\
    X( TOKEN_GTE         , ">="   )\
    X( TOKEN_AND         , "&&"   )\
    X( TOKEN_OR          , "||"   )\
    X( TOKEN_BANG        , "!"    )\
    X( TOKEN_BIT_AMP     , "&"    )\
    X( TOKEN_BIT_PIPE    , "|"    )\
    X( TOKEN_BIT_TILDE   , "~"    )\
    X( TOKEN_BIT_CARET   , "^"    )\
    X( TOKEN_BIT_SHIFT_L , "<<"   )\
    X( TOKEN_BIT_SHIFT_R , ">>"   )

// Special
#define TOKEN_SPECIAL_TABLE(X)     \
    X( TOKEN_EOF      ,  "eof"    )\
    X( TOKEN_ERROR    ,  "error"  )

