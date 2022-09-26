#include "ast.h"

#include "bin_ast.h"
#include "body_ast.h"
#include "call_ast.h"
#include "func_ast.h"
#include "func_decl_ast.h"
#include "if_ast.h"
#include "let_ast.h"
#include "loop_ast.h"
#include "num_ast.h"
#include "ret_ast.h"
#include "stmt_ast.h"
#include "ty_ast.h"
#include "var_ast.h"
#include "while_ast.h"

void destroy_ast(ast_t* ast) {
  if (ast->type == AST_BIN)
    destroy_bin_ast((bin_ast_t*) ast);
  else if (ast->type == AST_BODY)
    destroy_body_ast((body_ast_t*) ast);
  else if (ast->type == AST_CALL)
    destroy_call_ast((call_ast_t*) ast);
  else if (ast->type == AST_FUNC)
    destroy_func_ast((func_ast_t*) ast);
  else if (ast->type == AST_FUNC_DECL)
    destroy_func_decl_ast((func_decl_ast_t*) ast);
  else if (ast->type == AST_IF)
    destroy_if_ast((if_ast_t*) ast);
  else if (ast->type == AST_LET)
    destroy_let_ast((let_ast_t*) ast);
  else if (ast->type == AST_LOOP)
    destroy_loop_ast((loop_ast_t*) ast);
  else if (ast->type == AST_NUM)
    destroy_num_ast((num_ast_t*) ast);
  // else if (ast->type == AST_WHILE)
  //   destroy_while_ast(ast);
  // else if (ast->type == AST_STMT)
  //   destroy_ret_ast(ast);
  else if (ast->type == AST_RET)
    destroy_ret_ast((ret_ast_t*) ast);
  else if (ast->type == AST_TY)
    destroy_ty_ast((ty_ast_t*) ast);
  else if (ast->type == AST_VAR)
    destroy_var_ast((var_ast_t*) ast);
}