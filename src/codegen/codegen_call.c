#include "codegen_call.h"

#include <llvm-c/Core.h>
#include "codegen.h"
#include "../utils.h"

unit_t* codegen_call(call_ast_t* call_ast) {
  char* callee = call_ast->callee;
  unit_t* func = scope_get(callee)->val;
  unit_t* ty = scope_get(callee)->ty;

  int arg_count = call_ast->arg_count;
  unit_t** args = calloc(sizeof(unit_t*), call_ast->arg_count);

  for(int i = 0; i < arg_count; i++) 
    args[i] = ((rval_t*) codegen(call_ast->args[i]))->val;

  return create_rval(LLVMBuildCall2(builder, ty, func, (LLVMValueRef*) args, arg_count, "call_res"), LLVMGetReturnType(ty));

  // return LLVMBuildCall2(builder, func, (LLVMValueRef*) args, arg_count, "call_res");
}
