#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_bin(codegen_t* codegen, bin_ast_t* bin_ast);
