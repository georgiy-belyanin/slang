#include "ty_ast.h"

#include <stdlib.h>

ast_t* create_ty_ast(char* name) {
  ty_ast_t* ty_ast = malloc(sizeof(ty_ast_t));
  
  ty_ast->type = AST_TY;
  ty_ast->name = name;

  return (ast_t*) ty_ast;
}