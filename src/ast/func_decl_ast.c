#include "func_decl_ast.h"

#include <stdlib.h>

ast_t* create_func_decl_ast(char* name, ast_t* ty, int arg_count, char** arg_names, ast_t** arg_tys) {
  func_decl_ast_t* func_decl_ast = malloc(sizeof(func_decl_ast_t));

  func_decl_ast->type = AST_FUNC_DECL;
  func_decl_ast->name = name;
  func_decl_ast->ty = ty;
  func_decl_ast->arg_count = arg_count;
  func_decl_ast->arg_names = arg_names;
  func_decl_ast->arg_tys = arg_tys;

  return (ast_t*) func_decl_ast;
}
void destroy_func_decl_ast(func_decl_ast_t* func_decl_ast) {
  free(func_decl_ast->name);
  destroy_ast(func_decl_ast->ty);
  for(int i = 0; i < func_decl_ast->arg_count; i++) {
    free(func_decl_ast->arg_names[i]);
    destroy_ast(func_decl_ast->arg_tys[i]);
  }
  free(func_decl_ast->arg_names);
  free(func_decl_ast->arg_tys);
  free(func_decl_ast);
}