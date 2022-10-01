#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_if(codegen_t* codegen, if_ast_t* if_ast);
