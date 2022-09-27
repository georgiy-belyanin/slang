#include "codegen_func_decl.h"

#include <llvm-c/Core.h>
#include "codegen.h"

#include "../utils.h"
unit_t* codegen_func_decl(func_decl_ast_t* func_decl_ast) {

  char* name = func_decl_ast->name;
  int arg_count = func_decl_ast->arg_count;
  char** arg_names = func_decl_ast->arg_names;

  unit_t** arg_tys = calloc(sizeof(unit_t*), arg_count);
  for (int i = 0; i < arg_count; i++)
    arg_tys[i] = codegen(func_decl_ast->arg_tys[i]);

  unit_t* ty = LLVMFunctionType(codegen(func_decl_ast->ty), (LLVMTypeRef*) arg_tys, arg_count, 0);
  unit_t* func = LLVMAddFunction(module, name, ty);
  unit_t* entry = LLVMAppendBasicBlockInContext(context, func, "entry");
  LLVMPositionBuilderAtEnd(builder, entry);

  scope_set(name, create_val(func, ty));

  for (int i = 0; i < arg_count; i++) {
    unit_t* arg_alloca = LLVMBuildAlloca(builder, arg_tys[i], arg_names[i]);
    scope_set(arg_names[i], arg_alloca);
    unit_t* arg_val = LLVMGetParam(func, i);
    LLVMBuildStore(builder, arg_val, arg_alloca);
  }

  return NULL;
}
