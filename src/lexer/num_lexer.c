#include "num_lexer.h"

#include <ctype.h>

token_t lexer_next_num(lexer_t* lexer) {
  lexer->int_ = 0;
  while(isdigit(lexer->cur)) {
    lexer->int_ = lexer->int_ * 10 + (lexer->cur - '0');
    lexer_next(lexer);
  }
  if (lexer->cur != '.') {
    return TOKEN_INT;
  }
  lexer_next(lexer);

  lexer->real = lexer->int_;
  double real_part = 0;
  double real_div = 1;

  while(isdigit(lexer->cur)) {
    real_part = real_part * 10 + (lexer->cur - '0');
    real_div *= 10;
    lexer_next(lexer);
  }
  lexer->real = lexer->real + (real_part / real_div);
  return TOKEN_REAL;
}