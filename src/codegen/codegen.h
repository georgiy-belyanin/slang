#pragma once

#include <stdlib.h>
#include "../ast.h"
#include "../etc.h"
#include "val.h" 
#include "unit.h"

#define VAR_LEVELS 10

typedef void context_t;
typedef void module_t;
typedef void builder_t;


context_t* context;
module_t* module;
builder_t* builder;

int scope;
hashmap_t** scopes;

void codegen_init();
unit_t* codegen(ast_t* ast);

void scope_next();
void scope_prev();
val_t* scope_get(char* name);
void scope_set(char* name, void* val);
