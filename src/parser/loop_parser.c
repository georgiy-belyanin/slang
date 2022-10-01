#include "loop_parser.h"

#include "body_parser.h"
#include "expr_parser.h"

ast_t* parser_parse_loop(parser_t* parser) {
  parser_eat(parser, TOKEN_LOOP);
  ast_t* body = parser_parse_body(parser);
  return create_loop_ast(body);
}