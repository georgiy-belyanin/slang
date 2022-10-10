#include "public.h"

#include <ctype.h>
#include <stdlib.h>
#include "num_lexer.h"
#include "lexer.h"
#include "sym_lexer.h"
#include "word_lexer.h"

lexer_t* create_lexer(char* code) {
  lexer_t* lexer = malloc(sizeof(lexer_t));

  lexer->code = code;
  lexer->cur = ' ';
  lexer->pos = 0;
  lexer->row = 1;
  lexer->col = 0;

  lexer->ident = NULL;
  lexer->int_ = 0;
  lexer->real = 0.0;
  lexer->str = NULL;

  return lexer;
}
void destroy_lexer(lexer_t* lexer) {
  // free(lexer->code);
  // free(lexer->ident);
  // free(lexer->str);
  free(lexer);
}

token_t lexer_next_token(lexer_t* lexer) {
  lexer_skip_spaces(lexer);

  if (isalpha(lexer->cur)) {
    return lexer_next_word(lexer);
  } else if (isdigit(lexer->cur)) {
    return lexer_next_num(lexer);
  } else {
    return lexer_next_sym(lexer);
  }
}

char* lexer_get_ident(lexer_t* lexer) {
  return lexer->ident;
}
int lexer_get_int(lexer_t* lexer) {
  return lexer->int_;
}
double lexer_get_real(lexer_t* lexer) {
  return lexer->real;
}
int lexer_get_row(lexer_t* lexer) {
  return lexer->row;
}
int lexer_get_col(lexer_t* lexer) {
  return lexer->col;
}
