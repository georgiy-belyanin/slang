#pragma once

#include "token.h"

void lexer_set_code(char* code);
token_t lexer_next_token();

char* lexer_get_ident();
int lexer_get_number();