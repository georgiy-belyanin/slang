#include "let_ast.h"

#include <stdlib.h>

ast_t* create_let_ast(char* name, ast_t* ty) {
  let_ast_t* let_ast = malloc(sizeof(let_ast_t));

  let_ast->type = AST_LET;
  let_ast->name = name;
  let_ast->ty = ty;

  return (ast_t*) let_ast;
}