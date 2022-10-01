#include "func_decl_parser.h"

#include <stdlib.h>
#include "ty_parser.h"

ast_t* parser_parse_func_decl(parser_t* parser) {
  parser_eat(parser, TOKEN_FUNC);
  char* name = parser_eat_ident(parser);
  parser_eat(parser, TOKEN_LPAREN);

  // TODO: Limitations
  char** arg_names = calloc(sizeof(char*), 10);
  ast_t** arg_tys = calloc(sizeof(ast_t*), 10);

  int arg_count = 0;

  while(parser->cur != TOKEN_RPAREN) {
    char* arg_name = parser_eat_ident(parser);
    parser_eat(parser, TOKEN_COLON);
    ast_t* arg_ty = parser_parse_ty(parser);

    arg_names[arg_count] = arg_name;
    arg_tys[arg_count] = arg_ty;
    arg_count++;

    if (parser->cur == TOKEN_COMMA) {
      parser_eat(parser, TOKEN_COMMA);
    } else {
      parser_expect(parser, TOKEN_RPAREN);
    }
  }

  parser_eat(parser, TOKEN_RPAREN);
  parser_eat(parser, TOKEN_COLON);
  ast_t* ty = parser_parse_ty(parser);
  return create_func_decl_ast(name, ty, arg_count, arg_names, arg_tys);
}