#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;
  
  char* name;
} ty_ast_t;

ast_t* create_ty_ast(char* name);