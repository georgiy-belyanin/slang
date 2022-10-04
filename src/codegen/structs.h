#pragma once

#include "unit.h"

typedef struct structs_t structs_t;

// Todo: Type costil'...
structs_t* create_structs();
void destroy_structs(structs_t* tys);

int structs_get(structs_t* structs, char* name, char* field);
unit_t* structs_get_ty(structs_t* structs, char* name, char* field);
void structs_set(structs_t* structs, char* name, char** fields, unit_t** field_tys, int field_count);

