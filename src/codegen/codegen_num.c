#include "codegen_num.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_num(num_ast_t* num_ast) {
  unit_t* ty = tys_get("i32");
  return create_rval(LLVMConstInt(ty, num_ast->val, 0), ty);
}
