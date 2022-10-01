#pragma once

#include "../ast.h"
#include "../lexer.h"
#include "parser.h"

ast_t* parser_parse_stmt(parser_t* parser);
