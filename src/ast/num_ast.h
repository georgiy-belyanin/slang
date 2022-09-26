#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  int val;
} num_ast_t;

ast_t* create_num_ast(int val);
void destroy_num_ast(num_ast_t* num_ast);