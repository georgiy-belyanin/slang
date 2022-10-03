#pragma once

#include <string.h>
#include "../src/lexer.h"
#include "../src/tokens.h"
#include "test.h"

TEST(lexer, trait) {
  lexer_t* lexer = create_lexer("trait");
  assert(lexer_next_token(lexer) == TOKEN_TRAIT);
  return 0;
}
TEST(lexer, struct) {
  lexer_t* lexer = create_lexer("struct");
  assert(lexer_next_token(lexer) == TOKEN_STRUCT);
  return 0;
}
TEST(lexer, func) {
  lexer_t* lexer = create_lexer("func");
  assert(lexer_next_token(lexer) == TOKEN_FUNC);
  return 0;
}
TEST(lexer, let) {
  lexer_t* lexer = create_lexer("let");
  assert(lexer_next_token(lexer) == TOKEN_LET);
  return 0;
}
TEST(lexer, ret) {
  lexer_t* lexer = create_lexer("ret");
  assert(lexer_next_token(lexer) == TOKEN_RET);
  return 0;
}
TEST(lexer, ext) {
  lexer_t* lexer = create_lexer("ext");
  assert(lexer_next_token(lexer) == TOKEN_EXT);
  return 0;
}
TEST(lexer, if) {
  lexer_t* lexer = create_lexer("if");
  assert(lexer_next_token(lexer) == TOKEN_IF);
  return 0;
}
TEST(lexer, else) {
  lexer_t* lexer = create_lexer("else");
  assert(lexer_next_token(lexer) == TOKEN_ELSE);
  return 0;
}
TEST(lexer, while) {
  lexer_t* lexer = create_lexer("while");
  assert(lexer_next_token(lexer) == TOKEN_WHILE);
  return 0;
}
TEST(lexer, loop) {
  lexer_t* lexer = create_lexer("loop");
  assert(lexer_next_token(lexer) == TOKEN_LOOP);
  return 0;
}
TEST(lexer, new) {
  lexer_t* lexer = create_lexer("new");
  assert(lexer_next_token(lexer) == TOKEN_NEW);
  return 0;
}
TEST(lexer, del) {
  lexer_t* lexer = create_lexer("del");
  assert(lexer_next_token(lexer) == TOKEN_DEL);
  return 0;
}

TEST(lexer, true) {
  lexer_t* lexer = create_lexer("true");
  assert(lexer_next_token(lexer) == TOKEN_TRUE);
  return 0;
}
TEST(lexer, false) {
  lexer_t* lexer = create_lexer("false");
  assert(lexer_next_token(lexer) == TOKEN_FALSE);
  return 0;
}

TEST(lexer, colon) {
  lexer_t* lexer = create_lexer(":");
  assert(lexer_next_token(lexer) == TOKEN_COLON);
  return 0;
}
TEST(lexer, semi) {
  lexer_t* lexer = create_lexer(";");
  assert(lexer_next_token(lexer) == TOKEN_SEMI);
  return 0;
}
TEST(lexer, dot) {
  lexer_t* lexer = create_lexer(".");
  assert(lexer_next_token(lexer) == TOKEN_DOT);
  return 0;
}
TEST(lexer, comma) {
  lexer_t* lexer = create_lexer(",");
  assert(lexer_next_token(lexer) == TOKEN_COMMA);
  return 0;
}
TEST(lexer, lparen) {
  lexer_t* lexer = create_lexer("(");
  assert(lexer_next_token(lexer) == TOKEN_LPAREN);
  return 0;
}
TEST(lexer, rparen) {
  lexer_t* lexer = create_lexer(")");
  assert(lexer_next_token(lexer) == TOKEN_RPAREN);
  return 0;
}
TEST(lexer, lblock) {
  lexer_t* lexer = create_lexer("{");
  assert(lexer_next_token(lexer) == TOKEN_LBLOCK);
  return 0;
}
TEST(lexer, rblock) {
  lexer_t* lexer = create_lexer("}");
  assert(lexer_next_token(lexer) == TOKEN_RBLOCK);
  return 0;
}
TEST(lexer, lbracket) {
  lexer_t* lexer = create_lexer("[");
  assert(lexer_next_token(lexer) == TOKEN_LBRACKET);
  return 0;
}
TEST(lexer, rbracket) {
  lexer_t* lexer = create_lexer("]");
  assert(lexer_next_token(lexer) == TOKEN_RBRACKET);
  return 0;
}
TEST(lexer, uptr) {
  lexer_t* lexer = create_lexer("@");
  assert(lexer_next_token(lexer) == TOKEN_UPTR);
  return 0;
}
TEST(lexer, sptr) {
  lexer_t* lexer = create_lexer("~");
  assert(lexer_next_token(lexer) == TOKEN_SPTR);
  return 0;
}


