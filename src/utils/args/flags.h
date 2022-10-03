#pragma once

#include "flag_type.h"

#include <stdbool.h>

typedef struct flags_t flags_t;

flags_t* create_flags();
void destroy_flags(flags_t* flags);

bool flags_is_flag(flags_t* flags, char* val);
void flags_parse_arg(flags_t* flags, char* arg);

bool flags_is_flag_set(flags_t* flags, flag_type_t flag_type);
char* flags_get_flag(flags_t* flags, flag_type_t flag_type);
void flags_set_flag(flags_t* flags, flag_type_t flag_type, char* value);