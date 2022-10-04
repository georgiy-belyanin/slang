#pragma once

#include "../ast.h"
#include "codegen.h"
#include "unit.h"

unit_t* codegen_gen_ty(codegen_t* codegen, ty_ast_t* ty_ast);
unit_t* codegen_gen_ptr_ty(codegen_t* codegen, ptr_ty_ast_t* ptr_ty_ast);
unit_t* codegen_gen_arr_ty(codegen_t* codegen, arr_ty_ast_t* arr_ty_ast);
unit_t* codegen_gen_uptr_ty(codegen_t* codegen, uptr_ty_ast_t* uptr_ty_ast);
unit_t* codegen_gen_sptr_ty(codegen_t* codegen, sptr_ty_ast_t* sptr_ty_ast);
