#include "codegen_while.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_while(while_ast_t* while_ast) {
  unit_t* func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(builder));
  unit_t* loop = LLVMAppendBasicBlockInContext(context, func, "while");
  unit_t* then = LLVMAppendBasicBlockInContext(context, func, "then");
  unit_t* out = LLVMAppendBasicBlockInContext(context, func, "out");

  scope_next();

  LLVMPositionBuilderAtEnd(builder, loop);
  unit_t* cond = ((rval_t*) codegen(while_ast->cond))->val;
  LLVMBuildCondBr(builder, cond, then, out);

  LLVMPositionBuilderAtEnd(builder, then);
  codegen(while_ast->body);
  LLVMBuildBr(builder, loop);

  LLVMPositionBuilderAtEnd(builder, out);

  scope_prev();
  return NULL;
}
