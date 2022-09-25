#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  ast_t* val;
} ret_ast_t;

ast_t* create_ret_ast(ast_t* val);