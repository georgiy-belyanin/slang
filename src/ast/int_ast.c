#include "int_ast.h"

#include <stdlib.h>

ast_t* create_int_ast(int val) {
  int_ast_t* int_ast = malloc(sizeof(int_ast_t));
  
  int_ast->type = AST_INT;
  int_ast->val = val;

  return (ast_t*) int_ast;
}
void destroy_int_ast(int_ast_t* int_ast) {
  free(int_ast);
}