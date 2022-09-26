#include "codegen_body.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_body(body_ast_t* body_ast) {
  scope_next();
  for(int i = 0; i < body_ast->stmt_count; i++)
    codegen(body_ast->stmts[i]);
  scope_prev();

  return NULL;
}
