#include "var_ast.h"

#include <stdlib.h>

/*
#define VAR_LEVELS 10

static int var_level;
static hashmap_t* var_levels[VAR_LEVELS];

static unit_t* find_var(char* name) {
  for(int i = var_level; i >= 0; i--) {
    hashmap_t* hashmap = var_levels[i];
    if (hashmap_contains(hashmap, name))
      return hashmap_get(hashmap, name);
  }
  return NULL;
}*/

ast_t* create_var_ast(char* name) {
  var_ast_t* var_ast = malloc(sizeof(var_ast_t));
  var_ast->type = AST_VAR;
  var_ast->name = name;

  return (ast_t*) var_ast;
};
