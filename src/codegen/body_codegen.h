#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_body(codegen_t* codegen, body_ast_t* body_ast);