TEST(lexer, assign) {
  lexer_t* lexer = create_lexer("=");
  assert(lexer_next_token(lexer) == TOKEN_ASSIGN);
  return 0;
}
TEST(lexer, add) {
  lexer_t* lexer = create_lexer("+");
  assert(lexer_next_token(lexer) == TOKEN_ADD);
  return 0;
}
TEST(lexer, sub) {
  lexer_t* lexer = create_lexer("-");
  assert(lexer_next_token(lexer) == TOKEN_SUB);
  return 0;
}
TEST(lexer, mul) {
  lexer_t* lexer = create_lexer("*");
  assert(lexer_next_token(lexer) == TOKEN_MUL);
  return 0;
}
TEST(lexer, div) {
  lexer_t* lexer = create_lexer("/");
  assert(lexer_next_token(lexer) == TOKEN_DIV);
  return 0;
}

TEST(lexer, eq) {
  lexer_t* lexer = create_lexer("==");
  assert(lexer_next_token(lexer) == TOKEN_EQ);
  return 0;
}
TEST(lexer, ne) {
  lexer_t* lexer = create_lexer("!=");
  assert(lexer_next_token(lexer) == TOKEN_NE);
  return 0;
}
TEST(lexer, less) {
  lexer_t* lexer = create_lexer("<");
  assert(lexer_next_token(lexer) == TOKEN_LESS);
  return 0;
}
TEST(lexer, le) {
  lexer_t* lexer = create_lexer("<=");
  assert(lexer_next_token(lexer) == TOKEN_LE);
  return 0;
}
TEST(lexer, grtr) {
  lexer_t* lexer = create_lexer(">");
  assert(lexer_next_token(lexer) == TOKEN_GRTR);
  return 0;
}
TEST(lexer, ge) {
  lexer_t* lexer = create_lexer(">=");
  assert(lexer_next_token(lexer) == TOKEN_GE);
  return 0;
}

TEST(lexer, not) {
  lexer_t* lexer = create_lexer("!");
  assert(lexer_next_token(lexer) == TOKEN_NOT);
  return 0;
}
TEST(lexer, and) {
  lexer_t* lexer = create_lexer("&&");
  assert(lexer_next_token(lexer) == TOKEN_AND);
  return 0;
}
TEST(lexer, or) {
  lexer_t* lexer = create_lexer("||");
  assert(lexer_next_token(lexer) == TOKEN_OR);
  return 0;
}

TEST(lexer, bwand) {
  lexer_t* lexer = create_lexer("&");
  assert(lexer_next_token(lexer) == TOKEN_BWAND);
  return 0;
}
TEST(lexer, bwor) {
  lexer_t* lexer = create_lexer("|");
  assert(lexer_next_token(lexer) == TOKEN_BWOR);
  return 0;
}

