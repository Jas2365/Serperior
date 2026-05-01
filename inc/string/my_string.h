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
#include <defs.h>

#include <lists/my_list.h>

typedef struct string {
    u64 length;
    i8* str; 
} string;

typedef struct strvw {
    u64 length;
    const i8* str;
} strvw;

DEFINE_LIST(string);

#define fmt_str "%.*s"

#define str_lit(s) (string){ .str = s, .length = sizeof(s) -1 }

string make_string(const i8* lit);

string copy_string(string* cf, string* sf);
b8 is_string_eq(string* a, string* b);