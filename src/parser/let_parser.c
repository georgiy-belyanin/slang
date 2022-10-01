#include "let_parser.h"

#include "ty_parser.h"
#include "expr_parser.h"

ast_t* parser_parse_let(parser_t* parser) {
  parser_eat(parser, TOKEN_LET);
  char* name = parser_eat_ident(parser);
  parser_eat(parser, TOKEN_COLON);
  ast_t* ty = parser_parse_ty(parser);
  return create_let_ast(name, ty);
}