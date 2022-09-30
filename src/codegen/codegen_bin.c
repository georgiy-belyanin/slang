#include "codegen_bin.h"

#include <llvm-c/Core.h>
#include "codegen.h"
#include "../utils.h"

static rval_t* build_assign(rval_t* lhs, rval_t* rhs) {
  // if (LLVMGetTypeKind(lhs->ty) != LLVMIntegerTypeKind(rhs->ty))
  if (!rval_is_lval(lhs))
    return NULL;
  lval_t* lval = (lval_t*) lhs;
  unit_t* val = LLVMBuildStore(builder, rhs->val, lval->ptr);
  return create_rval(val, lhs->ty);
}
static int process_reals(rval_t* lhs, rval_t* rhs) {
  int is_real = LLVMGetTypeKind(lhs->ty) == LLVMFloatTypeKind || LLVMGetTypeKind(rhs->ty) == LLVMFloatTypeKind;

  if (LLVMGetTypeKind(lhs->ty) == LLVMFloatTypeKind && LLVMGetTypeKind(rhs->ty) == LLVMIntegerTypeKind) {
    rhs->val = LLVMBuildSIToFP(builder, rhs->val, lhs->ty, "ftoi_cast_res");
    rhs->ty = lhs->ty;
  } else if (LLVMGetTypeKind(lhs->ty) == LLVMIntegerTypeKind && LLVMGetTypeKind(rhs->ty) == LLVMFloatTypeKind) {
    lhs->val = LLVMBuildSIToFP(builder, lhs->val, rhs->ty, "ftoi_cast_res");
    lhs->ty = rhs->ty;
  }

  return is_real;
}
static rval_t* build_add(rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!process_reals(lhs, rhs))
    val = LLVMBuildAdd(builder, lhs->val, rhs->val, "add_res");
  else
    val = LLVMBuildFAdd(builder, lhs->val, rhs->val, "fadd_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_sub(rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!process_reals(lhs, rhs))
    val = LLVMBuildSub(builder, lhs->val, rhs->val, "sub_res");
  else {
    val = LLVMBuildFSub(builder, lhs->val, rhs->val, "fsub_res");
  }
  return create_rval(val, lhs->ty);
}
static rval_t* build_mul(rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!process_reals(lhs, rhs))
    val = LLVMBuildMul(builder, lhs->val, rhs->val, "mul_res");
  else
    val = LLVMBuildFMul(builder, lhs->val, rhs->val, "fmul_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_eq(rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!process_reals(lhs, rhs))
    val = LLVMBuildICmp(builder, LLVMIntEQ, lhs->val, rhs->val, "eq_res");
  else
    val = LLVMBuildFCmp(builder, LLVMRealOEQ, lhs->val, rhs->val, "feq_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_ne(rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!process_reals(lhs, rhs))
    val = LLVMBuildICmp(builder, LLVMIntNE, lhs->val, rhs->val, "ne_res");
  else
    val = LLVMBuildFCmp(builder, LLVMRealONE, lhs->val, rhs->val, "fne_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_less(rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!process_reals(lhs, rhs))
    val = LLVMBuildICmp(builder, LLVMIntSLE, lhs->val, rhs->val, "less_res");
  else
    val = LLVMBuildFCmp(builder, LLVMRealOLT, lhs->val, rhs->val, "fless_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_grtr(rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!process_reals(lhs, rhs))
    val = LLVMBuildICmp(builder, LLVMIntSGT, lhs->val, rhs->val, "grtr_res");
  else
    val = LLVMBuildFCmp(builder, LLVMRealOGT, lhs->val, rhs->val, "fgrtr_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_le(rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!process_reals(lhs, rhs))
    val = LLVMBuildICmp(builder, LLVMIntSLE, lhs->val, rhs->val, "le_res");
  else
    val = LLVMBuildFCmp(builder, LLVMRealOLE, lhs->val, rhs->val, "fle_res");
  return create_rval(val, lhs->ty);
}
static rval_t* build_ge(rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!process_reals(lhs, rhs))
    val = LLVMBuildICmp(builder, LLVMIntSGE, lhs->val, rhs->val, "ge_res");
  else
    val = LLVMBuildFCmp(builder, LLVMRealOGE, lhs->val, rhs->val, "fge_res");
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
    return build_assign(lhs, rhs);
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
