#pragma once

#include <string.h>
#include "../src/codegen.h"
#include "../src/lexer.h"
#include "../src/parser.h"
#include "test.h"

#include <llvm-c/Core.h>

TEST(codegen, testy) {
  lexer_set_code(
    "func fib(n: i32): i32 { let a: i32; ret a; }"
  );
  codegen_init();
  codegen(parser_parse());
  //LLVMDumpModule(module);

  return 0;
}

TESTS(codegen) {
  test_run(codegen, testy);
}
