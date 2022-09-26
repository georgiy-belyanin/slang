#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  char* name;
  ast_t* ty;

  int arg_count;
  char** arg_names;
  ast_t** arg_tys;
} func_decl_ast_t;

ast_t* create_func_decl_ast(char* name, ast_t* ty, int arg_count, char** arg_names, ast_t** arg_tys);
void destroy_func_decl_ast(func_decl_ast_t* func_decl_ast);