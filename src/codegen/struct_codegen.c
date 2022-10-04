#include "struct_codegen.h"

#include <stdlib.h>
#include <llvm-c/Core.h>
#include "public.h"

unit_t* codegen_gen_struct(codegen_t* codegen, struct_ast_t* struct_ast) {
  char* name = struct_ast->name;
  body_ast_t* body_ast = (body_ast_t*) struct_ast->body;

  int field_count = body_ast->stmt_count;
  char** fields = calloc(sizeof(char*), field_count);
  unit_t** field_tys = calloc(sizeof(unit_t*), field_count);

  for(int i = 0; i < field_count; i++) {
    let_ast_t* let_ast = (let_ast_t*) body_ast->stmts[i];

    fields[i] = let_ast->name;
    field_tys[i] = codegen_gen(codegen, let_ast->ty);
  }


  unit_t* ty = LLVMStructCreateNamed(codegen->context, name);
  LLVMStructSetBody(ty, (LLVMTypeRef*) field_tys, field_count, 0);

  codegen_tys_set(codegen, name, ty);
  codegen_structs_set(codegen, name, fields, field_tys, field_count);

  return NULL;
}
