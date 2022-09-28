#include "val.h"

#include <stdlib.h>

rval_t* create_rval(unit_t* val, unit_t* ty) {
  rval_t* rval = malloc(sizeof(rval_t));
  rval->val = val;
  rval->ty = ty;
  return rval;
}
void destroy_rval(rval_t* rval) {
  free(rval);
}

lval_t* create_lval(unit_t* val, unit_t* ty, unit_t* ptr) {
  lval_t* lval = malloc(sizeof(lval_t));
  lval->val = val;
  lval->ty = ty;
  lval->ptr = ptr;
  return lval;
}
void destroy_lval(lval_t* lval) {
  free(lval);
}
