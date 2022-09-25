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

static int token_get_prec(token_t token) {
  if (token == TOKEN_ASSIGN) 
    return 10;
  else if (token == TOKEN_LESS || token == TOKEN_GRTR)
    return 20;
  else if (token == TOKEN_ADD || token == TOKEN_SUB) 
    return 30;
  else if (token == TOKEN_MUL || token == TOKEN_DIV) 
    return 40;
  else 
    return -1;
}

static void next() {
  cur = lexer_next_token();
}
static char* get_ident() {
  return lexer_get_ident();
}
static int get_number() {
  return lexer_get_number();
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
static int eat_number() {
  int number = get_number();
  eat(TOKEN_NUMBER);
  return number;
}

static ast_t* parse_expr();
static ast_t* parse_ty() {
  return create_ty_ast(eat_ident());
}
static ast_t* parse_number() {
  return create_num_ast(eat_number());
}
/*static ast_t* parse_call() {
  return NULL;
}*/
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
  else if (cur == TOKEN_NUMBER)
    return parse_number();
  else if (cur == TOKEN_LPAREN) 
    return parse_paren();
  else 
    return NULL;
}
static ast_t* parse_bin_rhs(ast_t* lhs, int min_prec) {
  while (token_get_prec(cur) >= min_prec) {
    token_t op = cur;
    next();
    ast_t* rhs = parse_primary();
    while (token_get_prec(cur) > token_get_prec(op)) {
      rhs = parse_bin_rhs(rhs, token_get_prec(op) + ((token_get_prec(cur) > token_get_prec(op)) ? 1 : 0));
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
  ast_t* body = parse_body();
  return create_if_ast(cond, body);
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
  else 
    val = parse_expr();

  eat(TOKEN_SEMI);
  return val;
}
static ast_t* parse_body() {
  // TODO: Limitations.
  ast_t** stmts = calloc(sizeof(ast_t*), 100);
  int stmt_count = 0;

  eat(TOKEN_LBLOCK);
  while(cur != TOKEN_RBLOCK) {
    stmts[stmt_count++] = parse_stmt();
  }
  eat(TOKEN_RBLOCK);

  return create_body_ast(stmt_count, stmts);
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

  if (cur == TOKEN_FUNC) {
    return parse_func();
  }

  return NULL;
}

