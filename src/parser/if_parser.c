#include "if_parser.h"

#include <stdlib.h>
#include "body_parser.h"
#include "expr_parser.h"

ast_t* parser_parse_if(parser_t* parser) {
  parser_eat(parser, TOKEN_IF);
  ast_t* cond = parser_parse_expr(parser);
  ast_t* then = parser_parse_body(parser);
  ast_t* ow = NULL;

  if (parser->cur == TOKEN_ELSE) {
    parser_eat(parser, TOKEN_ELSE);
    ow = parser_parse_body(parser);
  }

  return create_if_ast(cond, then, ow);
}