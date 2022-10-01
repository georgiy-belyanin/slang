#include "sym_lexer.h"

#include <stdio.h>

token_t lexer_next_sym(lexer_t* lexer) {
  char prev = lexer->cur;
  lexer_next(lexer);
  if (prev == ':')
    return TOKEN_COLON;
  else if (prev == ';')
    return TOKEN_SEMI;
  else if (prev == '.')
    return TOKEN_DOT;
  else if (prev == ',')
    return TOKEN_COMMA;
  else if (prev == '(')
    return TOKEN_LPAREN;
  else if (prev == ')')
    return TOKEN_RPAREN;
  else if (prev == '[')
    return TOKEN_LBRACKET;
  else if (prev == ']')
    return TOKEN_RBRACKET;
  else if (prev == '{')
    return TOKEN_LBLOCK;
  else if (prev == '}')
    return TOKEN_RBLOCK;
  else if (prev == '+')
    return TOKEN_ADD;
  else if (prev == '-')
    return TOKEN_SUB;
  else if (prev == '*')
    return TOKEN_MUL;
  else if (prev == '/')
    return TOKEN_DIV;
  else if (prev == '=') {
    if (lexer->cur == '=') {
      lexer_next(lexer);
      return TOKEN_EQ;
    } else {
      return TOKEN_ASSIGN;
    }
  } else if (prev == '<') {
    if (lexer->cur == '=') {
      lexer_next(lexer);
      return TOKEN_LE;
    } else {
      return TOKEN_LESS;
    }
  } else if (prev == '>') {
    if (lexer->cur == '=') {
      lexer_next(lexer);
      return TOKEN_GE;
    } else {
      return TOKEN_GRTR;
    }
  } else if (prev == '!') {
    if (lexer->cur == '=') {
      lexer_next(lexer);
      return TOKEN_NE;
    } else {
      return TOKEN_NOT;
    }
  }else if (prev == '&') {
    if (lexer->cur == '&') {
      lexer_next(lexer);
      return TOKEN_AND;
    } else {
      return TOKEN_BWAND;
    }
  } else if (prev == '|') {
    if (lexer->cur == '|') {
      lexer_next(lexer);
      return TOKEN_OR;
    } else {
      return TOKEN_BWOR;
    }
  } else if (prev == EOF)
    return TOKEN_EOF;
  else 
    return TOKEN_UNKNOWN;
}