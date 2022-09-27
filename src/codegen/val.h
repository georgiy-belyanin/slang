#pragma once

#include "unit.h"

typedef struct {
  unit_t* ty;
  unit_t* val;
} val_t;

val_t* create_val(unit_t* val1, unit_t* ty);