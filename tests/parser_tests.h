#pragma once

#include <string.h>
#include "../src/ast.h"
#include "../src/parser.h"
#include "test.h"

TEST(parser, func_decl) {
  lexer_set_code(
    "func fib(n: i32): i32 { }"
  );

  ast_t* ast = parser_parse();
  func_ast_t* func_ast = (func_ast_t*) ast;
  func_decl_ast_t* func_decl_ast = (func_decl_ast_t*) func_ast->decl;
  ty_ast_t* ty_ast = (ty_ast_t*) func_decl_ast->ty;
  char* arg_name_ast = func_decl_ast->arg_names[0];
  ty_ast_t* arg_ty_ast = (ty_ast_t*) func_decl_ast->arg_tys[0];

  assert(ast->type == AST_FUNC);
  assert(strcmp(func_decl_ast->name, "fib") == 0);
  assert(strcmp(ty_ast->name, "i32") == 0);
  assert(func_decl_ast->arg_count == 1);
  assert(strcmp(arg_name_ast, "n") == 0);
  assert(strcmp(arg_ty_ast->name, "i32") == 0);

  return 0;
}
TEST(parser, let) {
  lexer_set_code(
    "func fib(n: i32): i32 { let foo: i32; }"
  );

  ast_t* ast = parser_parse();
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  let_ast_t* let_ast = (let_ast_t*) body_ast->stmts[0];
  ty_ast_t* ty_ast = (ty_ast_t*) let_ast->ty;

  assert(let_ast->type == AST_LET);
  assert(strcmp(let_ast->name, "foo") == 0);
  assert(strcmp(ty_ast->name, "i32") == 0);

  return 0;
}
TEST(parser, ret) {
  lexer_set_code(
    "func fib(n: i32): i32 { ret 10; }"
  );

  ast_t* ast = parser_parse();
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast->stmts[0];

  assert(ret_ast->type == AST_RET);

  return 0;
}
TEST(parser, num) {
  lexer_set_code(
    "func fib(n: i32): i32 { ret 10; }"
  );

  ast_t* ast = parser_parse();
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast->stmts[0];
  num_ast_t* num_ast = (num_ast_t*) ret_ast->val;

  assert(num_ast->type == AST_NUM);
  assert(num_ast->val == 10);

  return 0;
}
TEST(parser, call) {
  lexer_set_code(
    "func fib(n: i32): i32 { ret fib(1); }"
  );

  ast_t* ast = parser_parse();
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast->stmts[0];
  call_ast_t* call_ast = (call_ast_t*) ret_ast->val;
  num_ast_t* arg_ast = (num_ast_t*) call_ast->args[0];

  assert(call_ast->type == AST_CALL);
  assert(strcmp(call_ast->callee, "fib") == 0);
  assert(call_ast->arg_count == 1);
  assert(arg_ast->val == 1);

  return 0;
}

TESTS(parser) {
  test_run(parser, func_decl);
  test_run(parser, let);
  test_run(parser, ret);
  test_run(parser, num);
  test_run(parser, call);
}

