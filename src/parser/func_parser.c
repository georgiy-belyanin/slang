#include "func_parser.h"

#include "func_decl_parser.h"
#include "body_parser.h"

ast_t* parser_parse_func(parser_t* parser) {
  ast_t* decl = parser_parse_func_decl(parser);
  ast_t* body = parser_parse_body(parser);
  return create_func_ast(decl, body);
}