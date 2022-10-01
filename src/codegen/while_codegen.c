#include "while_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_while(codegen_t* codegen, while_ast_t* while_ast) {
  unit_t* func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(codegen->builder));
  unit_t* loop = LLVMAppendBasicBlockInContext(codegen->context, func, "while");
  unit_t* then = LLVMAppendBasicBlockInContext(codegen->context, func, "then");
  unit_t* out = LLVMAppendBasicBlockInContext(codegen->context, func, "out");

  codegen_scope_next(codegen);

  LLVMPositionBuilderAtEnd(codegen->builder, loop);
  unit_t* cond = ((rval_t*) codegen_gen(codegen, while_ast->cond))->val;
  LLVMBuildCondBr(codegen->builder, cond, then, out);

  LLVMPositionBuilderAtEnd(codegen->builder, then);
  codegen_gen(codegen, while_ast->body);
  LLVMBuildBr(codegen->builder, loop);

  LLVMPositionBuilderAtEnd(codegen->builder, out);

  codegen_scope_prev(codegen);
  return NULL;
}
