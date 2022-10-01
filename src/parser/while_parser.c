#include "while_parser.h"

#include "body_parser.h"
#include "expr_parser.h"

ast_t* parser_parse_while(parser_t* parser) {
  parser_eat(parser, TOKEN_WHILE);
  ast_t* cond = parser_parse_expr(parser);
  ast_t* body = parser_parse_body(parser);
  return create_while_ast(cond, body);
}