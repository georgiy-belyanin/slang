#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_loop(codegen_t* codegen, loop_ast_t* loop_ast);
