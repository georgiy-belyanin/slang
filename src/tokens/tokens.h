#pragma once

#define TOKENS \
  TOKEN(TOKEN_UNKNOWN, "[unknown token]")\
  TOKEN(TOKEN_EOF, "eof")\
  \
  TOKEN(TOKEN_FUNC, "func")\
  TOKEN(TOKEN_LET, "let")\
  TOKEN(TOKEN_RET, "ret")\
  TOKEN(TOKEN_EXT, "ext")\
  TOKEN(TOKEN_IF, "if")\
  TOKEN(TOKEN_ELSE, "else")\
  TOKEN(TOKEN_WHILE, "while")\
  TOKEN(TOKEN_LOOP, "loop")\
  \
  TOKEN(TOKEN_COLON, ":")\
  TOKEN(TOKEN_SEMI, ";")\
  TOKEN(TOKEN_DOT, ",")\
  TOKEN(TOKEN_COMMA, ",")\
  TOKEN(TOKEN_LPAREN, "(")\
  TOKEN(TOKEN_RPAREN, ")")\
  TOKEN(TOKEN_LBLOCK, "{")\
  TOKEN(TOKEN_RBLOCK, "}")\
  TOKEN(TOKEN_LBRACKET, "[")\
  TOKEN(TOKEN_RBRACKET, "]")\
  \
  TOKEN(TOKEN_ASSIGN, "=")\
  TOKEN(TOKEN_ADD, "+")\
  TOKEN(TOKEN_SUB, "-")\
  TOKEN(TOKEN_MUL, "*")\
  TOKEN(TOKEN_DIV, "/")\
  \
  TOKEN(TOKEN_EQ, "==")\
  TOKEN(TOKEN_NE, "!=")\
  TOKEN(TOKEN_LESS, "<")\
  TOKEN(TOKEN_GRTR, ">")\
  TOKEN(TOKEN_LE, "<=")\
  TOKEN(TOKEN_GE, ">=")\
  \
  TOKEN(TOKEN_NOT, "!")\
  TOKEN(TOKEN_OR, "||")\
  TOKEN(TOKEN_AND, "&&")\
  \
  TOKEN(TOKEN_BWOR, "|")\
  TOKEN(TOKEN_BWAND, "&")\
  \
  TOKEN(TOKEN_IDENT, "[identifier]")\
  TOKEN(TOKEN_INTEGER, "[integer]")\
  TOKEN(TOKEN_DECIMAL, "[float]")