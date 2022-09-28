#pragma once

#include "val.h"

void scope_init();
void scope_next();
void scope_prev();
rval_t* scope_get(char* name);
void scope_set(char* name, void* val);
