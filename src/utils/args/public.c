#include "public.h"

#include <stdlib.h>
#include "args.h"
#include "flags.h"

args_t* create_args(int argc, char** argv) {
  args_t* args = malloc(sizeof(args_t));

  args->files = calloc(sizeof(char*), 20);
  args->flags = create_flags();

  for(int i = 1; i < argc; i++) {
    if(flags_is_flag(args->flags, argv[i]))
      flags_parse_arg(args->flags, argv[i]);
    else 
      args->files[args->file_count++] = argv[i];
  }

  return args;
}
void destroy_args(args_t* args) {
  destroy_flags(args->flags);
  free(args);
}

int args_file_get_count(args_t* args) {
  return args->file_count;
}

char* args_file_get(args_t* args, int n) {
  if (n >= args->file_count)
    return NULL;

  return args->files[n];
}

char* args_flags_get(args_t* args, flag_type_t flag_type) {
  return flags_get_flag(args->flags, flag_type);
}
