#include "codegen_num.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_num(num_ast_t* num_ast) {
  return LLVMConstInt(LLVMInt32TypeInContext(context), num_ast->val, 0);
}
