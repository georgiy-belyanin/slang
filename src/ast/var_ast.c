#include "var_ast.h"

#include <stdlib.h>

ast_t* create_var_ast(char* name) {
  var_ast_t* var_ast = malloc(sizeof(var_ast_t));
  var_ast->type = AST_VAR;
  var_ast->name = name;

  return (ast_t*) var_ast;
};
void destroy_var_ast(var_ast_t* var_ast) {
  free(var_ast->name);
  free(var_ast);
}