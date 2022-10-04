#pragma once

typedef enum {
  OP_UNKNOWN,

  OP_ASSIGN,

  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV,

  OP_EQ,
  OP_NE,
  OP_LESS,
  OP_GRTR,
  OP_LE,
  OP_GE,

  OP_AND,
  OP_OR,

  OP_BWAND,
  OP_BWOR,

  OP_MINUS,
  OP_NOT,

  OP_DOT
} op_t;