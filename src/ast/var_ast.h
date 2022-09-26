#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;
  char* name;
} var_ast_t;

ast_t* create_var_ast(char* name);
void destroy_var_ast(var_ast_t* var_ast);