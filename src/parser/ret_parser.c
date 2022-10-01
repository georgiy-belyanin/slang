#include "ret_parser.h"

#include "expr_parser.h"

ast_t* parser_parse_ret(parser_t* parser) {
  parser_eat(parser, TOKEN_RET);
  ast_t* expr = parser_parse_expr(parser);
  return create_ret_ast(expr);
}