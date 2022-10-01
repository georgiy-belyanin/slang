#include "real_parser.h"

ast_t* parser_parse_real(parser_t* parser) {
  return create_real_ast(parser_eat_real(parser));
}