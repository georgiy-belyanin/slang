#pragma once

#include "../ast.h"
#include "../tokens.h"
#include "parser.h"

ast_t* parser_parse_while(parser_t* parser);