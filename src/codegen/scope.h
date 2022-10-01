#pragma once

#include "val.h"

typedef struct scope_t scope_t;

scope_t* create_scope();
void destroy_scope(scope_t* scope);

void scope_next(scope_t* scope);
void scope_prev(scope_t* scope);
rval_t* scope_get(scope_t* scope, char* name);
void scope_set(scope_t* scope, char* name, void* val);
