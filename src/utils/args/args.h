#pragma once

#include "flags.h"

struct args_t {
  flags_t* flags;
  
  char** files;
  int file_count;
};