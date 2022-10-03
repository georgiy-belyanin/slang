#include "struct_ast.h"

#include <stdlib.h>

ast_t* create_struct_ast(char* name, ast_t* body) {
  struct_ast_t* struct_ast = malloc(sizeof(struct_ast_t));

  struct_ast->type = AST_STRUCT;
  struct_ast->name = name;
  struct_ast->body = body;

  return (ast_t*) struct_ast;
}
void destroy_struct_ast(struct_ast_t* struct_ast) {
  destroy_ast(struct_ast->body);
  free(struct_ast->name);
  free(struct_ast);
}