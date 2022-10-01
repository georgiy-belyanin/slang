#include "call_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_call(codegen_t* codegen, call_ast_t* call_ast) {
  char* callee = call_ast->callee;
  unit_t* func = codegen_scope_get(codegen, callee)->val;
  unit_t* ty = codegen_scope_get(codegen, callee)->ty;

  int arg_count = call_ast->arg_count;
  unit_t** args = calloc(sizeof(unit_t*), call_ast->arg_count);

  for(int i = 0; i < arg_count; i++) 
    args[i] = ((rval_t*) codegen_gen(codegen, call_ast->args[i]))->val;

  return create_rval(LLVMBuildCall2(codegen->builder, ty, func, (LLVMValueRef*) args, arg_count, "call_res"), LLVMGetReturnType(ty));

  // return LLVMBuildCall2(builder, func, (LLVMValueRef*) args, arg_count, "call_res");
}
