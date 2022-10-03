#pragma once

#include "unit.h"

typedef struct tys_t tys_t;

// Todo: Type costil'...
tys_t* create_tys(void* context);
void destroy_tys(tys_t* tys);

unit_t* tys_get(tys_t* tys, char* name);
void tys_set(tys_t* tys, char* name, unit_t* val);

