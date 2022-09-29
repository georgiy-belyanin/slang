#include "real_ast.h"

#include <stdlib.h>

ast_t* create_real_ast(float val) {
  real_ast_t* real_ast = malloc(sizeof(real_ast_t));
  
  real_ast->type = AST_REAL;
  real_ast->val = val;

  return (ast_t*) real_ast;
}
void destroy_real_ast(real_ast_t* real_ast) {
  free(real_ast);
}