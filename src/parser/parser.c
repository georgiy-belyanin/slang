#include "parser.h"

#include <stdarg.h>
#include "../utils.h"

static token_t cur = TOKEN_UNKNOWN;

static void expect(token_t token) {
  if (cur != token)
    error("expected %s, and got %s", token_get_name(token), token_get_name(cur));
}
static void expect_any(int count, ...) {
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    if (cur == va_arg(args, token_t)) {
      va_end(args);
      return;
    }
  }
  // TODO: Print extended information about what token was expected.
  error("unexpected token");
  va_end(args);
}

static void next() {
  cur = lexer_next_token();
}
static char* get_ident() {
  return lexer_get_ident();
}
static int get_int() {
  return lexer_get_int();
}
static double get_real() {
  return lexer_get_real();
}
static void eat(token_t token) {
  expect(token);
  next();
}
static char* eat_ident() {
  char* ident = get_ident();
  eat(TOKEN_IDENT);
  return ident;
}
static int eat_int() {
  int int_ = get_int();
  eat(TOKEN_INT);
  return int_;
}
static double eat_real() {
  double real = get_real();
  eat(TOKEN_REAL);
  return real;
}

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
static op_t un_op_from_token(token_t token) {
  if (token == TOKEN_SUB)
    return OP_MINUS;
  else if (token == TOKEN_NOT)
    return OP_NOT;
  return OP_UNKNOWN;
}
static int token_is_un_op(token_t token) {
  return token == TOKEN_SUB || token == TOKEN_NOT;
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


static ast_t* parse_expr();
static ast_t* parse_ty() {
  return create_ty_ast(eat_ident());
}
static ast_t* parse_real() {
  return create_real_ast(eat_real());
}
static ast_t* parse_int() {
  return create_int_ast(eat_int());
}
static ast_t* parse_ident() {
  char* name = eat_ident();
  if (cur == TOKEN_LPAREN) {
    eat(TOKEN_LPAREN);

    int arg_count = 0;
    ast_t** args = calloc(sizeof(ast_t*), 10);
    while(cur != TOKEN_RPAREN) {
      args[arg_count++] = parse_expr();

      if (cur == TOKEN_COMMA) {
        eat(TOKEN_COMMA);
      } else {
        expect(TOKEN_RPAREN);
      }
    }
    eat(TOKEN_RPAREN);

    return create_call_ast(name, arg_count, args);
  } else {
    return create_var_ast(name);
  }
  return NULL;
}
static ast_t* parse_paren() {
  return NULL;
}
static ast_t* parse_primary() {
  if (cur == TOKEN_IDENT)
    return parse_ident();
  else if (cur == TOKEN_REAL)
    return parse_real();
  else if (cur == TOKEN_INT)
    return parse_int();
  else if (cur == TOKEN_LPAREN) 
    return parse_paren();
  // else if (token_is_un_op(cur)) 
  //   return parse_un_op();
  else 
    return NULL;
}
// static ast_t* parse_un() {
//   op_t op = un_op_from_token(cur);
//   next();
//   ast_t* val = parse_expr();
//   return create_un(op, val);
// }
static ast_t* parse_bin_rhs(ast_t* lhs, int min_prec) {
  while (op_get_prec(bin_op_from_token(cur)) >= min_prec) {
    op_t op = bin_op_from_token(cur);
    next();
    ast_t* rhs = parse_primary();
    op_t op1 = bin_op_from_token(cur);

    if (op_get_prec(op1) > op_get_prec(op)) {
      rhs = parse_bin_rhs(rhs, op_get_prec(op) + 1);
    }
    lhs = create_bin_ast(op, lhs, rhs);
  }
  return lhs;
}
static ast_t* parse_expr() {
  ast_t* lhs = parse_primary();

  return parse_bin_rhs(lhs, 0);
}

static ast_t* parse_body();
static ast_t* parse_if() {
  eat(TOKEN_IF);
  ast_t* cond = parse_expr();
  ast_t* then = parse_body();
  ast_t* ow = NULL;

  if (cur == TOKEN_ELSE) {
    eat(TOKEN_ELSE);
    ow = parse_body();
  }

  return create_if_ast(cond, then, ow);
}
static ast_t* parse_while() {
  eat(TOKEN_WHILE);
  ast_t* cond = parse_expr();
  ast_t* body = parse_body();
  return create_while_ast(cond, body);
}
static ast_t* parse_loop() {
  eat(TOKEN_LOOP);
  ast_t* body = parse_body();
  return create_loop_ast(body);
}
static ast_t* parse_let() {
  eat(TOKEN_LET);
  char* name = eat_ident();
  eat(TOKEN_COLON);
  ast_t* ty = parse_ty();
  return create_let_ast(name, ty);
}
static ast_t* parse_ret() {
  eat(TOKEN_RET);
  ast_t* expr = parse_expr();
  return create_ret_ast(expr);
}

static ast_t* parse_stmt() {
  ast_t* val = NULL;
  if (cur == TOKEN_RET)
    val = parse_ret();
  else if (cur == TOKEN_LET)
    val = parse_let();
  else if (cur == TOKEN_IF)
    return parse_if();
  else if (cur == TOKEN_WHILE)
    return parse_while();
  else if (cur == TOKEN_LOOP)
    return parse_loop();
  else 
    val = parse_expr();

  eat(TOKEN_SEMI);
  return val;
}
static ast_t* parse_small_body() {

  ast_t** stmts = calloc(sizeof(ast_t*), 1);
  stmts[0] = parse_stmt();
  return create_body_ast(1, stmts);
}
static ast_t* parse_large_body() {
  ast_t** stmts = calloc(sizeof(ast_t*), 100);
  int stmt_count = 0;

  eat(TOKEN_LBLOCK);
  while(cur != TOKEN_RBLOCK) {
    stmts[stmt_count++] = parse_stmt();
  }
  eat(TOKEN_RBLOCK);
  return create_body_ast(stmt_count, stmts);
}
static ast_t* parse_body() {
  // TODO: Limitations.
  if(cur == TOKEN_LBLOCK) {
    return parse_large_body();
  } else {
    return parse_small_body();
  }
}


static ast_t* parse_func_decl() {
  eat(TOKEN_FUNC);
  char* name = eat_ident();
  eat(TOKEN_LPAREN);

  // TODO: Limitations
  char** arg_names = calloc(sizeof(char*), 10);
  ast_t** arg_tys = calloc(sizeof(ast_t*), 10);

  int arg_count = 0;

  while(cur != TOKEN_RPAREN) {
    char* arg_name = eat_ident();
    eat(TOKEN_COLON);
    ast_t* arg_ty = parse_ty();

    arg_names[arg_count] = arg_name;
    arg_tys[arg_count] = arg_ty;
    arg_count++;

    if (cur == TOKEN_COMMA) {
      eat(TOKEN_COMMA);
    } else {
      expect(TOKEN_RPAREN);
    }
  }

  eat(TOKEN_RPAREN);
  eat(TOKEN_COLON);
  ast_t* ty = parse_ty();
  return create_func_decl_ast(name, ty, arg_count, arg_names, arg_tys);
}
static ast_t* parse_func() {
  ast_t* decl = parse_func_decl();
  ast_t* body = parse_body();
  return create_func_ast(decl, body);
}

ast_t* parser_parse() {
  if (cur == TOKEN_UNKNOWN)
    next();

  if (cur == TOKEN_FUNC)
    return parse_func();
  else if (cur == TOKEN_EOF) 
    return NULL;
  return NULL;
}

