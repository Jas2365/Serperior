/*
 * Copyright 2026 Jas2365
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this string except in compliance with the License.
 * You may obtain a copy at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by law or agreed to in writing, software distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
 * OR CONDITIONS OF ANY KIND, either express or implied.
 */

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"


#ifdef __INTELLISENSE__
    #define __typeof__(x) decltype(x)
    #define is_ptr(object) (0)
    #define to_ptr(object) (&(object))
#else
    #define _ptr_sentinel_ ((null*)0)
    #define _ptr_kind_ (__builtin_classify_type(_ptr_sentinel_))
    #define is_ptr(object) (__builtin_classify_type(object) == _ptr_kind_ )
    #define to_ptr(object) __builtin_choose_expr(is_ptr(object), (object), &(object))
#endif
#pragma GCC diagnostic pop