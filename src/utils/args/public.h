#pragma once

#include "flag_type.h"

typedef struct args_t args_t;

args_t* create_args(int argc, char** argv);
void destroy_args(args_t* args);

int args_file_get_count(args_t* args);
char* args_file_get(args_t* args, int n);

char* args_flags_get(args_t* args, flag_type_t flag_type);