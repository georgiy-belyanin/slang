#include "val.h"

#include <stdlib.h>
val_t* create_val(unit_t* val1, unit_t* ty) {
  val_t* val = malloc(sizeof(val_t));
  val->val = val1;
  val->ty = ty;
  return val;
}