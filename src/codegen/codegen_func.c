#include "codegen_bin.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_func(func_ast_t* func_ast) {
  scope_next();
  codegen(func_ast->decl);
  codegen(func_ast->body);
  scope_prev();
  
  return NULL;
}
