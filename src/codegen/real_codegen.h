#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_real(codegen_t* codegen, real_ast_t* real_ast);
