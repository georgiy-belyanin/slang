#include "int_parser.h"

ast_t* parser_parse_int(parser_t* parser) {
  return create_int_ast(parser_eat_int(parser));
}