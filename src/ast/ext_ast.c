#include "ext_ast.h"

#include <stdlib.h>

ast_t* create_ext_ast(ast_t* func_decl) {
  ext_ast_t* ext_ast = malloc(sizeof(ext_ast_t));
  
  ext_ast->type = AST_EXT;
  ext_ast->func_decl = func_decl;

  return (ast_t*) ext_ast;
}
void destroy_ext_ast(ext_ast_t* ext_ast) {
  destroy_ast(ext_ast->func_decl);
  free(ext_ast);
}