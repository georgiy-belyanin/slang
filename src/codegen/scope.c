#include "scope.h"

#include <stdlib.h>
#include "../etc.h"

struct scope_t {
  int scope;
  hashmap_t** scopes;
};

scope_t* create_scope() {
  scope_t* scope = malloc(sizeof(scope_t));
  scope->scope = 0;
  scope->scopes = calloc(sizeof(hashmap_t*), 16);
  scope->scopes[scope->scope] = create_hashmap();
  return scope;
}
void destroy_scope(scope_t* scope) {
  for(int i = scope->scope; i >= 0; i--) {
    hashmap_t* hashmap = scope->scopes[i];
    destroy_hashmap(hashmap);
  }
  free(scope);
}

void scope_next(scope_t* scope) {
  scope->scope++;
  scope->scopes[scope->scope] = create_hashmap();
}
void scope_prev(scope_t* scope) {
  destroy_hashmap(scope->scopes[scope->scope]);
  scope->scope--;
}
rval_t* scope_get(scope_t* scope, char* name) {
  for(int i = scope->scope; i >= 0; i--) {
    hashmap_t* hashmap = scope->scopes[i];
    if (hashmap_contains(hashmap, name))
      return hashmap_get(hashmap, name);
  }
  return NULL;
}
void scope_set(scope_t* scope, char* name, void* val) {
  hashmap_set(scope->scopes[scope->scope], name, val);
}
