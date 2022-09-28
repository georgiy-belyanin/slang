#include "codegen_if.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_if(if_ast_t* if_ast) {
  unit_t* func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(builder));
  unit_t* then = LLVMAppendBasicBlockInContext(context, func, "then");
  unit_t* ow = LLVMAppendBasicBlockInContext(context, func, "ow");
  unit_t* out = LLVMAppendBasicBlockInContext(context, func, "out");

  scope_next();

  unit_t* cond = ((rval_t*) codegen(if_ast->cond))->val;
  LLVMBuildCondBr(builder, cond, then, ow);

  LLVMPositionBuilderAtEnd(builder, then);
  codegen(if_ast->then);
  LLVMBuildBr(builder, out);

  LLVMPositionBuilderAtEnd(builder, ow);
  codegen(if_ast->ow);
  LLVMBuildBr(builder, out);

  LLVMPositionBuilderAtEnd(builder, out);

  scope_prev();

  return NULL;
}
