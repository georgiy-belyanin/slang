#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_let(codegen_t* codegen, let_ast_t* let_ast);
