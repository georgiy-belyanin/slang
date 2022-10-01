#pragma once

#include <stdlib.h>
#include <string.h>
#include "../tokens.h"
#include "lexer.h"

token_t lexer_next_word(lexer_t* lexer);