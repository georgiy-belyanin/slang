#pragma once

#include <string.h>
#include "../src/lexer.h"
#include "../src/tokens.h"
#include "test.h"

TEST(lexer, func) {
  lexer_set_code("func");
  assert(lexer_next_token() == TOKEN_FUNC);
  return 0;
}
TEST(lexer, let) {
  lexer_set_code("let");
  assert(lexer_next_token() == TOKEN_LET);
  return 0;
}
TEST(lexer, ret) {
  lexer_set_code("ret");
  assert(lexer_next_token() == TOKEN_RET);
  return 0;
}
TEST(lexer, ext) {
  lexer_set_code("ext");
  assert(lexer_next_token() == TOKEN_EXT);
  return 0;
}
TEST(lexer, if) {
  lexer_set_code("if");
  assert(lexer_next_token() == TOKEN_IF);
  return 0;
}
TEST(lexer, while) {
  lexer_set_code("while");
  assert(lexer_next_token() == TOKEN_WHILE);
  return 0;
}
TEST(lexer, loop) {
  lexer_set_code("loop");
  assert(lexer_next_token() == TOKEN_LOOP);
  return 0;
}

TEST(lexer, colon) {
  lexer_set_code(":");
  assert(lexer_next_token() == TOKEN_COLON);
  return 0;
}
TEST(lexer, semi) {
  lexer_set_code(";");
  assert(lexer_next_token() == TOKEN_SEMI);
  return 0;
}
TEST(lexer, dot) {
  lexer_set_code(".");
  assert(lexer_next_token() == TOKEN_DOT);
  return 0;
}
TEST(lexer, comma) {
  lexer_set_code(",");
  assert(lexer_next_token() == TOKEN_COMMA);
  return 0;
}
TEST(lexer, lparen) {
  lexer_set_code("(");
  assert(lexer_next_token() == TOKEN_LPAREN);
  return 0;
}
TEST(lexer, rparen) {
  lexer_set_code(")");
  assert(lexer_next_token() == TOKEN_RPAREN);
  return 0;
}
TEST(lexer, lbracket) {
  lexer_set_code("[");
  assert(lexer_next_token() == TOKEN_LBRACKET);
  return 0;
}
TEST(lexer, rbracket) {
  lexer_set_code("]");
  assert(lexer_next_token() == TOKEN_RBRACKET);
  return 0;
}
TEST(lexer, lblock) {
  lexer_set_code("{");
  assert(lexer_next_token() == TOKEN_LBLOCK);
  return 0;
}
TEST(lexer, rblock) {
  lexer_set_code("}");
  assert(lexer_next_token() == TOKEN_RBLOCK);
  return 0;
}

TEST(lexer, assign) {
  lexer_set_code("=");
  assert(lexer_next_token() == TOKEN_ASSIGN);
  return 0;
}
TEST(lexer, add) {
  lexer_set_code("+");
  assert(lexer_next_token() == TOKEN_ADD);
  return 0;
}
TEST(lexer, sub) {
  lexer_set_code("-");
  assert(lexer_next_token() == TOKEN_SUB);
  return 0;
}
TEST(lexer, mul) {
  lexer_set_code("*");
  assert(lexer_next_token() == TOKEN_MUL);
  return 0;
}
TEST(lexer, div) {
  lexer_set_code("/");
  assert(lexer_next_token() == TOKEN_DIV);
  return 0;
}

TEST(lexer, eq) {
  lexer_set_code("==");
  assert(lexer_next_token() == TOKEN_EQ);
  return 0;
}
TEST(lexer, ne) {
  lexer_set_code("!=");
  assert(lexer_next_token() == TOKEN_NE);
  return 0;
}
TEST(lexer, less) {
  lexer_set_code("<");
  assert(lexer_next_token() == TOKEN_LESS);
  return 0;
}
TEST(lexer, le) {
  lexer_set_code("<=");
  assert(lexer_next_token() == TOKEN_LE);
  return 0;
}
TEST(lexer, grtr) {
  lexer_set_code(">");
  assert(lexer_next_token() == TOKEN_GRTR);
  return 0;
}
TEST(lexer, ge) {
  lexer_set_code(">=");
  assert(lexer_next_token() == TOKEN_GE);
  return 0;
}

