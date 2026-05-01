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
#include <string/my_string.h>
#include <lists/my_list.h>
#include <ast_visitor.h>

// Metadata for .smi.meta files
typedef struct Symbol_Metadata {
    string name;
    u64    hash; // for O(1) lookup
    u64    type_offset; // offset in type descriptor section 
    b8     is_function;    
} Symbol_Metadata;

DEFINE_LIST(Symbol_Metadata);

typedef struct Module_Metadata {
    u32 magic;              // 0x534D4920 "SMI"
    u16 version;
    string module_name;
    u64 symbol_count;
    List(Symbol_Metadata) symbols;
    u8* type_descriptors; // binary blob of information
    u64 type_desc_size;
} Module_Metadata;

typedef struct Module_Node {
    string name;        // module name
    string sm_path;    // path to .sm file          
    string si_path;    // path to .si file     
    string sim_path;   // path to compiled .smi file         
    string meta_path;  // path to .smi.meta         

    b8 is_compiled; // incremental compilation flag
    u64 sm_timestamp;
    u64 si_timestamp;
    u64 smi_timestamp;

    List(string) dependencies; // imported module names
} Module_Node;

DEFINE_LIST(Module_Node);

typedef struct Dependency_Graph {
    List(Module_Node) nodes;
    b8 has_cycle;
    List(string) sorted_order; // topological sort result
} Dependency_Graph;



