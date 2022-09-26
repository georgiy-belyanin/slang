#include "codegen_let.h"

#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_let(let_ast_t* let_ast) {
  char* name = let_ast->name;
  ast_t* ty = let_ast->ty;

  unit_t* val = LLVMBuildAlloca(builder, codegen(ty), name);
  scope_set(name, val);
  return val;
}
