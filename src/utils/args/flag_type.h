#pragma once

#include "flag_types.h"

typedef enum {
  FLAG_TYPE_UNKNOWN,

#define FLAG_TYPE(name, _, _1, _2) name,
FLAG_TYPES
#undef FLAG_TYPE

  FLAG_TYPE_COUNT
} flag_type_t;

flag_type_t flag_type_from_str(char* str);
char* flag_type_get_default(flag_type_t flag_type);