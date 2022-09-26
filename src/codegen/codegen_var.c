#include "codegen_var.h"

#include <llvm-c/Core.h>
#include "codegen.h"

#include "../utils.h"
unit_t* codegen_var(var_ast_t* var_ast) {
  char* name = var_ast->name;
  return LLVMBuildLoad2(builder, LLVMInt32TypeInContext(context), scope_get(name), "val");
}
