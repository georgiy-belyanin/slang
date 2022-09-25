#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  int stmt_count;
  ast_t** stmts;
} body_ast_t;

ast_t* create_body_ast(int stmt_count, ast_t** stmts);