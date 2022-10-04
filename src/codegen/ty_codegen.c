#include "ty_codegen.h"

#include <string.h>
#include <llvm-c/Core.h>

unit_t* codegen_gen_ty(codegen_t* codegen, ty_ast_t* ty_ast) {
  return codegen_tys_get(codegen, ty_ast->name);
}
unit_t* codegen_gen_ptr_ty(codegen_t* codegen, ptr_ty_ast_t* ptr_ty_ast) {
  return LLVMPointerType(codegen_gen(codegen, ptr_ty_ast->ty), 0);
}