TEST(lexer, not) {
  lexer_set_code("!");
  assert(lexer_next_token() == TOKEN_NOT);
  return 0;
}
TEST(lexer, and) {
  lexer_set_code("&&");
  assert(lexer_next_token() == TOKEN_AND);
  return 0;
}
TEST(lexer, or) {
  lexer_set_code("||");
  assert(lexer_next_token() == TOKEN_OR);
  return 0;
}

TEST(lexer, bwand) {
  lexer_set_code("&");
  assert(lexer_next_token() == TOKEN_BWAND);
  return 0;
}
TEST(lexer, bwor) {
  lexer_set_code("|");
  assert(lexer_next_token() == TOKEN_BWOR);
  return 0;
}

TEST(lexer, ident) {
  lexer_set_code("foo bar");
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(strcmp(lexer_get_ident(), "foo") == 0);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(strcmp(lexer_get_ident(), "bar") == 0);
  return 0;
}
TEST(lexer, number) {
  lexer_set_code("23 46");
  assert(lexer_next_token() == TOKEN_NUMBER);
  assert(lexer_get_number() == 23);
  assert(lexer_next_token() == TOKEN_NUMBER);
  assert(lexer_get_number() == 46);
  return 0;
}



TEST(lexer, complex) {
  lexer_set_code(
    "func fib(n: i32): i32 {\n"
    "  if n <= 2 {\n"
    "   ret 1;\n"
    "  }\n"
    "  ret fib(n - 1) + fib(n - 2);\n"
    "}"
  );
  assert(lexer_next_token() == TOKEN_FUNC);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(lexer_next_token() == TOKEN_LPAREN);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(lexer_next_token() == TOKEN_COLON);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(lexer_next_token() == TOKEN_RPAREN);
  assert(lexer_next_token() == TOKEN_COLON);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(lexer_next_token() == TOKEN_LBLOCK);
  assert(lexer_next_token() == TOKEN_IF);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(lexer_next_token() == TOKEN_LE);
  assert(lexer_next_token() == TOKEN_NUMBER);
  assert(lexer_next_token() == TOKEN_LBLOCK);
  assert(lexer_next_token() == TOKEN_RET);
  assert(lexer_next_token() == TOKEN_NUMBER);
  assert(lexer_next_token() == TOKEN_SEMI);
  assert(lexer_next_token() == TOKEN_RBLOCK);
  assert(lexer_next_token() == TOKEN_RET);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(lexer_next_token() == TOKEN_LPAREN);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(lexer_next_token() == TOKEN_SUB);
  assert(lexer_next_token() == TOKEN_NUMBER);
  assert(lexer_next_token() == TOKEN_RPAREN);
  assert(lexer_next_token() == TOKEN_ADD);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(lexer_next_token() == TOKEN_LPAREN);
  assert(lexer_next_token() == TOKEN_IDENT);
  assert(lexer_next_token() == TOKEN_SUB);
  assert(lexer_next_token() == TOKEN_NUMBER);
  assert(lexer_next_token() == TOKEN_RPAREN);
  assert(lexer_next_token() == TOKEN_SEMI);
  assert(lexer_next_token() == TOKEN_RBLOCK);


  return 0;
}

TESTS(lexer) {
  test_run(lexer, func);
  test_run(lexer, let);
  test_run(lexer, ret);
  test_run(lexer, ext);
  test_run(lexer, if);
  test_run(lexer, while);
  test_run(lexer, loop);

  test_run(lexer, colon);
  test_run(lexer, semi);
  test_run(lexer, dot);
  test_run(lexer, comma);
  test_run(lexer, lparen);
  test_run(lexer, rparen);
  test_run(lexer, lbracket);
  test_run(lexer, rbracket);
  test_run(lexer, lblock);
  test_run(lexer, rblock);

  test_run(lexer, assign);
  test_run(lexer, add);
  test_run(lexer, sub);
  test_run(lexer, mul);
  test_run(lexer, div);

  test_run(lexer, eq);
  test_run(lexer, ne);
  test_run(lexer, less);
  test_run(lexer, le);
  test_run(lexer, grtr);
  test_run(lexer, ge);

  test_run(lexer, not);
  test_run(lexer, and);
  test_run(lexer, or);

  test_run(lexer, bwand);
  test_run(lexer, bwor);

  test_run(lexer, ident);
  test_run(lexer, number);

  test_run(lexer, complex);
}
