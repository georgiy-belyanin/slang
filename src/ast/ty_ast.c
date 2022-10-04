#include "ty_ast.h"

#include <stdlib.h>


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


ast_t* create_ptr_ty_ast(ast_t* ty) {
  ptr_ty_ast_t* ptr_ty_ast = malloc(sizeof(ptr_ty_ast_t));

  ptr_ty_ast->type = AST_PTR_TY;
  ptr_ty_ast->ty = ty;
  
  return (ast_t*) ptr_ty_ast;
}
void destroy_ptr_ty_ast(ptr_ty_ast_t* ptr_ty_ast) {
  destroy_ast(ptr_ty_ast->ty);
  free(ptr_ty_ast);
}


ast_t* create_arr_ty_ast(ast_t* ty, int size) {
  return NULL;
}


ast_t* create_uptr_ty_ast(ast_t* ty) {
  //uptr_ty_ast_t* uptr_ty_ast = malloc(sizeof())
  return NULL;
}

ast_t* create_sptr_ty_ast(ast_t* ty) {
  return NULL;
}

