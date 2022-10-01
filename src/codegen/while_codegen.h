#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_while(codegen_t* codegen, while_ast_t* while_ast);
