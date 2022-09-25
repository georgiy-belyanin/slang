#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  char* name;
  ast_t* ty;
} let_ast_t;

ast_t* create_let_ast(char* name, ast_t* ty);