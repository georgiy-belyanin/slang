#include "public.h"

#include <stdlib.h>
#include "func_parser.h"
#include "parser.h"
#include "struct_parser.h"

parser_t* create_parser(lexer_t* lexer) {
  parser_t* parser = malloc(sizeof(parser_t));
  parser->cur = TOKEN_UNKNOWN;
  parser->lexer = lexer;
  return parser;
}
void destroy_parser(parser_t* parser) {
  free(parser);
}

ast_t* parser_parse(parser_t* parser) {
  if (parser->cur == TOKEN_UNKNOWN)
    parser_next(parser);

  if (parser->cur == TOKEN_FUNC)
    return parser_parse_func(parser);
  else if (parser->cur == TOKEN_STRUCT) 
    return parser_parse_struct(parser);
  else if (parser->cur == TOKEN_EOF) 
    return NULL;

  return NULL;
}