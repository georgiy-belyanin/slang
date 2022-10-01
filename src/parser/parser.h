#pragma once

#include "../ast.h"
#include "../lexer.h"
#include "public.h"

struct parser_t {
  token_t cur;
  lexer_t* lexer;
};

void parser_next(parser_t* parser);

void parser_expect(parser_t* parser, token_t token);
void parser_expect_any(parser_t* parser, int count, ...);

int parser_get_int(parser_t* parser);
float parser_get_real(parser_t* parser);
char* parser_get_str(parser_t* parser);

void parser_eat(parser_t* parser, token_t token);
char* parser_eat_ident(parser_t* parser);
int parser_eat_int(parser_t* parser);
float parser_eat_real(parser_t* parser);
char* parser_eat_str(parser_t* parser);

ast_t* parser_parse(parser_t* parser);
