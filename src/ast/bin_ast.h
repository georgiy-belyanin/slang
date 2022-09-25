#pragma once

#include "ast.h"
#include "ast_type.h"

typedef int op_t;

typedef struct {
  ast_type_t type;

  op_t op;
  ast_t* lhs;
  ast_t* rhs;
} bin_ast_t;

ast_t* create_bin_ast(op_t op, ast_t* lhs, ast_t* rhs);