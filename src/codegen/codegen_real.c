#include "codegen_real.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_real(real_ast_t* real_ast) {
  unit_t* ty = tys_get("f32");
  return create_rval(LLVMConstReal(ty, real_ast->val), ty);
}
