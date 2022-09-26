#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;
  
  ast_t* decl;
  ast_t* body;
} func_ast_t;

ast_t* create_func_ast(ast_t* decl, ast_t* body);
void destroy_func_ast(func_ast_t* func_ast);