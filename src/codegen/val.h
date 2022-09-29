#pragma once

#include "unit.h"


typedef enum {
  VAL_RVAL,
  VAL_LVAL
} val_type_t;

typedef struct {
  val_type_t type;
  unit_t* val;
  unit_t* ty;
} rval_t;

typedef struct {
  val_type_t type;
  unit_t* val;
  unit_t* ty;
} val_t;

rval_t* create_rval(unit_t* val, unit_t* ty);
void destroy_rval(rval_t* rval);

typedef struct {
  val_type_t type;
  unit_t* val;
  unit_t* ty;
  unit_t* ptr;
} lval_t;

lval_t* create_lval(unit_t* val, unit_t* ty, unit_t* ptr);
void destroy_lval(lval_t* lval);

int val_is_rval(val_t* val);
int val_is_lval(val_t* val);
int rval_is_lval(rval_t* rval);
