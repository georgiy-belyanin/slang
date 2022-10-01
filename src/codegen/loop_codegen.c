#include "loop_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_loop(codegen_t* codegen, loop_ast_t* loop_ast) {
  unit_t* func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(codegen->builder));
  unit_t* loop = LLVMAppendBasicBlockInContext(codegen->context, func, "loop");
  unit_t* out = LLVMAppendBasicBlockInContext(codegen->context, func, "out");

  codegen_scope_next(codegen);

  LLVMPositionBuilderAtEnd(codegen->builder, loop);
  codegen_gen(codegen, loop_ast->body);
  LLVMBuildBr(codegen->builder, loop);
  LLVMPositionBuilderAtEnd(codegen->builder, out);

  codegen_scope_prev(codegen);

  return NULL;
}
