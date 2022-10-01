#include "real_codegen.h"

#include <llvm-c/Core.h>

unit_t* codegen_gen_real(codegen_t* codegen, real_ast_t* real_ast) {
  unit_t* ty = codegen_tys_get(codegen, "f32");
  return create_rval(LLVMConstReal(ty, real_ast->val), ty);
}
