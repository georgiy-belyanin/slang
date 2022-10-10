#pragma once

#include <string.h>
#include "../src/ast.h"
#include "../src/parser.h"
#include "test.h"

TEST(parser, func_decl) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { }\n"
    "func log(base: f32, n: f32): f32 { }\n"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast1 = parser_parse(parser);
  func_ast_t* func_ast1 = (func_ast_t*) ast1;
  func_decl_ast_t* func_decl_ast1 = (func_decl_ast_t*) func_ast1->decl;
  ty_ast_t* ty_ast1 = (ty_ast_t*) func_decl_ast1->ty;
  char* arg_name1 = func_decl_ast1->arg_names[0];
  ty_ast_t* arg_ty_ast1 = (ty_ast_t*) func_decl_ast1->arg_tys[0];

  ast_t* ast2 = parser_parse(parser);
  func_ast_t* func_ast2 = (func_ast_t*) ast2;
  func_decl_ast_t* func_decl_ast2 = (func_decl_ast_t*) func_ast2->decl;
  ty_ast_t* ty_ast2 = (ty_ast_t*) func_decl_ast2->ty;
  char* arg_name21 = func_decl_ast2->arg_names[0];
  char* arg_name22 = func_decl_ast2->arg_names[1];
  ty_ast_t* arg_ty_ast21 = (ty_ast_t*) func_decl_ast2->arg_tys[0];
  ty_ast_t* arg_ty_ast22 = (ty_ast_t*) func_decl_ast2->arg_tys[1];

  assert(ast1->type == AST_FUNC);
  assert(strcmp(func_decl_ast1->name, "fib") == 0);
  assert(strcmp(ty_ast1->name, "i32") == 0);
  assert(func_decl_ast1->arg_count == 1);
  assert(strcmp(arg_name1, "n") == 0);
  assert(strcmp(arg_ty_ast1->name, "i32") == 0);

  assert(ast2->type == AST_FUNC);
  assert(strcmp(func_decl_ast2->name, "log") == 0);
  assert(strcmp(ty_ast2->name, "f32") == 0);
  assert(func_decl_ast2->arg_count == 2);
  assert(strcmp(arg_name21, "base") == 0);
  assert(strcmp(arg_ty_ast21->name, "f32") == 0);
  assert(strcmp(arg_name22, "n") == 0);
  assert(strcmp(arg_ty_ast22->name, "f32") == 0);

  destroy_ast(ast1);
  destroy_ast(ast2);
  destroy_parser(parser);
  destroy_lexer(lexer);

  return 0;
}
TEST(parser, struct) {
  lexer_t* lexer = create_lexer(
    "struct a {\n"
      "let foo: i32;\n"
      "let bar: f32;\n"
    "}"
    );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  struct_ast_t* struct_ast = (struct_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) struct_ast->body;
  let_ast_t* let_ast1 = (let_ast_t*) body_ast->stmts[0];
  let_ast_t* let_ast2 = (let_ast_t*) body_ast->stmts[1];
  ty_ast_t* let_ty_ast1 = (ty_ast_t*) let_ast1->ty;
  ty_ast_t* let_ty_ast2 = (ty_ast_t*) let_ast2->ty;

  assert(struct_ast->type == AST_STRUCT);
  assert(strcmp(struct_ast->name, "a") == 0);
  assert(strcmp(let_ast1->name, "i32") == 0);
  assert(strcmp(let_ast2->name, "f32") == 0);
  assert(strcmp(let_ty_ast1->name, "i32") == 0);
  assert(strcmp(let_ty_ast2->name, "f32") == 0);


  destroy_parser(parser);
  destroy_lexer(lexer);

  return 0;
}
TEST(parser, let) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { let foo: i32; }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  let_ast_t* let_ast = (let_ast_t*) body_ast->stmts[0];
  ty_ast_t* ty_ast = (ty_ast_t*) let_ast->ty;

  assert(let_ast->type == AST_LET);
  assert(strcmp(let_ast->name, "foo") == 0);
  assert(strcmp(ty_ast->name, "i32") == 0);

  destroy_ast(ast);

  return 0;
}
TEST(parser, ret) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { ret 10; }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast->stmts[0];

  assert(ret_ast->type == AST_RET);

  destroy_ast(ast);

  return 0;
}
TEST(parser, int) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { ret 10; }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast->stmts[0];
  int_ast_t* int_ast = (int_ast_t*) ret_ast->val;

  assert(int_ast->type == AST_INT);
  assert(int_ast->val == 10);

  destroy_ast(ast);

  return 0;
}
TEST(parser, real) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { ret 10.0; }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast->stmts[0];
  real_ast_t* real_ast = (real_ast_t*) ret_ast->val;

  assert(real_ast->type == AST_REAL);
  assert(real_ast->val == 10.0);

  destroy_ast(ast);

  return 0;
}
TEST(parser, call) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { ret fib(1); }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast->stmts[0];
  call_ast_t* call_ast = (call_ast_t*) ret_ast->val;
  int_ast_t* arg_ast = (int_ast_t*) call_ast->args[0];

  assert(call_ast->type == AST_CALL);
  assert(strcmp(call_ast->callee, "fib") == 0);
  assert(call_ast->arg_count == 1);
  assert(arg_ast->val == 1);

  destroy_ast(ast);

  return 0;
}
TEST(parser, bin) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { ret 2 - n * 4; }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast->stmts[0];
  bin_ast_t* bin_ast1 = (bin_ast_t*) ret_ast->val;
  int_ast_t* int_ast1 = (int_ast_t*) bin_ast1->lhs;
  bin_ast_t* bin_ast2 = (bin_ast_t*) bin_ast1->rhs;
  var_ast_t* var_ast1 = (var_ast_t*) bin_ast2->lhs;
  int_ast_t* int_ast2 = (int_ast_t*) bin_ast2->rhs;

  assert(bin_ast1->type == AST_BIN);
  assert(bin_ast1->op == OP_SUB);
  assert(int_ast1->type == AST_INT);
  assert(int_ast1->val == 2);
  assert(bin_ast2->type == AST_BIN);
  assert(bin_ast2->op == OP_MUL);
  assert(var_ast1->type == AST_VAR);
  assert(strcmp(var_ast1->name, "n") == 0);
  assert(int_ast2->type == AST_INT);
  assert(int_ast2->val == 4);

  destroy_ast(ast);

  return 0;
}
TEST(parser, body) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { let a: i32; a = 10; ret a; }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  let_ast_t* let_ast = (let_ast_t*) body_ast->stmts[0];
  bin_ast_t* bin_ast = (bin_ast_t*) body_ast->stmts[1];
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast->stmts[2];

  assert(let_ast->type == AST_LET);
  assert(bin_ast->type == AST_BIN);
  assert(ret_ast->type == AST_RET);
  
  destroy_ast(ast);

  return 0;
}
TEST(parser, if) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { if n > 10 { ret 10; } }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  if_ast_t* if_ast = (if_ast_t*) body_ast->stmts[0];
  bin_ast_t* bin_ast = (bin_ast_t*) if_ast->cond;
  body_ast_t* then_ast = (body_ast_t*) if_ast->then;
  ret_ast_t* ret_ast = (ret_ast_t*) then_ast->stmts[0];

  assert(if_ast->type == AST_IF);
  assert(bin_ast->type == AST_BIN);
  assert(bin_ast->op == OP_GRTR);
  assert(ret_ast->type == AST_RET);
  
  destroy_ast(ast);

  return 0;
}
TEST(parser, while) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { while n > 10 { ret 10; } }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  while_ast_t* while_ast = (while_ast_t*) body_ast->stmts[0];
  bin_ast_t* bin_ast = (bin_ast_t*) while_ast->cond;
  body_ast_t* body_ast1 = (body_ast_t*) while_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast1->stmts[0];

  assert(while_ast->type == AST_WHILE);
  assert(bin_ast->type == AST_BIN);
  assert(bin_ast->op == OP_GRTR);
  assert(ret_ast->type == AST_RET);
  
  destroy_ast(ast);

  return 0;
}
TEST(parser, loop) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 { loop { ret 10; } }"
  );
  parser_t* parser = create_parser(lexer);

  ast_t* ast = parser_parse(parser);
  func_ast_t* func_ast = (func_ast_t*) ast;
  body_ast_t* body_ast = (body_ast_t*) func_ast->body;
  loop_ast_t* loop_ast = (loop_ast_t*) body_ast->stmts[0];
  body_ast_t* body_ast1 = (body_ast_t*) loop_ast->body;
  ret_ast_t* ret_ast = (ret_ast_t*) body_ast1->stmts[0];

  assert(loop_ast->type == AST_LOOP);
  assert(ret_ast->type == AST_RET);
  
  destroy_ast(ast);

  return 0;
}





TESTS(parser) {
  test_run(parser, func_decl);
  test_run(parser, let);
  test_run(parser, ret);
  test_run(parser, int);
  test_run(parser, real);
  test_run(parser, call);
  test_run(parser, bin);
  test_run(parser, body);
  test_run(parser, if);
  test_run(parser, while);
  test_run(parser, loop);
}