TEST(lexer, ident) {
  lexer_t* lexer = create_lexer("foo bar");
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(strcmp(lexer_get_ident(lexer), "foo") == 0);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(strcmp(lexer_get_ident(lexer), "bar") == 0);
  return 0;
}
TEST(lexer, int) {
  lexer_t* lexer = create_lexer("23 46");
  assert(lexer_next_token(lexer) == TOKEN_INT);
  assert(lexer_get_int(lexer) == 23);
  assert(lexer_next_token(lexer) == TOKEN_INT);
  assert(lexer_get_int(lexer) == 46);
  return 0;
}
TEST(lexer, real) {
  lexer_t* lexer = create_lexer("42.13 23.5");
  assert(lexer_next_token(lexer) == TOKEN_REAL);
  assert(lexer_get_real(lexer) == 42.13);
  assert(lexer_next_token(lexer) == TOKEN_REAL);
  assert(lexer_get_real(lexer) == 23.5);
  return 0;
}
TEST(lexer, str) {
  lexer_t* lexer = create_lexer("\"Hey\"");
  assert(lexer_next_token(lexer) == TOKEN_STR);
  assert(lexer_get_real(lexer) == 42.13);
  assert(lexer_next_token(lexer) == TOKEN_REAL);
  assert(lexer_get_real(lexer) == 23.5);
  return 0;
}



TEST(lexer, complex) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 {\n"
    "  if n <= 2 {\n"
    "   ret 1;\n"
    "  }\n"
    "  ret fib(n - 1) + fib(n - 2);\n"
    "}"
  );
  assert(lexer_next_token(lexer) == TOKEN_FUNC);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(lexer_next_token(lexer) == TOKEN_LPAREN);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(lexer_next_token(lexer) == TOKEN_COLON);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(lexer_next_token(lexer) == TOKEN_RPAREN);
  assert(lexer_next_token(lexer) == TOKEN_COLON);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(lexer_next_token(lexer) == TOKEN_LBLOCK);
  assert(lexer_next_token(lexer) == TOKEN_IF);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(lexer_next_token(lexer) == TOKEN_LE);
  assert(lexer_next_token(lexer) == TOKEN_INT);
  assert(lexer_next_token(lexer) == TOKEN_LBLOCK);
  assert(lexer_next_token(lexer) == TOKEN_RET);
  assert(lexer_next_token(lexer) == TOKEN_INT);
  assert(lexer_next_token(lexer) == TOKEN_SEMI);
  assert(lexer_next_token(lexer) == TOKEN_RBLOCK);
  assert(lexer_next_token(lexer) == TOKEN_RET);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(lexer_next_token(lexer) == TOKEN_LPAREN);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(lexer_next_token(lexer) == TOKEN_SUB);
  assert(lexer_next_token(lexer) == TOKEN_INT);
  assert(lexer_next_token(lexer) == TOKEN_RPAREN);
  assert(lexer_next_token(lexer) == TOKEN_ADD);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(lexer_next_token(lexer) == TOKEN_LPAREN);
  assert(lexer_next_token(lexer) == TOKEN_IDENT);
  assert(lexer_next_token(lexer) == TOKEN_SUB);
  assert(lexer_next_token(lexer) == TOKEN_INT);
  assert(lexer_next_token(lexer) == TOKEN_RPAREN);
  assert(lexer_next_token(lexer) == TOKEN_SEMI);
  assert(lexer_next_token(lexer) == TOKEN_RBLOCK);

  //destroy_lexer(lexer);

  return 0;
}

TESTS(lexer) {
  test_run(lexer, trait);
  test_run(lexer, struct);
  test_run(lexer, func);
  test_run(lexer, let);
  test_run(lexer, ret);
  test_run(lexer, ext);
  test_run(lexer, if);
  test_run(lexer, else);
  test_run(lexer, while);
  test_run(lexer, loop);
  test_run(lexer, new);
  test_run(lexer, del);

  test_run(lexer, true);
  test_run(lexer, false);

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

  test_run(lexer, uptr);
  test_run(lexer, sptr);

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
  test_run(lexer, int);
  test_run(lexer, real);
  //test_run(lexer, str);

  test_run(lexer, complex);
}
