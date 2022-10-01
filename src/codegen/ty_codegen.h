#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_ty(codegen_t* codegen, ty_ast_t* ty_ast);
