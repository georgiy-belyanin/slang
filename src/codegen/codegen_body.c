#include "codegen_body.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_body(body_ast_t* body_ast) {
  for(int i = 0; i < body_ast->stmt_count; i++)
    codegen(body_ast->stmts[i]);
  return NULL;
}
