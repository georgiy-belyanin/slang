#include "ty_parser.h"

#include <stdlib.h>

static ast_t* parser_parse_uptr_ty(parser_t* parser) {
  // parser_eat(parser, TOKEN_UPTR);
  // return create_uptr_ty_ast(parser_parse_ty(parser));
  return NULL;
}
static ast_t* parser_parse_sptr_ty(parser_t* parser) {
  //parser_eat(parser, TOKEN_SPTR);
  //return create_sptr_ty_ast(parser_parse_ty(parser));
  return NULL;
}

ast_t* parser_parse_ty(parser_t* parser) {
  if (parser->cur == TOKEN_UPTR) 
    return parser_parse_uptr_ty(parser);
  else if (parser->cur == TOKEN_SPTR) 
    return parser_parse_sptr_ty(parser);
  // else if (parser->cur == TOKEN_LBLOCK) 
  //   return parse_arr_ty(parser);
  else if (parser->cur == TOKEN_IDENT)
    return create_ty_ast(parser_eat_ident(parser));
  else
    return NULL;
}
