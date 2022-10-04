#include "bin_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

static rval_t* codegen_gen_assign(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  // if (LLVMGetTypeKind(lhs->ty) != LLVMIntegerTypeKind(rhs->ty))
  if (!rval_is_lval(lhs))
    return NULL;
  lval_t* lval = (lval_t*) lhs;
  unit_t* val = LLVMBuildStore(codegen->builder, rhs->val, lval->ptr);
  return create_rval(val, lhs->ty);
}
static int codegen_process_reals(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  int is_real = LLVMGetTypeKind(lhs->ty) == LLVMFloatTypeKind || LLVMGetTypeKind(rhs->ty) == LLVMFloatTypeKind;

  if (LLVMGetTypeKind(lhs->ty) == LLVMFloatTypeKind && LLVMGetTypeKind(rhs->ty) == LLVMIntegerTypeKind) {
    rhs->val = LLVMBuildSIToFP(codegen->builder, rhs->val, lhs->ty, "ftoi_cast_res");
    rhs->ty = lhs->ty;
  } else if (LLVMGetTypeKind(lhs->ty) == LLVMIntegerTypeKind && LLVMGetTypeKind(rhs->ty) == LLVMFloatTypeKind) {
    lhs->val = LLVMBuildSIToFP(codegen->builder, lhs->val, rhs->ty, "ftoi_cast_res");
    lhs->ty = rhs->ty;
  }

  return is_real;
}
static rval_t* codegen_gen_add(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!codegen_process_reals(codegen, lhs, rhs))
    val = LLVMBuildAdd(codegen->builder, lhs->val, rhs->val, "add_res");
  else
    val = LLVMBuildFAdd(codegen->builder, lhs->val, rhs->val, "fadd_res");
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_sub(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!codegen_process_reals(codegen, lhs, rhs))
    val = LLVMBuildSub(codegen->builder, lhs->val, rhs->val, "sub_res");
  else {
    val = LLVMBuildFSub(codegen->builder, lhs->val, rhs->val, "fsub_res");
  }
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_mul(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!codegen_process_reals(codegen, lhs, rhs))
    val = LLVMBuildMul(codegen->builder, lhs->val, rhs->val, "mul_res");
  else
    val = LLVMBuildFMul(codegen->builder, lhs->val, rhs->val, "fmul_res");
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_eq(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!codegen_process_reals(codegen, lhs, rhs))
    val = LLVMBuildICmp(codegen->builder, LLVMIntEQ, lhs->val, rhs->val, "eq_res");
  else
    val = LLVMBuildFCmp(codegen->builder, LLVMRealOEQ, lhs->val, rhs->val, "feq_res");
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_ne(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!codegen_process_reals(codegen, lhs, rhs))
    val = LLVMBuildICmp(codegen->builder, LLVMIntNE, lhs->val, rhs->val, "ne_res");
  else
    val = LLVMBuildFCmp(codegen->builder, LLVMRealONE, lhs->val, rhs->val, "fne_res");
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_less(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!codegen_process_reals(codegen, lhs, rhs))
    val = LLVMBuildICmp(codegen->builder, LLVMIntSLE, lhs->val, rhs->val, "less_res");
  else
    val = LLVMBuildFCmp(codegen->builder, LLVMRealOLT, lhs->val, rhs->val, "fless_res");
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_grtr(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!codegen_process_reals(codegen, lhs, rhs))
    val = LLVMBuildICmp(codegen->builder, LLVMIntSGT, lhs->val, rhs->val, "grtr_res");
  else
    val = LLVMBuildFCmp(codegen->builder, LLVMRealOGT, lhs->val, rhs->val, "fgrtr_res");
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_le(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!codegen_process_reals(codegen, lhs, rhs))
    val = LLVMBuildICmp(codegen->builder, LLVMIntSLE, lhs->val, rhs->val, "le_res");
  else
    val = LLVMBuildFCmp(codegen->builder, LLVMRealOLE, lhs->val, rhs->val, "fle_res");
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_ge(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = NULL;
  if (!codegen_process_reals(codegen, lhs, rhs))
    val = LLVMBuildICmp(codegen->builder, LLVMIntSGE, lhs->val, rhs->val, "ge_res");
  else
    val = LLVMBuildFCmp(codegen->builder, LLVMRealOGE, lhs->val, rhs->val, "fge_res");
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_and(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildAnd(codegen->builder, lhs->val, rhs->val, "and_res");
  return create_rval(val, lhs->ty);
}
static rval_t* codegen_gen_or(codegen_t* codegen, rval_t* lhs, rval_t* rhs) {
  unit_t* val = LLVMBuildOr(codegen->builder, lhs->val, rhs->val, "or_res");
  return create_rval(val, lhs->ty);
}

static lval_t* codegen_gen_dot(codegen_t* codegen, bin_ast_t* bin_ast) {
  lval_t* lhs = (lval_t*) codegen_gen(codegen, bin_ast->lhs);
  var_ast_t* var_ast = (var_ast_t*) bin_ast->rhs;
  char* field_name = var_ast->name;

  int field = codegen_structs_get(codegen, LLVMGetStructName(lhs->ty), field_name);
  unit_t* field_ty = codegen_structs_get_ty(codegen, LLVMGetStructName(lhs->ty), field_name);
  unit_t* ptr = LLVMBuildStructGEP2(codegen->builder, lhs->ty, lhs->ptr, field, "gep_res");
  unit_t* val = LLVMBuildLoad2(codegen->builder, field_ty, ptr, "gep_val");
  return create_lval(val, lhs->ty, ptr);
}

unit_t* codegen_gen_bin(codegen_t* codegen, bin_ast_t* bin_ast) {
  if (bin_ast->op == OP_DOT)
    return codegen_gen_dot(codegen, bin_ast);

  unit_t* lhs = (rval_t*) codegen_gen(codegen, bin_ast->lhs);
  unit_t* rhs = (rval_t*) codegen_gen(codegen, bin_ast->rhs);
  if (bin_ast->op == OP_ASSIGN) {
    return codegen_gen_assign(codegen, lhs, rhs);
  } else if (bin_ast->op == OP_ADD)
    return codegen_gen_add(codegen, lhs, rhs);
  else if (bin_ast->op == OP_SUB)
    return codegen_gen_sub(codegen, lhs, rhs);
  else if (bin_ast->op == OP_MUL)
    return codegen_gen_mul(codegen, lhs, rhs);
  else if (bin_ast->op == OP_DIV)
    return NULL;
  else if (bin_ast->op == OP_EQ)
    return codegen_gen_eq(codegen, lhs, rhs);
  else if (bin_ast->op == OP_NE)
    return codegen_gen_ne(codegen, lhs, rhs);
  else if (bin_ast->op == OP_LESS)
    return codegen_gen_less(codegen, lhs, rhs);
  else if (bin_ast->op == OP_GRTR)
    return codegen_gen_grtr(codegen, lhs, rhs);
  else if (bin_ast->op == OP_LE)
    return codegen_gen_le(codegen, lhs, rhs);
  else if (bin_ast->op == OP_GE)
    return codegen_gen_ge(codegen, lhs, rhs);

  else if (bin_ast->op == OP_AND)
    return codegen_gen_and(codegen, lhs, rhs);
  else if (bin_ast->op == OP_OR)
    return codegen_gen_or(codegen, lhs, rhs);

  else if (bin_ast->op == OP_BWAND)
    return codegen_gen_and(codegen, lhs, rhs);
  else if (bin_ast->op == OP_BWOR)
    return codegen_gen_or(codegen, lhs, rhs);

  return NULL;
}
