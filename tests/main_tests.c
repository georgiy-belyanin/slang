#include "test.h"

#include "lexer_tests.h"

int main() {
  tests_run(lexer);
  tests_info();
  return 0;
}