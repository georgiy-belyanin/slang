#include "public.h"

#include <stdlib.h>
#include "bin_codegen.h"
#include "body_codegen.h"
#include "call_codegen.h"
#include "func_decl_codegen.h"
#include "func_codegen.h"
#include "if_codegen.h"
#include "int_codegen.h"
#include "let_codegen.h"
#include "loop_codegen.h"
#include "real_codegen.h"
#include "ret_codegen.h"
#include "ty_codegen.h"
#include "var_codegen.h"
#include "while_codegen.h"

codegen_t* create_codegen() {
  codegen_t* codegen = malloc(sizeof(codegen_t));
  codegen->context = LLVMContextCreate();
  codegen->module = LLVMModuleCreateWithNameInContext("slang_module", codegen->context);
  codegen->builder = LLVMCreateBuilderInContext(codegen->context);

  codegen->scope = create_scope();
  codegen->tys = create_tys(codegen->context);

  return codegen;
}
void destroy_codegen(codegen_t* codegen) {
  destroy_scope(codegen->scope);
  destroy_tys(codegen->tys);
  free(codegen);
}

unit_t* codegen_gen(codegen_t* codegen, ast_t* ast) {
  if (ast == NULL)
    return NULL;
  if (ast->type == AST_BIN)
    return codegen_gen_bin(codegen, (bin_ast_t*) ast);
  else if (ast->type == AST_BODY)
    return codegen_gen_body(codegen, (body_ast_t*) ast);
  else if (ast->type == AST_CALL)
    return codegen_gen_call(codegen, (call_ast_t*) ast);
  else if (ast->type == AST_FUNC_DECL)
    return codegen_gen_func_decl(codegen, (func_decl_ast_t*) ast);
  else if (ast->type == AST_FUNC)
    return codegen_gen_func(codegen, (func_ast_t*) ast);
  else if (ast->type == AST_IF)
    return codegen_gen_if(codegen, (if_ast_t*) ast);
  else if (ast->type == AST_INT)
    return codegen_gen_int(codegen, (int_ast_t*) ast);
  else if (ast->type == AST_LET)
    return codegen_gen_let(codegen, (let_ast_t*) ast);
  else if (ast->type == AST_LOOP)
    return codegen_gen_loop(codegen, (loop_ast_t*) ast);
  else if (ast->type == AST_REAL)
    return codegen_gen_real(codegen, (real_ast_t*) ast);
  else if (ast->type == AST_RET)
    return codegen_gen_ret(codegen, (ret_ast_t*) ast);
  else if (ast->type == AST_TY)
    return codegen_gen_ty(codegen, (ty_ast_t*) ast);
  else if (ast->type == AST_VAR)
    return codegen_gen_var(codegen, (var_ast_t*) ast);
  else if (ast->type == AST_WHILE)
    return codegen_gen_while(codegen, (while_ast_t*) ast);
  return NULL;
}

void codegen_dump(codegen_t* codegen) {
  LLVMDumpModule(codegen->module);
}
