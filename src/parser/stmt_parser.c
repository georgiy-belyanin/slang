#include "stmt_parser.h"

#include <stdlib.h>
#include "expr_parser.h"
#include "if_parser.h"
#include "ret_parser.h"
#include "let_parser.h"
#include "loop_parser.h"
#include "while_parser.h"

ast_t* parser_parse_stmt(parser_t* parser) {
  ast_t* val = NULL;
  if (parser->cur == TOKEN_RET)
    val = parser_parse_ret(parser);
  else if (parser->cur == TOKEN_LET)
    val = parser_parse_let(parser);
  else if (parser->cur == TOKEN_IF)
    return parser_parse_if(parser);
  else if (parser->cur == TOKEN_WHILE)
    return parser_parse_while(parser);
  else if (parser->cur == TOKEN_LOOP)
    return parser_parse_loop(parser);
  else 
    val = parser_parse_expr(parser);

  parser_eat(parser, TOKEN_SEMI);
  return val;
}
