#pragma once

#include "../ast.h"
#include "../lexer.h"
#include "../tokens.h"

typedef struct parser_t parser_t;

parser_t* create_parser(lexer_t* lexer);
void destroy_parser(parser_t* parser);

ast_t* parser_parse(parser_t* parser);