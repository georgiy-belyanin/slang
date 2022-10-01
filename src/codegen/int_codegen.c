#include "int_codegen.h"

#include <llvm-c/Core.h>

unit_t* codegen_gen_int(codegen_t* codegen, int_ast_t* int_ast) {
  unit_t* ty = codegen_tys_get(codegen, "i32");
  return create_rval(LLVMConstInt(ty, int_ast->val, 0), ty);
}
