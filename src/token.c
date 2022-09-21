#include "token.h"

char* token_get_name(token_t token) {
#define TOKEN(id, name) if (token == id) return name; else
TOKENS
#undef TOKEN
  return NULL;
}