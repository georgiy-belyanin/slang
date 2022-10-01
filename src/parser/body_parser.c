#include "body_parser.h"

#include <stdlib.h>
#include "stmt_parser.h"

static ast_t* parser_parse_small_body(parser_t* parser) {
  ast_t** stmts = calloc(sizeof(ast_t*), 1);
  stmts[0] = parser_parse_stmt(parser);
  return create_body_ast(1, stmts);
}
static ast_t* parser_parse_large_body(parser_t* parser) {
  ast_t** stmts = calloc(sizeof(ast_t*), 100);
  int stmt_count = 0;

  parser_eat(parser, TOKEN_LBLOCK);
  while(parser->cur != TOKEN_RBLOCK) {
    stmts[stmt_count++] = parser_parse_stmt(parser);
  }
  parser_eat(parser, TOKEN_RBLOCK);
  return create_body_ast(stmt_count, stmts);
}

ast_t* parser_parse_body(parser_t* parser) {
  if(parser->cur == TOKEN_LBLOCK) {
    return parser_parse_large_body(parser);
  } else {
    return parser_parse_small_body(parser);
  }
}