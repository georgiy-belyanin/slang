#pragma once

#include <stdlib.h>
#include "../ast.h"
#include "unit.h"

typedef void context_t;
typedef void module_t;
typedef void builder_t;

context_t* context;
module_t* module;
builder_t* builder;

void codegen_init();
unit_t* codegen(ast_t* ast);
