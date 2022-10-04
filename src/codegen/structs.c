#include "structs.h"

#include <stdlib.h>
#include <llvm-c/Core.h>
#include "../etc.h"
#include "codegen.h"

typedef struct {
  int n;
  unit_t* ty;
} field_t;

static field_t* create_field(int n, unit_t* ty) {
  field_t* field = malloc(sizeof(field_t));

  field->n = n;
  field->ty = ty;

  return field;
}
static void destroy_field(field_t* field) {
  free(field);
}

struct structs_t {
  //LLVMContextRef context;
  hashmap_t* structs;
};

structs_t* create_structs(void* context) {
  structs_t* structs = malloc(sizeof(structs_t));

  structs->structs = create_hashmap();

  return structs;
}

void destroy_structs(structs_t* structs) {
  destroy_hashmap(structs->structs);
  free(structs);
}

int structs_get(structs_t* structs, char* name, char* field) {
  return ((field_t*) hashmap_get(hashmap_get(structs->structs, name), field))->n;
}
unit_t* structs_get_ty(structs_t* structs, char* name, char* field) {
  return ((field_t*) hashmap_get(hashmap_get(structs->structs, name), field))->ty;
}
void structs_set(structs_t* structs, char* name, char** fields, unit_t** field_tys, int field_count) {
  hashmap_set(structs->structs, name, create_hashmap());
  for(int i = 0; i < field_count; i++) {
    hashmap_set(hashmap_get(structs->structs, name), fields[i], create_field(i, field_tys[i]));
  }
}
