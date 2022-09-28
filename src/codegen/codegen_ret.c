#include "codegen_ret.h"

#include <llvm-c/Core.h>
#include "codegen.h"
#include "../utils.h"

unit_t* codegen_ret(ret_ast_t* ret_ast) {
  rval_t* rval = (rval_t*) codegen(ret_ast->val);
  LLVMBuildRet(builder, rval->val);
  return NULL;
}
