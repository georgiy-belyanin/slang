#include "func_codegen.h"

#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_func(codegen_t* codegen, func_ast_t* func_ast) {
  codegen_gen(codegen, func_ast->decl);
  codegen_gen(codegen, func_ast->body);

  return NULL;
}
