#pragma once

#include "ast_type.h"

typedef struct {
  ast_type_t type;
} ast_t;

void destroy_ast(ast_t* ast);