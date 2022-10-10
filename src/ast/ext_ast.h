#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  ast_t* func_decl;
} ext_ast_t;

ast_t* create_ext_ast(ast_t* func_decl);
void destroy_ext_ast(ext_ast_t* ext_ast);
