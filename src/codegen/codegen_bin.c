#include "codegen_bin.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_bin(bin_ast_t* bin_ast) {
  if (bin_ast->op == OP_ASSIGN)
    return NULL;
  else if (bin_ast->op == OP_ADD)
    return LLVMBuildAdd(builder, codegen(bin_ast->lhs), codegen(bin_ast->rhs), "add_res");
  else if (bin_ast->op == OP_SUB)
    return LLVMBuildSub(builder, codegen(bin_ast->lhs), codegen(bin_ast->rhs), "sub_res");
  else if (bin_ast->op == OP_MUL)
    return LLVMBuildMul(builder, codegen(bin_ast->lhs), codegen(bin_ast->rhs), "mul_res");
  else if (bin_ast->op == OP_DIV)
    return NULL;

  else if (bin_ast->op == OP_EQ)
    return NULL;
  else if (bin_ast->op == OP_NE)
    return NULL;
  else if (bin_ast->op == OP_LESS)
    return NULL;
  else if (bin_ast->op == OP_GRTR)
    return NULL;
  else if (bin_ast->op == OP_LE)
    return NULL;
  else if (bin_ast->op == OP_GE)
    return NULL;

  else if (bin_ast->op == OP_NOT)
    return NULL;
  else if (bin_ast->op == OP_AND)
    return NULL;
  else if (bin_ast->op == OP_OR)
    return NULL;

  else if (bin_ast->op == OP_BWAND)
    return NULL;
  else if (bin_ast->op == OP_BWOR)
    return NULL;
  return NULL;
}
