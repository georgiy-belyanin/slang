#pragma once

#include "../ast.h"
#include "unit.h"

typedef struct codegen_t codegen_t;

codegen_t* create_codegen();
void destroy_codegen(codegen_t* codegen);

unit_t* codegen_gen(codegen_t* codegen, ast_t* ast);
void codegen_dump(codegen_t* codegen);