#pragma args

#include <string.h>
#include "../src/utils.h"
#include "test.h"

TEST(args, files) {
  args_t* args = create_args(3, (char*[3]) { "slang", "1.sl", "2.sl" });

  assert(args_file_get_count(args) == 2);
  assert(strcmp(args_file_get(args, 0), "1.sl") == 0);
  assert(strcmp(args_file_get(args, 1), "2.sl") == 0);

  destroy_args(args);

  return 0;
}
TEST(args, ir) {
  args_t* args = create_args(2, (char*[2]) { "slang", "-i" });
  assert(args_flags_get(args, FLAG_TYPE_IR) == (char*) 1);
  destroy_args(args);

  args = create_args(2, (char*[2]) { "slang", "--ir" });
  assert(args_flags_get(args, FLAG_TYPE_IR) == (char*) 1);
  destroy_args(args);

  return 0;
}
TEST(args, help) {
  args_t* args = create_args(2, (char*[2]) { "slang", "-h" });
  assert(args_flags_get(args, FLAG_TYPE_HELP) == (char*) 1);
  destroy_args(args);

  args = create_args(2, (char*[2]) { "slang", "--help" });
  assert(args_flags_get(args, FLAG_TYPE_HELP) == (char*) 1);
  destroy_args(args);

  return 0;
}
TEST(args, out) {
  args_t* args = create_args(2, (char*[2]) { "slang", "-o=1.o" });
  assert(strcmp(args_flags_get(args, FLAG_TYPE_OUT), "1.o") == 0);
  destroy_args(args);

  args = create_args(2, (char*[2]) { "slang", "--out==1.o" });
  assert(strcmp(args_flags_get(args, FLAG_TYPE_OUT), "1.o") == 0);
  destroy_args(args);

  return 0;
}
TEST(args, default) {
  args_t* args = create_args(2, (char*[3]) { "slang", "1.sl" });

  assert(args_flags_get(args, FLAG_TYPE_HELP) == (char*) 0);
  assert(args_flags_get(args, FLAG_TYPE_IR) == (char*) 0);
  assert(strcmp(args_flags_get(args, FLAG_TYPE_OUT), "out.o") == 0);

  destroy_args(args);

  return 0;
}

TESTS(args) {
  test_run(args, files);
  test_run(args, ir);
  test_run(args, help);
  test_run(args, out);
  test_run(args, default);
}