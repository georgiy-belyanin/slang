#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_func(codegen_t* codegen, func_ast_t* func_ast);
