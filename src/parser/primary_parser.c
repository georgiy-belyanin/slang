#include "primary_parser.h"

#include <stdlib.h>
#include "ident_parser.h"
#include "real_parser.h"
#include "int_parser.h"

// static op_t un_op_from_token(token_t token) {
//   if (token == TOKEN_SUB)
//     return OP_MINUS;
//   else if (token == TOKEN_NOT)
//     return OP_NOT;
//   return OP_UNKNOWN;
// }
// static int token_is_un_op(token_t token) {
//   return token == TOKEN_SUB || token == TOKEN_NOT;
// }
//
// static ast_t* parse_un() {
//   op_t op = un_op_from_token(cur);
//   next();
//   ast_t* val = parse_expr();
//   return create_un(op, val);
// }

static ast_t* parser_parse_paren(parser_t* parser) {
  return NULL;
}

ast_t* parser_parse_primary(parser_t* parser) {
  if (parser->cur == TOKEN_IDENT)
    return parser_parse_ident(parser);
  else if (parser->cur == TOKEN_REAL)
    return parser_parse_real(parser);
  else if (parser->cur == TOKEN_INT)
    return parser_parse_int(parser);
  else if (parser->cur == TOKEN_LPAREN) 
    return parser_parse_paren(parser);
  // else if (token_is_un_op(cur)) 
  //   return parse_un_op();
  else 
    return NULL;

}