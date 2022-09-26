#pragma once

#include "ast.h"
#include "ast_type.h"

typedef struct {
  ast_type_t type;

  ast_t* cond;
  ast_t* body;
} while_ast_t;

ast_t* create_while_ast(ast_t* cond, ast_t* body);
void destroy_while_ast(while_ast_t* while_ast);