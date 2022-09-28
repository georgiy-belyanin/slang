#include "out.h"

#include <llvm-c/Core.h>
#include <llvm-c/Transforms/PassManagerBuilder.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/TargetMachine.h>
#include <llvm-c/BitWriter.h>
#include "codegen.h"

static char* errors = 0;
static LLVMTargetMachineRef machine;

void out_init() {
  LLVMInitializeAllTargetInfos();
  LLVMInitializeAllTargets();
  LLVMInitializeAllTargetMCs();
  LLVMInitializeAllAsmParsers();
  LLVMInitializeAllAsmPrinters();

  LLVMPrintModuleToFile(module, "module.txt", &errors);

  LLVMTargetRef target;
  LLVMGetTargetFromTriple(LLVMGetDefaultTargetTriple(), &target, &errors);
  LLVMDisposeMessage(errors);
  machine = LLVMCreateTargetMachine(target, LLVMGetDefaultTargetTriple(), "generic", LLVMGetHostCPUFeatures(), LLVMCodeGenLevelDefault, LLVMRelocDefault, LLVMCodeModelDefault);

  LLVMSetTarget(module, LLVMGetDefaultTargetTriple());
  LLVMTargetDataRef datalayout = LLVMCreateTargetDataLayout(machine);
  char* datalayout_str = LLVMCopyStringRepOfTargetData(datalayout);
  LLVMSetDataLayout(module, datalayout_str);
  LLVMDisposeMessage(datalayout_str);

}

void out_obj(char* name) {
  LLVMTargetMachineEmitToFile(machine, module, "result.o", LLVMObjectFile, &errors); 
}