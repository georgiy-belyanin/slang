#include "flags.h"

#include <string.h>
#include <stdlib.h>

struct flags_t {
  char** flags;
};

flags_t* create_flags() {
  flags_t* flags = malloc(sizeof(flags_t));

  flags->flags = calloc(sizeof(char*), FLAG_TYPE_COUNT);

  for(int i = 0; i < FLAG_TYPE_COUNT; i++) {
    flags->flags[i] = flag_type_get_default(i);
  }

  return flags;
}
void destroy_flags(flags_t* flags) {
  free(flags->flags);
  // Fixme: memory-leak.
  // ...
  free(flags);
}

bool flags_is_flag(flags_t* flags, char* val) {
  return val[0] == '-';
}
void flags_parse_arg(flags_t* flags, char* arg) {
  char* arg1 = malloc(sizeof(char) * 32);
  strcpy(arg1, arg);

  char* tok = strtok(arg1, "=");
  char* flag = tok; 

  tok = strtok(NULL, "=");
  char* val = (tok == NULL) ? ((char*) 1) : tok;

  flag_type_t flag_type = flag_type_from_str(flag);

  if (flag_type == FLAG_TYPE_UNKNOWN)
    return;

  flags->flags[flag_type] = val;
}

bool flags_is_flag_set(flags_t* flags, flag_type_t flag_type) {
  return flags->flags[flag_type] != NULL;
}
char* flags_get_flag(flags_t* flags, flag_type_t flag_type) {
  return flags->flags[flag_type];
}
void flags_set_flag(flags_t* flags, flag_type_t flag_type, char* value) {
  flags->flags[flag_type] = value;
}