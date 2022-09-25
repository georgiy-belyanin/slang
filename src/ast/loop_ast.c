#include "loop_ast.h"

#include <stdlib.h>

ast_t* create_loop_ast(ast_t* body) {
  loop_ast_t* loop_ast = malloc(sizeof(loop_ast_t));
  
  loop_ast->type = AST_LOOP;
  loop_ast->body = body;

  return (ast_t*) loop_ast;
}