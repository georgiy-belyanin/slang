#include "lexer.h"

#include <ctype.h>
#include <stdlib.h>

void lexer_next(lexer_t* lexer) {
  lexer->cur = lexer->code[lexer->pos++];

  if (lexer->cur == '\n') {
    lexer->row++;
    lexer->col = 0;
  } else {
    lexer->col++;
  }
}
void lexer_skip_spaces(lexer_t* lexer) {
  while(isspace(lexer->cur))
    lexer_next(lexer);
}

