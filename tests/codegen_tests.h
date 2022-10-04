#pragma once

#include <string.h>
#include "../src/codegen.h"
#include "../src/lexer.h"
#include "../src/parser.h"
#include "test.h"

TEST(codegen, testy) {
  lexer_t* lexer = create_lexer(
    "struct foo {\n"
    "  let bar: *i32;\n"
    "  let buz: i32;\n"
    "}\n"
    "func fib(n: i32): i32 {\n"
    "  let a: foo;\n"
    "  if n <= 2 ret 1; \n" 
    "  ret fib(n - 1.2) + fib(n - 2); \n"
    "}"
  );

  parser_t* parser = create_parser(lexer);
  codegen_t* codegen = create_codegen();

  codegen_gen(codegen, parser_parse(parser));
  codegen_gen(codegen, parser_parse(parser));
  codegen_dump(codegen);

  return 0;
}

TESTS(codegen) {
  test_run(codegen, testy);
}
