#include "tys.h"

#include "../etc.h"
#include "codegen.h"

static hashmap_t* tys;

void tys_init() {
  tys = create_hashmap();

  hashmap_set(tys, "i8", LLVMInt8TypeInContext(context));
  hashmap_set(tys, "i16", LLVMInt16TypeInContext(context));
  hashmap_set(tys, "i32", LLVMInt32TypeInContext(context));
  hashmap_set(tys, "i64", LLVMInt64TypeInContext(context));

  hashmap_set(tys, "f32", LLVMFloatTypeInContext(context));
  hashmap_set(tys, "f64", LLVMDoubleTypeInContext(context));

  hashmap_set(tys, "bool", LLVMInt1TypeInContext(context));
}
unit_t* tys_get(char* name) {
  return hashmap_get(tys, name);
}