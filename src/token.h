#pragma once 

#include "tokens.h"
#include <stdlib.h>

typedef enum {
#define TOKEN(id, _) id,
TOKENS
#undef TOKEN
} token_t;

char* token_get_name(token_t token);