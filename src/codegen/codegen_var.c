#include "codegen_var.h"

#include <llvm-c/Core.h>
#include "codegen.h"

#include "../utils.h"
unit_t* codegen_var(var_ast_t* var_ast) {
  char* name = var_ast->name;
  unit_t* alloca = scope_get(name)->val;
  unit_t* ty = scope_get(name)->ty;
  unit_t* val = LLVMBuildLoad2(builder, ty, alloca, var_ast->name);
  return create_lval(val, ty, alloca);
}
