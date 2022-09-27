#include "codegen_loop.h"

#include <llvm-c/Core.h>
#include "codegen.h"
#include "../utils.h"

unit_t* codegen_loop(loop_ast_t* loop_ast) {
  unit_t* func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(builder));
  unit_t* loop = LLVMAppendBasicBlockInContext(context, func, "loop");
  unit_t* out = LLVMAppendBasicBlockInContext(context, func, "out");

  scope_next();

  LLVMPositionBuilderAtEnd(builder, loop);
  codegen(loop_ast->body);
  LLVMBuildBr(builder, loop);
  LLVMPositionBuilderAtEnd(builder, out);

  scope_prev();


  return NULL;
}
