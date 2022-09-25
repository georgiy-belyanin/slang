#pragma once

#include <stdio.h>
#include <stdlib.h>

#define log(...) \
  do { \
    printf(__VA_ARGS__); \
  } while(0)
#define info(...) \
  do { \
    log("Info: " __VA_ARGS__); \
  } while(0)
#define warn(...) \
  do { \
    log("Warn: " __VA_ARGS__); \
  } while(0)
#define error(...) \
  do { \
    log("Error: " __VA_ARGS__); \
    exit(-1); \
  } while(0)