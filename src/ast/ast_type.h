#pragma once

typedef enum {
  AST_TY,

  AST_INT,
  AST_REAL,

  AST_VAR,
  AST_CALL,
  AST_BIN,

  AST_RET,
  AST_LET,
  AST_IF,
  AST_LOOP,
  AST_WHILE,
  AST_BODY,

  AST_FUNC_DECL,
  AST_FUNC,

} ast_type_t;
