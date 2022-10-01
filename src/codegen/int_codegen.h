#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_int(codegen_t* codegen, int_ast_t* int_ast);
