#pragma once

#include <stdlib.h>
#include "../ast.h"
#include "../etc.h"
#include "public.h"
#include "scope.h"
#include "tys.h"
#include "unit.h"
#include "val.h"

typedef void context_t;
typedef void module_t;
typedef void builder_t;

struct codegen_t {
  context_t* context;
  module_t* module;
  builder_t* builder;

  tys_t* tys;
  scope_t* scope;
};

void codegen_scope_next(codegen_t* codegen);
void codegen_scope_prev(codegen_t* codegen);
rval_t* codegen_scope_get(codegen_t* codegen, char* name);
void codegen_scope_set(codegen_t* codegen, char* name, void* val);

unit_t* codegen_tys_get(codegen_t* codegen, char* name);

