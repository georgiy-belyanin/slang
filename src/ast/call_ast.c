#include "call_ast.h"

#include <stdlib.h>

ast_t* create_call_ast(char* callee, int arg_count, ast_t** args) {
  call_ast_t* call_ast = malloc(sizeof(call_ast_t));
  
  call_ast->type = AST_CALL;
  call_ast->callee = callee;
  call_ast->arg_count = arg_count;
  call_ast->args = args;

  return (ast_t*) call_ast;
}