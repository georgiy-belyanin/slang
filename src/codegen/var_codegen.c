#include "var_codegen.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_gen_var(codegen_t* codegen, var_ast_t* var_ast) {
  char* name = var_ast->name;
  unit_t* alloca = codegen_scope_get(codegen, name)->val;
  unit_t* ty = codegen_scope_get(codegen, name)->ty;
  unit_t* val = LLVMBuildLoad2(codegen->builder, ty, alloca, var_ast->name);
  return create_lval(val, ty, alloca);
}
