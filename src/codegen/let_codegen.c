#include "let_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_let(codegen_t* codegen, let_ast_t* let_ast) {
  char* name = let_ast->name;

  unit_t* ty = codegen_gen(codegen, let_ast->ty);
  unit_t* val = LLVMBuildAlloca(codegen->builder, ty, name);

  codegen_scope_set(codegen, name, create_rval(val, ty));
  return create_lval(NULL, ty, val);
}
