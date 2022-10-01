#include "ret_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_ret(codegen_t* codegen, ret_ast_t* ret_ast) {
  rval_t* rval = (rval_t*) codegen_gen(codegen, ret_ast->val);
  LLVMBuildRet(codegen->builder, rval->val);
  return NULL;
}
