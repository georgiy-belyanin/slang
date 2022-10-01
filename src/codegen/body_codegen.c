#include "body_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_body(codegen_t* codegen, body_ast_t* body_ast) {
  codegen_scope_next(codegen);
  for(int i = 0; i < body_ast->stmt_count; i++)
    codegen_gen(codegen, body_ast->stmts[i]);
  codegen_scope_prev(codegen);

  return NULL;
}
