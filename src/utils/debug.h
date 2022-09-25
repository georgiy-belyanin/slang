#pragma once

#include "log.h"

#define debug(...) \
  do { \
    log(__VA_ARGS__); \
  } while (0)
#define watch(f, x) \
  do { \
    debug("'%s' = " f "\n", #x, x); \
  } while (0)
