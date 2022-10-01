#include "tys.h"

#include <stdlib.h>
#include <llvm-c/Core.h>
#include "../etc.h"
#include "codegen.h"

struct tys_t {
  //LLVMContextRef context;
  hashmap_t* tys;
};

tys_t* create_tys(void* context) {
  tys_t* tys = malloc(sizeof(tys_t));
  tys->tys = create_hashmap();

  hashmap_set(tys->tys, "i8", LLVMInt8TypeInContext(context));
  hashmap_set(tys->tys, "i16", LLVMInt16TypeInContext(context));
  hashmap_set(tys->tys, "i32", LLVMInt32TypeInContext(context));
  hashmap_set(tys->tys, "i64", LLVMInt64TypeInContext(context));

  hashmap_set(tys->tys, "f32", LLVMFloatTypeInContext(context));
  hashmap_set(tys->tys, "f64", LLVMDoubleTypeInContext(context));

  hashmap_set(tys->tys, "bool", LLVMInt1TypeInContext(context));
  return tys;
}
void destroy_tys(tys_t* tys) {
  destroy_hashmap(tys->tys);
  free(tys);
}
unit_t* tys_get(tys_t* tys, char* name) {
  return hashmap_get(tys->tys, name);
}