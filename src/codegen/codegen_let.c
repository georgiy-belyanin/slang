#include "codegen_let.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_let(let_ast_t* let_ast) {
  char* name = let_ast->name;

  unit_t* ty = codegen(let_ast->ty);
  unit_t* val = LLVMBuildAlloca(builder, ty, name);

  scope_set(name, create_rval(val, ty));
  return create_lval(NULL, ty, val);
}
