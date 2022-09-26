#include "codegen_ty.h"

#include <string.h>
#include <llvm-c/Core.h>
#include "codegen.h"

unit_t* codegen_ty(ty_ast_t* ty_ast) {
  if (strcmp(ty_ast->name, "i8") == 0) 
    return LLVMInt8TypeInContext(context);
  else if (strcmp(ty_ast->name, "i16") == 0) 
    return LLVMInt16TypeInContext(context);
  else if (strcmp(ty_ast->name, "i32") == 0)  {
    return LLVMInt32TypeInContext(context);
  }
  else if (strcmp(ty_ast->name, "i64") == 0) 
    return LLVMInt64TypeInContext(context);
  return NULL;
}
