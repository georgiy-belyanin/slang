#include "parser.h"

#include <stdarg.h>
#include "../utils.h"

void parser_next(parser_t* parser) {
  parser->cur = lexer_next_token(parser->lexer);
}

void parser_expect(parser_t* parser, token_t token) {
  if (parser->cur != token)
    error("expected %s, and got %s", token_get_name(token), token_get_name(parser->cur));
}
void parser_expect_any(parser_t* parser, int count, ...) {
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    if (parser->cur == va_arg(args, token_t)) {
      va_end(args);
      return;
    }
  }
  // TODO: Print extended information about what token was expected.
  error("unexpected token");
  va_end(args);
}

static char* parser_get_ident(parser_t* parser) {
  return lexer_get_ident(parser->lexer);
}
int parser_get_int(parser_t* parser) {
  return lexer_get_int(parser->lexer);
}
float parser_get_real(parser_t* parser) {
  return lexer_get_real(parser->lexer);
}
void parser_eat(parser_t* parser, token_t token) {
  parser_expect(parser, token);
  parser_next(parser);
}
char* parser_eat_ident(parser_t* parser) {
  char* ident = parser_get_ident(parser);
  parser_eat(parser, TOKEN_IDENT);
  return ident;
}
int parser_eat_int(parser_t* parser) {
  int int_ = parser_get_int(parser);
  parser_eat(parser, TOKEN_INT);
  return int_;
}
float parser_eat_real(parser_t* parser) {
  float real = parser_get_real(parser);
  parser_eat(parser, TOKEN_REAL);
  return real;
}


