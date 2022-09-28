#include "codegen.h"

#include <llvm-c/Core.h>
#include "codegen_bin.h"
#include "codegen_body.h"
#include "codegen_call.h"
#include "codegen_func_decl.h"
#include "codegen_func.h"
#include "codegen_if.h"
#include "codegen_let.h"
#include "codegen_loop.h"
#include "codegen_num.h"
#include "codegen_ret.h"
#include "codegen_ty.h"
#include "codegen_var.h"
#include "codegen_while.h"

void codegen_init() {
  context = LLVMContextCreate();
  module = LLVMModuleCreateWithNameInContext("slang_module", context);
  builder = LLVMCreateBuilderInContext(context);

  scope_init();
  tys_init();
}

unit_t* codegen(ast_t* ast) {
  if (ast == NULL)
    return NULL;
  if (ast->type == AST_BIN)
    return codegen_bin((bin_ast_t*) ast);
  else if (ast->type == AST_BODY)
    return codegen_body((body_ast_t*) ast);
  else if (ast->type == AST_CALL)
    return codegen_call((call_ast_t*) ast);
  else if (ast->type == AST_FUNC_DECL)
    return codegen_func_decl((func_decl_ast_t*) ast);
  else if (ast->type == AST_FUNC)
    return codegen_func((func_ast_t*) ast);
  else if (ast->type == AST_IF)
    return codegen_if((if_ast_t*) ast);
  else if (ast->type == AST_LET)
    return codegen_let((let_ast_t*) ast);
  else if (ast->type == AST_LOOP)
    return codegen_loop((loop_ast_t*) ast);
  else if (ast->type == AST_NUM)
    return codegen_num((num_ast_t*) ast);
  else if (ast->type == AST_RET)
    return codegen_ret((ret_ast_t*) ast);
  else if (ast->type == AST_TY)
    return codegen_ty((ty_ast_t*) ast);
  else if (ast->type == AST_VAR)
    return codegen_var((var_ast_t*) ast);
  else if (ast->type == AST_WHILE)
    return codegen_while((while_ast_t*) ast);
  return NULL;
}
