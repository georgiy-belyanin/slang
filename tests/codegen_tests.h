#pragma once

#include <string.h>
#include "../src/codegen.h"
#include "../src/lexer.h"
#include "../src/parser.h"
#include "test.h"

TEST(codegen, testy) {
  lexer_t* lexer = create_lexer(
    "func fib(n: i32): i32 {\n"
    "  if n <= 2 ret 1; \n" 
    "  ret fib(n - 1.2) + fib(n - 2); \n"
    "}"
  );
  parser_t* parser = create_parser(lexer);

  codegen_init();
  codegen(parser_parse(parser));
  LLVMDumpModule(module);

  return 0;
}

TESTS(codegen) {
  test_run(codegen, testy);
}
