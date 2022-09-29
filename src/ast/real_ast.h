#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  float val;
} real_ast_t;

ast_t* create_real_ast(float val);
void destroy_real_ast(real_ast_t* real_ast);