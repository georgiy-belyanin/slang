#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_struct(codegen_t* codegen, struct_ast_t* struct_ast);
