#pragma once

#include <string.h>
#include "../src/codegen.h"
#include "../src/lexer.h"
#include "../src/parser.h"
#include "test.h"

TEST(codegen, testy) {
  lexer_set_code(
    "func fib(n: i32): i32 {\n"
    "  if n <= 2 ret 1; \n" 
    "  ret fib(n - 1) + fib(n - 2); \n"
    "}"
  );
  codegen_init();
  codegen(parser_parse());
  LLVMDumpModule(module);

  return 0;
}

TESTS(codegen) {
  test_run(codegen, testy);
}
