#include "codegen_int.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_int(int_ast_t* int_ast) {
  unit_t* ty = tys_get("i32");
  return create_rval(LLVMConstInt(ty, int_ast->val, 0), ty);
}
