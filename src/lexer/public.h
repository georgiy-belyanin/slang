#pragma once

#include "../tokens.h"

typedef struct lexer_t lexer_t;

lexer_t* create_lexer(char* code);
void destroy_lexer(lexer_t* lexer);

token_t lexer_next_token(lexer_t* lexer);

char* lexer_get_ident(lexer_t* lexer);
int lexer_get_int(lexer_t*);
double lexer_get_real(lexer_t* lexer);
