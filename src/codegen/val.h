#pragma once

#include "unit.h"

typedef struct {
  unit_t* val;
  unit_t* ty;
} rval_t;

rval_t* create_rval(unit_t* val, unit_t* ty);
void destroy_rval(rval_t* rval);

typedef struct {
  unit_t* val;
  unit_t* ty;
  unit_t* ptr;
} lval_t;

lval_t* create_lval(unit_t* val, unit_t* ty, unit_t* ptr);
void destroy_lval(lval_t* lval);
