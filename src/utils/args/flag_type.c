#include "flag_type.h"

#include <stdlib.h>
#include <string.h>

flag_type_t flag_type_from_str(char* str) {
#define FLAG_TYPE(name, s, l, _) if (strcmp(str, s) == 0 || strcmp(str, l) == 0) return name; else
FLAG_TYPES
#undef FLAG_TYPE
    return FLAG_TYPE_UNKNOWN;
}
char* flag_type_get_default(flag_type_t flag_type) {
#define FLAG_TYPE(name, _, _1, default) if (flag_type == name) return (char*) default; else
FLAG_TYPES
#undef FLAG_TYPE
  return NULL;
}
