#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  int val;
} int_ast_t;

ast_t* create_int_ast(int val);
void destroy_int_ast(int_ast_t* int_ast);