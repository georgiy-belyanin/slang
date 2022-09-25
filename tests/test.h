#pragma once

#include "../src/utils.h"

static int ok = 0;
static int failed = 0;

#define success(...) printf("\x1B[32m" __VA_ARGS__ "\x1B[0m")
#define fail(...) printf("\x1B[31m" __VA_ARGS__ "\x1B[0m")

#define assert(condition) \
  do { \
    if (!(condition)) { \
      log(#condition " (line: %d) ", __LINE__) ; \
      return -1; \
    } \
  } while(0)

#define TEST(module, name) int test_ ## module ## _ ## name()
#define test_run(module, name) \
  do { \
    log("\t- Running test " #name ": "); \
    if (test_ ## module ## _ ## name()) { \
      failed++; \
      fail("failed\n"); \
    } else { \
      ok++; \
      success("ok\n"); \
    } \
  } while(0)

#define TESTS(module) void tests_ ## module()
#define tests_run(module) \
  do { \
    info("Running test module " #module "\n"); \
    tests_ ## module(); \
  } while(0)

#define tests_info() info("Executed %d tests: %d success, %d failed\n", ok + failed, ok, failed)
