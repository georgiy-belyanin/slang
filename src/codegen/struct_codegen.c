#include "struct_codegen.h"

#include <stdlib.h>
#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_struct(codegen_t* codegen, struct_ast_t* struct_ast) {
  body_ast_t* body_ast = (body_ast_t*) struct_ast->body;
  int ty_count = body_ast->stmt_count;
  unit_t** tys = calloc(sizeof(unit_t*), ty_count);

  for(int i = 0; i < ty_count; i++) {
    let_ast_t* let_ast = (let_ast_t*) body_ast->stmts[i];

    tys[i] = codegen_gen(codegen, let_ast->ty);
  }

  codegen_tys_set(codegen, struct_ast->name, LLVMStructTypeInContext(codegen->context, (LLVMTypeRef*) tys, ty_count, 0));
  return NULL;
}
