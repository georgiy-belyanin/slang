#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  ast_t* body;
} loop_ast_t;

ast_t* create_loop_ast(ast_t* body);