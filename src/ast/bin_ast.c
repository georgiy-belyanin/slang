#include "bin_ast.h"

#include <stdlib.h>

ast_t* create_bin_ast(op_t op, ast_t* lhs, ast_t* rhs) {
  bin_ast_t* bin_ast = malloc(sizeof(bin_ast));

  bin_ast->type = AST_BIN;
  bin_ast->op = op;
  bin_ast->lhs = lhs;
  bin_ast->rhs = rhs;

  return (ast_t*) bin_ast;
}