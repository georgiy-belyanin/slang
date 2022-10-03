#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  char* name;
  ast_t* body;
} struct_ast_t;

ast_t* create_struct_ast(char* name, ast_t* body);
void destroy_struct_ast(struct_ast_t* struct_ty_ast);