#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_call(codegen_t* codegen, call_ast_t* call_ast);
