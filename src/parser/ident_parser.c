#include "ident_parser.h"

#include <stdlib.h>
#include "expr_parser.h"

ast_t* parser_parse_ident(parser_t* parser) {
  char* name = parser_eat_ident(parser);
  if (parser->cur == TOKEN_LPAREN) {
    parser_eat(parser, TOKEN_LPAREN);

    int arg_count = 0;
    ast_t** args = calloc(sizeof(ast_t*), 10);
    while(parser->cur != TOKEN_RPAREN) {
      args[arg_count++] = parser_parse_expr(parser);

      if (parser->cur == TOKEN_COMMA) {
        parser_eat(parser, TOKEN_COMMA);
      } else {
        parser_expect(parser, TOKEN_RPAREN);
      }
    }
    parser_eat(parser, TOKEN_RPAREN);

    return create_call_ast(name, arg_count, args);
  } else {
    return create_var_ast(name);
  }
}