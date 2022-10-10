#include "ext_parser.h"

#include "func_decl_parser.h"

ast_t* parser_parse_ext(parser_t* parser) {
  parser_eat(parser, TOKEN_EXT);
  ast_t* decl = parser_parse_func_decl(parser);
  return create_ext_ast(decl);
}