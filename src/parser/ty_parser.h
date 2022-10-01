#pragma once

#include "../ast.h"
#include "../lexer.h"
#include "parser.h"

ast_t* parser_parse_ty(parser_t* parser);
