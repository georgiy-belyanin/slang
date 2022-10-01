#pragma once

#include "../ast.h"
#include "../tokens.h"
#include "parser.h"

ast_t* parser_parse_ident(parser_t* parser);