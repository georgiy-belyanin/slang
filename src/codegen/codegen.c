#include "codegen.h"

#include <llvm-c/Core.h>

void codegen_scope_next(codegen_t* codegen) {
  scope_next(codegen->scope);
}
void codegen_scope_prev(codegen_t* codegen) {
  scope_prev(codegen->scope);
}
rval_t* codegen_scope_get(codegen_t* codegen, char* name) {
  return scope_get(codegen->scope, name);
}
void codegen_scope_set(codegen_t* codegen, char* name, void* val) {
  scope_set(codegen->scope, name, val);
}

unit_t* codegen_tys_get(codegen_t* codegen, char* name) {
  return tys_get(codegen->tys, name);
}
void codegen_tys_set(codegen_t* codegen, char* name, unit_t* val) {
  tys_set(codegen->tys, name, val);
}

int codegen_structs_get(codegen_t* codegen, char* name, char* field) {
  return structs_get(codegen->structs, name, field);
}
unit_t* codegen_structs_get_ty(codegen_t* codegen, char* name, char* field) {
  return structs_get_ty(codegen->structs, name, field);
}
void codegen_structs_set(codegen_t* codegen, char* name, char** fields, unit_t* field_tys, int field_count) {
  return structs_set(codegen->structs, name, fields, field_tys, field_count);
}
