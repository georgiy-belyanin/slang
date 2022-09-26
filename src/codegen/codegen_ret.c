#include "codegen_ret.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_ret(ret_ast_t* ret_ast) {
  LLVMBuildRet(builder, codegen(ret_ast->val));
  return NULL;
}
