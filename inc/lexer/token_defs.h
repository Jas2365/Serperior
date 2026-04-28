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

#ifndef TOKEN_LITERAL
#define TOKEN_LITERAL(t_name, t_lex)
#endif

#ifndef TOKEN_KEYWORD
#define TOKEN_KEYWORD(t_name, t_lex)
#endif

#ifndef TOKEN_SYMBOL
#define TOKEN_SYMBOL(t_name, t_lex)
#endif

#ifndef TOKEN_SPECIAL
#define TOKEN_SPECIAL(t_name, t_lex)
#endif

//             NAME                LEX_NAME
// Literals
TOKEN_LITERAL( TOKEN_IDENT      ,  "ident"      )
TOKEN_LITERAL( TOKEN_BOOL_LIT   ,  "bool_lit"   )
TOKEN_LITERAL( TOKEN_INT_LIT    ,  "int_lit"    )
TOKEN_LITERAL( TOKEN_FLOAT_LIT  ,  "float_lit"  )
TOKEN_LITERAL( TOKEN_CHAR_LIT   ,  "char_lit"   )
TOKEN_LITERAL( TOKEN_STRING_LIT ,  "string_lit" )

// Keyword
TOKEN_KEYWORD( TOKEN_MODULE    ,   "module"    )
TOKEN_KEYWORD( TOKEN_IMPORT    ,   "import"    )
TOKEN_KEYWORD( TOKEN_FN        ,   "fn"        )
TOKEN_KEYWORD( TOKEN_RETURN    ,   "return"    )
TOKEN_KEYWORD( TOKEN_INTERNAL  ,   "internal"  )
TOKEN_KEYWORD( TOKEN_PERSIST   ,   "persist"   )
TOKEN_KEYWORD( TOKEN_STRUCT    ,   "struct"    )
TOKEN_KEYWORD( TOKEN_UNION     ,   "union"     )
TOKEN_KEYWORD( TOKEN_ENUM      ,   "enum"      )
TOKEN_KEYWORD( TOKEN_WHILE     ,   "while"     )
TOKEN_KEYWORD( TOKEN_FOR       ,   "for"       )
TOKEN_KEYWORD( TOKEN_SWITCH    ,   "switch"    )
TOKEN_KEYWORD( TOKEN_IF        ,   "if"        )
TOKEN_KEYWORD( TOKEN_ELSE      ,   "else"      )
TOKEN_KEYWORD( TOKEN_BREAK     ,   "break"     )
TOKEN_KEYWORD( TOKEN_CONTINUE  ,   "continue"  )
TOKEN_KEYWORD( TOKEN_TYPEOF    ,   "typeof"    )
TOKEN_KEYWORD( TOKEN_TYPE      ,   "type"      )
TOKEN_KEYWORD( TOKEN_TRUE      ,   "true"      )
TOKEN_KEYWORD( TOKEN_FALSE     ,   "false"     )
TOKEN_KEYWORD( TOKEN_CONST     ,   "const"     )
TOKEN_KEYWORD( TOKEN_NULL      ,   "null"      )
TOKEN_KEYWORD( TOKEN_I8        ,   "i8"        )
TOKEN_KEYWORD( TOKEN_I16       ,   "i16"       )
TOKEN_KEYWORD( TOKEN_I32       ,   "i32"       )
TOKEN_KEYWORD( TOKEN_I64       ,   "i64"       )
TOKEN_KEYWORD( TOKEN_U8        ,   "u8"        )
TOKEN_KEYWORD( TOKEN_U16       ,   "u16"       )
TOKEN_KEYWORD( TOKEN_U32       ,   "u32"       )
TOKEN_KEYWORD( TOKEN_U64       ,   "u64"       )
TOKEN_KEYWORD( TOKEN_F32       ,   "f32"       )
TOKEN_KEYWORD( TOKEN_F64       ,   "f64"       )
TOKEN_KEYWORD( TOKEN_BOOL      ,   "bool"      )
TOKEN_KEYWORD( TOKEN_CHAR      ,   "char"      )
TOKEN_KEYWORD( TOKEN_STRING    ,   "string"    )

// Symbol
TOKEN_SYMBOL( TOKEN_PAREN_L     , "("    )
TOKEN_SYMBOL( TOKEN_PAREN_R     , ")"    )
TOKEN_SYMBOL( TOKEN_BRACKET_L   , "["    )
TOKEN_SYMBOL( TOKEN_BRACKET_R   , "]"    )
TOKEN_SYMBOL( TOKEN_BRACES_L    , "{"    )
TOKEN_SYMBOL( TOKEN_BRACES_R    , "}"    )
TOKEN_SYMBOL( TOKEN_DOT         , "."    )
TOKEN_SYMBOL( TOKEN_COMMA       , ","    )
TOKEN_SYMBOL( TOKEN_COLON       , ":"    )
TOKEN_SYMBOL( TOKEN_SEMICOLON   , ";"    )
TOKEN_SYMBOL( TOKEN_ASSIGN      , "="    )
TOKEN_SYMBOL( TOKEN_PLUS        , "+"    )
TOKEN_SYMBOL( TOKEN_MINUS       , "-"    )
TOKEN_SYMBOL( TOKEN_STAR        , "*"    )
TOKEN_SYMBOL( TOKEN_SLASH       , "/"    )
TOKEN_SYMBOL( TOKEN_PERCENT     , "%"    )
TOKEN_SYMBOL( TOKEN_EQ          , "=="   )
TOKEN_SYMBOL( TOKEN_NEQ         , "!="   )
TOKEN_SYMBOL( TOKEN_LT          , "<"    )
TOKEN_SYMBOL( TOKEN_GT          , ">"    )
TOKEN_SYMBOL( TOKEN_LTE         , "<="   )
TOKEN_SYMBOL( TOKEN_GTE         , ">="   )
TOKEN_SYMBOL( TOKEN_AND         , "&&"   )
TOKEN_SYMBOL( TOKEN_OR          , "||"   )
TOKEN_SYMBOL( TOKEN_BANG        , "!"    )
TOKEN_SYMBOL( TOKEN_BIT_AMP     , "&"    )
TOKEN_SYMBOL( TOKEN_BIT_PIPE    , "|"    )
TOKEN_SYMBOL( TOKEN_BIT_TILDE   , "~"    )
TOKEN_SYMBOL( TOKEN_BIT_CARET   , "^"    )
TOKEN_SYMBOL( TOKEN_BIT_SHIFT_L , "<<"   )
TOKEN_SYMBOL( TOKEN_BIT_SHIFT_R , ">>"   )

// Special
TOKEN_SPECIAL( TOKEN_EOF      ,  "eof"    )
TOKEN_SPECIAL( TOKEN_ERROR    ,  "error"  )

#undef TOKEN_LITERAL
#undef TOKEN_KEYWORD
#undef TOKEN_SYMBOL
#undef TOKEN_SPECIAL

