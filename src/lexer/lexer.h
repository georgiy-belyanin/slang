#pragma once

#include "../tokens.h"
#include "public.h"

struct lexer_t {
  char* code;
  char cur;
  int pos;
  int row;
  int col;

  char* ident;
  int int_;
  double real;
  char* str;
};

void lexer_next(lexer_t* lexer);
void lexer_skip_spaces(lexer_t* lexer);
