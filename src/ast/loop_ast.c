#include "loop_ast.h"

#include <stdlib.h>

ast_t* create_loop_ast(ast_t* body) {
  loop_ast_t* loop_ast = malloc(sizeof(loop_ast_t));
  
  loop_ast->type = AST_LOOP;
  loop_ast->body = body;

  return (ast_t*) loop_ast;
}
void destroy_loop_ast(loop_ast_t* loop_ast) {
  destroy_ast(loop_ast->body);
  free(loop_ast);
}