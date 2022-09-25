#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  ast_t* cond;
  ast_t* body;
} if_ast_t;

ast_t* create_if_ast(ast_t* cond, ast_t* body);