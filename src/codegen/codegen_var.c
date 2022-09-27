#include "codegen_var.h"

#include <llvm-c/Core.h>
#include "codegen.h"

#include "../utils.h"
unit_t* codegen_var(var_ast_t* var_ast) {
  char* name = var_ast->name;
  val_t* val = scope_get(name);
  unit_t* alloca = val->val;
  unit_t* ty = val->ty;
  return LLVMBuildLoad2(builder, ty, alloca, "val");
}
