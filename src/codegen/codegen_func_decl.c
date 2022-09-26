#include "codegen_func_decl.h"

#include <llvm-c/Core.h>
#include "codegen.h"

#include "../utils.h"
unit_t* codegen_func_decl(func_decl_ast_t* func_decl_ast) {
  int arg_count = func_decl_ast->arg_count;
  unit_t** arg_tys = calloc(sizeof(unit_t*), arg_count);
  for(int i = 0; i < arg_count; i++)
    arg_tys[i] = codegen(func_decl_ast->arg_tys[i]);

  unit_t* ty = LLVMFunctionType(codegen(func_decl_ast->ty), (LLVMTypeRef*) arg_tys, arg_count, 0);
  char* name = func_decl_ast->name;

  unit_t* func = LLVMAddFunction(module, name, ty);
  unit_t* entry = LLVMAppendBasicBlockInContext(context, func, "entry");
  LLVMPositionBuilderAtEnd(builder, entry);
  return NULL;
}
