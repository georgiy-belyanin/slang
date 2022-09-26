#include "if_ast.h"

#include <stdlib.h>

ast_t* create_if_ast(ast_t* cond, ast_t* body) {
  if_ast_t* if_ast = malloc(sizeof(if_ast_t));
  
  if_ast->type = AST_IF;
  if_ast->cond = cond;
  if_ast->body = body;

  return (ast_t*) if_ast;
}
void destroy_if_ast(if_ast_t* if_ast) {
  destroy_ast(if_ast->cond);
  destroy_ast(if_ast->body);
  free(if_ast);
}