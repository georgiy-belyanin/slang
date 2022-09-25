#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  char* callee;
  int arg_count;
  ast_t** args;
} call_ast_t;

ast_t* create_call_ast(char* callee, int arg_count, ast_t** args);