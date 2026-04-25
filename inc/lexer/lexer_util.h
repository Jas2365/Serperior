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

#include <lexer/lexer.h>
#include <string/my_string.h>

typedef struct Token_info {
    string name;
    string symbol;
    Token_Type type;
} Token_info;

typedef struct double_char {
    char a, b;
    Token_Type single;
    Token_Type compound;

} double_char;

extern Token_info Keywords[];
extern s64 keyword_count;
extern Token_Type Char_table[];
extern s64 char_table_count;
extern double_char Double_char_Table[];
extern s64 double_char_table_count;

extern u8 char_class[256];

null lexer_util_info();