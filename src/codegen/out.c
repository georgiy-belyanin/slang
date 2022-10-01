// #include "out.h"

// #include <llvm-c/Core.h>
// #include <llvm-c/Transforms/PassManagerBuilder.h>
// #include <llvm-c/Analysis.h>
// #include <llvm-c/TargetMachine.h>
// #include <llvm-c/BitWriter.h>
// #include "codegen.h"

// static char* errors = 0;
// static LLVMTargetMachineRef machine;

// void out_init(codegen_t* codegen) {
//   LLVMInitializeAllTargetInfos();
//   LLVMInitializeAllTargets();
//   LLVMInitializeAllTargetMCs();
//   LLVMInitializeAllAsmParsers();
//   LLVMInitializeAllAsmPrinters();

//   LLVMPrintModuleToFile(codegen->module, "module.txt", &errors);

//   LLVMTargetRef target;
//   LLVMGetTargetFromTriple(LLVMGetDefaultTargetTriple(), &target, &errors);
//   LLVMDisposeMessage(errors);
//   machine = LLVMCreateTargetMachine(target, LLVMGetDefaultTargetTriple(), "generic", LLVMGetHostCPUFeatures(), LLVMCodeGenLevelDefault, LLVMRelocDefault, LLVMCodeModelDefault);

//   LLVMSetTarget(codegen->module, LLVMGetDefaultTargetTriple());
//   LLVMTargetDataRef datalayout = LLVMCreateTargetDataLayout(machine);
//   char* datalayout_str = LLVMCopyStringRepOfTargetData(datalayout);
//   LLVMSetDataLayout(codegen->module, datalayout_str);
//   LLVMDisposeMessage(datalayout_str);

// }

// void out_obj(codegen_t* codegen, char* name) {
//   LLVMTargetMachineEmitToFile(machine, codegen->module, "result.o", LLVMObjectFile, &errors); 
// }