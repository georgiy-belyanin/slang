#include "expr_parser.h"

#include "primary_parser.h"

static op_t bin_op_from_token(token_t token) {
  if (token == TOKEN_ASSIGN)
    return OP_ASSIGN;

  else if (token == TOKEN_ADD)
    return OP_ADD;
  else if (token == TOKEN_SUB)
    return OP_SUB;
  else if (token == TOKEN_MUL)
    return OP_MUL;
  else if (token == TOKEN_DIV)
    return OP_DIV;

  else if (token == TOKEN_EQ)
    return OP_EQ;
  else if (token == TOKEN_NE)
    return OP_NE;
  else if (token == TOKEN_LESS)
    return OP_LESS;
  else if (token == TOKEN_GRTR)
    return OP_GRTR;
  else if (token == TOKEN_LE)
    return OP_LE;
  else if (token == TOKEN_GE)
    return OP_GE;

  else if (token == TOKEN_NOT)
    return OP_NOT;
  else if (token == TOKEN_AND)
    return OP_AND;
  else if (token == TOKEN_OR)
    return OP_OR;

  else if (token == TOKEN_BWAND)
    return OP_BWAND;
  else if (token == TOKEN_BWOR)
    return OP_BWOR;
  return OP_UNKNOWN;
}
static int op_get_prec(op_t op) {
  if (op == OP_ASSIGN) 
    return 10;
  else if (op == OP_OR)
    return 20;
  else if (op == OP_AND) 
    return 25;
  else if (op == OP_BWOR)
    return 30;
  else if (op == OP_BWAND) 
    return 35;
  else if (op == OP_LESS || op == OP_GRTR || op == OP_LE || op == OP_GE)
    return 40;
  else if (op == OP_ADD || op == OP_SUB)
    return 50;
  else if (op == OP_MUL || op == OP_DIV)
    return 60;
  else if (op == OP_NOT)
    return 70;
  else 
    return -1;
}

static ast_t* parser_parse_bin_rhs(parser_t* parser, ast_t* lhs, int min_prec) {
  while (op_get_prec(bin_op_from_token(parser->cur)) >= min_prec) {
    op_t op = bin_op_from_token(parser->cur);
    parser_next(parser);
    ast_t* rhs = parser_parse_primary(parser);
    op_t op1 = bin_op_from_token(parser->cur);

    if (op_get_prec(op1) > op_get_prec(op)) {
      rhs = parser_parse_bin_rhs(parser, rhs, op_get_prec(op) + 1);
    }
    lhs = create_bin_ast(op, lhs, rhs);
  }
  return lhs;
}
ast_t* parser_parse_expr(parser_t* parser) {
  ast_t* lhs = parser_parse_primary(parser);

  return parser_parse_bin_rhs(parser, lhs, 0);
}