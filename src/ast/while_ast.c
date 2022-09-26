#include "while_ast.h"

#include <stdlib.h>

ast_t* create_while_ast(ast_t* cond, ast_t* body) {
  while_ast_t* while_ast = malloc(sizeof(while_ast_t));
  
  while_ast->type = AST_WHILE;
  while_ast->cond = cond;
  while_ast->body = body;

  return (ast_t*) while_ast;
}
void destroy_while_ast(while_ast_t* while_ast) {
  destroy_ast(while_ast->cond);
  destroy_ast(while_ast->body);
  free(while_ast);
}