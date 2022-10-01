#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_var(codegen_t* codegen, var_ast_t* var_ast);
