#include "if_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_if(codegen_t* codegen, if_ast_t* if_ast) {
  unit_t* func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(codegen->builder));
  unit_t* then = LLVMAppendBasicBlockInContext(codegen->context, func, "then");
  unit_t* ow = LLVMAppendBasicBlockInContext(codegen->context, func, "ow");
  unit_t* out = LLVMAppendBasicBlockInContext(codegen->context, func, "out");

  codegen_scope_next(codegen);

  unit_t* cond = ((rval_t*) codegen_gen(codegen, if_ast->cond))->val;
  LLVMBuildCondBr(codegen->builder, cond, then, ow);

  LLVMPositionBuilderAtEnd(codegen->builder, then);
  codegen_gen(codegen, if_ast->then);
  LLVMBuildBr(codegen->builder, out);

  LLVMPositionBuilderAtEnd(codegen->builder, ow);
  codegen_gen(codegen, if_ast->ow);
  LLVMBuildBr(codegen->builder, out);

  LLVMPositionBuilderAtEnd(codegen->builder, out);

  codegen_scope_prev(codegen);

  return NULL;
}
