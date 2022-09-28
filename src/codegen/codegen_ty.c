#include "codegen_ty.h"

#include <string.h>
#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_ty(ty_ast_t* ty_ast) {
  return tys_get(ty_ast->name);
}
