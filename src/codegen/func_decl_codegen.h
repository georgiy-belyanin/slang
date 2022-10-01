#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_func_decl(codegen_t* codegen, func_decl_ast_t* func_decl_ast);
