#include "in.h"

#include "../lexer.h"
#include <stdio.h>
#include <stdlib.h>

void in_init(char* filename) {
  FILE *f = fopen(filename, "rb");

  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

  char *content = malloc(fsize + 1);
  fread(content, fsize, 1, f);
  fclose(f);

  content[fsize] = 0;



}