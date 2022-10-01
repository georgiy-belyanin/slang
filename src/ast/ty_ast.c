#include "ty_ast.h"

#include <stdlib.h>

ast_t* create_arr_ty_ast(ast_t* ty, int size) {
  return NULL;
}
ast_t* create_ptr_ty_ast(ast_t* ty) {
  return NULL;
}
ast_t* create_ty_ast(char* name) {
  ty_ast_t* ty_ast = malloc(sizeof(ty_ast_t));
  
  ty_ast->type = AST_TY;
  ty_ast->name = name;

  return (ast_t*) ty_ast;
}
void destroy_ty_ast(ty_ast_t* ty_ast) {
  free(ty_ast->name);
  free(ty_ast);
}