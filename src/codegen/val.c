#include "val.h"

#include <stdlib.h>

rval_t* create_rval(unit_t* val, unit_t* ty) {
  rval_t* rval = malloc(sizeof(rval_t));
  
  rval->type = VAL_RVAL;
  rval->val = val;
  rval->ty = ty;

  return rval;
}
void destroy_rval(rval_t* rval) {
  free(rval);
}

lval_t* create_lval(unit_t* val, unit_t* ty, unit_t* ptr) {
  lval_t* lval = malloc(sizeof(lval_t));

  lval->type = VAL_LVAL;
  lval->val = val;
  lval->ty = ty;
  lval->ptr = ptr;

  return lval;
}
void destroy_lval(lval_t* lval) {
  free(lval);
}

int val_is_rval(val_t* val) {
  return val->type == VAL_RVAL;
}
int val_is_lval(val_t* val) {
  return val->type == VAL_LVAL;
}
int rval_is_lval(rval_t* rval) {
  return rval->type == VAL_LVAL;
}
