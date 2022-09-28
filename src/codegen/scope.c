#include "scope.h"

#include <stdlib.h>
#include "../etc.h"

static int scope;
static hashmap_t** scopes;

void scope_init() {
  scope = 0;
  scopes = calloc(sizeof(hashmap_t*), 16);
  scopes[scope] = create_hashmap();
}
void scope_next() {
  scope++;
  scopes[scope] = create_hashmap();
}
void scope_prev() {
  destroy_hashmap(scopes[scope]);
  scope--;
}
rval_t* scope_get(char* name) {
  for(int i = scope; i >= 0; i--) {
    hashmap_t* hashmap = scopes[i];
    if (hashmap_contains(hashmap, name))
      return hashmap_get(hashmap, name);
  }
  return NULL;
}
void scope_set(char* name, void* val) {
  hashmap_set(scopes[scope], name, val);
}
