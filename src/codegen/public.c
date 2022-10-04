#include "public.h"

#include <stdlib.h>
#include <llvm-c/Core.h>
#include "bin_codegen.h"
#include "body_codegen.h"
#include "call_codegen.h"
#include "func_decl_codegen.h"
#include "func_codegen.h"
#include "if_codegen.h"
#include "int_codegen.h"
#include "let_codegen.h"
#include "loop_codegen.h"
#include "real_codegen.h"
#include "ret_codegen.h"
#include "struct_codegen.h"
#include "ty_codegen.h"
#include "var_codegen.h"
#include "while_codegen.h"

codegen_t* create_codegen() {
  codegen_t* codegen = malloc(sizeof(codegen_t));
  codegen->context = LLVMContextCreate();
  codegen->module = LLVMModuleCreateWithNameInContext("slang_module", codegen->context);
  codegen->builder = LLVMCreateBuilderInContext(codegen->context);

  codegen->scope = create_scope();
  codegen->tys = create_tys(codegen->context);
  codegen->structs = create_structs();

  return codegen;
}
void destroy_codegen(codegen_t* codegen) {
  destroy_scope(codegen->scope);
  destroy_tys(codegen->tys);
  free(codegen);
}

unit_t* codegen_gen(codegen_t* codegen, ast_t* ast) {
  if (ast == NULL)
    return NULL;
  if (ast->type == AST_BIN)
    return codegen_gen_bin(codegen, (bin_ast_t*) ast);
  else if (ast->type == AST_BODY)
    return codegen_gen_body(codegen, (body_ast_t*) ast);
  else if (ast->type == AST_CALL)
    return codegen_gen_call(codegen, (call_ast_t*) ast);
  else if (ast->type == AST_FUNC_DECL)
    return codegen_gen_func_decl(codegen, (func_decl_ast_t*) ast);
  else if (ast->type == AST_FUNC)
    return codegen_gen_func(codegen, (func_ast_t*) ast);
  else if (ast->type == AST_IF)
    return codegen_gen_if(codegen, (if_ast_t*) ast);
  else if (ast->type == AST_INT)
    return codegen_gen_int(codegen, (int_ast_t*) ast);
  else if (ast->type == AST_LET)
    return codegen_gen_let(codegen, (let_ast_t*) ast);
  else if (ast->type == AST_LOOP)
    return codegen_gen_loop(codegen, (loop_ast_t*) ast);
  else if (ast->type == AST_PTR_TY)
    return codegen_gen_ptr_ty(codegen, (ptr_ty_ast_t*) ast);
  else if (ast->type == AST_REAL)
    return codegen_gen_real(codegen, (real_ast_t*) ast);
  else if (ast->type == AST_RET)
    return codegen_gen_ret(codegen, (ret_ast_t*) ast);
  else if (ast->type == AST_STRUCT)
    return codegen_gen_struct(codegen, (struct_ast_t*) ast);
  else if (ast->type == AST_TY)
    return codegen_gen_ty(codegen, (ty_ast_t*) ast);
  else if (ast->type == AST_VAR)
    return codegen_gen_var(codegen, (var_ast_t*) ast);
  else if (ast->type == AST_WHILE)
    return codegen_gen_while(codegen, (while_ast_t*) ast);
  return NULL;
}

void codegen_dump(codegen_t* codegen) {
  LLVMDumpModule(codegen->module);
}



#include <llvm-c/Transforms/PassManagerBuilder.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/TargetMachine.h>
#include <llvm-c/BitWriter.h>

struct out_t {
  LLVMModuleRef module;
  LLVMTargetMachineRef machine;
};

out_t* create_out(codegen_t* codegen) {
  out_t* out = malloc(sizeof(out_t));
  out->module = codegen->module;

  char* errors = calloc(sizeof(char), 1024);

  LLVMInitializeAllTargetInfos();
  LLVMInitializeAllTargets();
  LLVMInitializeAllTargetMCs();
  LLVMInitializeAllAsmParsers();
  LLVMInitializeAllAsmPrinters();


  LLVMTargetRef target;
  LLVMGetTargetFromTriple(LLVMGetDefaultTargetTriple(), &target, &errors);
  LLVMDisposeMessage(errors);
  out->machine = LLVMCreateTargetMachine(target, LLVMGetDefaultTargetTriple(), "generic", LLVMGetHostCPUFeatures(), LLVMCodeGenLevelDefault, LLVMRelocDefault, LLVMCodeModelDefault);

  LLVMSetTarget(out->module, LLVMGetDefaultTargetTriple());
  LLVMTargetDataRef datalayout = LLVMCreateTargetDataLayout(out->machine);
  char* datalayout_str = LLVMCopyStringRepOfTargetData(datalayout);
  LLVMSetDataLayout(out->module, datalayout_str);
  LLVMDisposeMessage(datalayout_str);

  return out;
}
void destroy_out(out_t* out) {
  free(out);
}

void out_obj(out_t* out, char* name) {
  char* errors = calloc(sizeof(char), 1024);

  LLVMTargetMachineEmitToFile(out->machine, out->module, name, LLVMObjectFile, &errors); 
}
void out_txt(out_t* out, char* name) {
  char* errors = calloc(sizeof(char), 1024);
  
  LLVMPrintModuleToFile(out->module, "module.txt", &errors);
}


#include <stdio.h>

struct in_t {

};

in_t* create_in() {
  in_t* in = malloc(sizeof(in_t));
  return in;
}
void destroy_in(in_t* in) {
  free(in);
}

char* in_read(in_t* in, char* filename) {
  FILE *f = fopen(filename, "rb");

  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

  char* content = malloc(fsize + 1);
  fread(content, fsize, 1, f);
  fclose(f);

  content[fsize] = EOF;
  
  return content;
}
