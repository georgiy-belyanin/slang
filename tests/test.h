#pragma once

#include <stdio.h>

int ok = 0;
int failed = 0;

#define info(...) printf(__VA_ARGS__)
#define success(...) printf("\x1B[32m" __VA_ARGS__ "\x1B[0m")
#define error(...) printf("\x1B[31m" __VA_ARGS__ "\x1B[0m")

#define assert(condition) \
  do { \
    if (!(condition)) { \
      info(#condition " (line: %d) ", __LINE__) ; \
      return -1; \
    } \
  } while(0)

#define TEST(module, name) int test_ ## module ## _ ## name()
#define test_run(module, name) \
  do { \
    info("\t- Running test " #name ": "); \
    if (test_ ## module ## _ ## name()) { \
      failed++; \
      error("failed\n"); \
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