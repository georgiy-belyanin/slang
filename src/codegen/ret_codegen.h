#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_ret(codegen_t* codegen, ret_ast_t* ret_ast);
