#include "body_ast.h"

#include <stdlib.h>

ast_t* create_body_ast(int stmt_count, ast_t** stmts) {
  body_ast_t* body_ast = malloc(sizeof(body_ast));

  body_ast->type = AST_BODY;
  body_ast->stmt_count = stmt_count;
  body_ast->stmts = stmts;

  return (ast_t*) body_ast;
}

void destroy_body_ast(body_ast_t* body_ast) {
  for(int i = 0; i < body_ast->stmt_count; i++) 
    destroy_ast(body_ast->stmts[i]);
  free(body_ast);
}