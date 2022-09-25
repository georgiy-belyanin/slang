#include "hashmap_tests.h"
#include "lexer_tests.h"
#include "parser_tests.h"

int main() {
  tests_run(hashmap);
  tests_run(lexer);
  tests_run(parser);
  tests_info();
  return 0;
}
