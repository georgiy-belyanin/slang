#include "codegen_call.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_call(call_ast_t* call_ast) {
  char* callee = call_ast->callee;
  unit_t* func = LLVMGetNamedFunction(module, callee);

  int arg_count = call_ast->arg_count;
  unit_t** args = calloc(sizeof(unit_t*), call_ast->arg_count);

  for(int i = 0; i < arg_count; i++) 
    args[i] = codegen(call_ast->args[i]);

  return LLVMBuildCall(builder, func, (LLVMValueRef*) args, arg_count, "call_res");
}
