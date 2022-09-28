#include "codegen_bin.h"

#include <llvm-c/Core.h>
#include "codegen.h"


// static rval_t* build_assign(lval_t* lhs, rval_t* rhs) {
//   if (lhs->ptr == NULL) 
//     return NULL;
//   return LLVMBuildStore(builder, lhs, scope_get(((var_ast_t*) bin_ast->lhs)->name)->val);
// };

static rval_t* build_add(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildAdd(builder, lhs->val, rhs->val, "add_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_sub(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildSub(builder, lhs->val, rhs->val, "sub_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_mul(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildMul(builder, lhs->val, rhs->val, "mul_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_eq(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildICmp(builder, LLVMIntEQ, lhs->val, rhs->val, "eq_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_ne(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildICmp(builder, LLVMIntNE, lhs->val, rhs->val, "ne_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_less(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildICmp(builder, LLVMIntSLT, lhs->val, rhs->val, "less_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_grtr(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildICmp(builder, LLVMIntSGT, lhs->val, rhs->val, "grtr_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_le(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildICmp(builder, LLVMIntSLE, lhs->val, rhs->val, "le_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_ge(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildICmp(builder, LLVMIntSGE, lhs->val, rhs->val, "ge_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_and(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildAnd(builder, lhs->val, rhs->val, "and_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_or(rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildOr(builder, lhs->val, rhs->val, "or_res");
  return create_rval(val, lhs->ty);
}


unit_t* codegen_bin(bin_ast_t* bin_ast) {
  unit_t* lhs = (rval_t*) codegen(bin_ast->lhs);
  unit_t* rhs = (rval_t*) codegen(bin_ast->rhs);
  if (bin_ast->op == OP_ASSIGN) {
    //LLVMBuildStore(builder, lhs, scope_get(((var_ast_t*) bin_ast->lhs)->name)->val);
    return NULL;
  } else if (bin_ast->op == OP_ADD)
    return build_add(lhs, rhs);
  else if (bin_ast->op == OP_SUB)
    return build_sub(lhs, rhs);
  else if (bin_ast->op == OP_MUL)
    return build_mul(lhs, rhs);
  else if (bin_ast->op == OP_DIV)
    return NULL;
  else if (bin_ast->op == OP_EQ)
    return build_eq(lhs, rhs);
  else if (bin_ast->op == OP_NE)
    return build_ne(lhs, rhs);
  else if (bin_ast->op == OP_LESS)
    return build_less(lhs, rhs);
  else if (bin_ast->op == OP_GRTR)
    return build_grtr(lhs, rhs);
  else if (bin_ast->op == OP_LE)
    return build_le(lhs, rhs);
  else if (bin_ast->op == OP_GE)
    return build_ge(lhs, rhs);

  else if (bin_ast->op == OP_AND)
    return build_and(lhs, rhs);
  else if (bin_ast->op == OP_OR)
    return build_or(lhs, rhs);

  else if (bin_ast->op == OP_BWAND)
    return build_and(lhs, rhs);
  else if (bin_ast->op == OP_BWOR)
    return build_or(lhs, rhs);
  return NULL;
}
