#include "ret_ast.h"

#include <stdlib.h>

ast_t* create_ret_ast(ast_t* val) {
  ret_ast_t* ret_ast = malloc(sizeof(ret_ast_t));
  
  ret_ast->type = AST_RET;
  ret_ast->val = val;

  return (ast_t*) ret_ast;
}