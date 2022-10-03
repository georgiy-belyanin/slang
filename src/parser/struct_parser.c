#include "struct_parser.h"

#include "body_parser.h"

ast_t* parser_parse_struct(parser_t* parser) {
  parser_eat(parser, TOKEN_STRUCT);

  char* name = parser_eat_ident(parser);
  ast_t* body = parser_parse_body(parser);

  return create_struct_ast(name, body);
}