#include "ty_codegen.h"

#include <string.h>
#include <llvm-c/Core.h>

unit_t* codegen_gen_ty(codegen_t* codegen, ty_ast_t* ty_ast) {
  return codegen_tys_get(codegen, ty_ast->name);
}
