#include "func_decl_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_func_decl(codegen_t* codegen, func_decl_ast_t* func_decl_ast) {

  char* name = func_decl_ast->name;
  int arg_count = func_decl_ast->arg_count;
  char** arg_names = func_decl_ast->arg_names;

  unit_t** arg_tys = calloc(sizeof(unit_t*), arg_count);
  for (int i = 0; i < arg_count; i++)
    arg_tys[i] = codegen_gen(codegen, func_decl_ast->arg_tys[i]);

  unit_t* ty = LLVMFunctionType(codegen_gen(codegen, func_decl_ast->ty), (LLVMTypeRef*) arg_tys, arg_count, 0);
  unit_t* func = LLVMAddFunction(codegen->module, name, ty);
  unit_t* entry = LLVMAppendBasicBlockInContext(codegen->context, func, "entry");
  LLVMPositionBuilderAtEnd(codegen->builder, entry);

  codegen_scope_set(codegen, name, create_rval(func, ty));

  for (int i = 0; i < arg_count; i++) {
    unit_t* arg_alloca = LLVMBuildAlloca(codegen->builder, arg_tys[i], arg_names[i]);
    unit_t* arg = LLVMGetParam(func, i);

    LLVMBuildStore(codegen->builder, arg, arg_alloca);
    codegen_scope_set(codegen, arg_names[i], create_rval(arg_alloca, arg_tys[i]));
  }

  return NULL;
}
