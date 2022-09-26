#include "num_ast.h"

#include <stdlib.h>

ast_t* create_num_ast(int val) {
  num_ast_t* num_ast = malloc(sizeof(num_ast_t));
  
  num_ast->type = AST_NUM;
  num_ast->val = val;

  return (ast_t*) num_ast;
}
void destroy_num_ast(num_ast_t* num_ast) {
  free(num_ast);
}