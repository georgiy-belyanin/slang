#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;
  
  ast_t* ty;
  int size;
} arr_ty_ast_t;
typedef struct {
  ast_type_t type;
  
  ast_t* ty;
} ptr_ty_ast_t;
typedef struct {
  ast_type_t type;
  
  char* name;
} ty_ast_t;

ast_t* create_arr_ty_ast(ast_t* ty, int size);
ast_t* create_ptr_ty_ast(ast_t* ty);
ast_t* create_ty_ast(char* name);
void destroy_ty_ast(ty_ast_t* ty_ast);