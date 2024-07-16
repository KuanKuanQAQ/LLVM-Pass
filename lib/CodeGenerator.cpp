//=============================================================================
// FILE:
//    CodeGenerator.cpp
//
// DESCRIPTION:
//    ...
//
// USAGE:
//    clang -S -fpass-plugin=./lib/libCodeGenerator.so -c <input-c-file>
//
// License: MIT
//=============================================================================
#include "CodeGenerator.h"
#include "BoundaryCheck.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include <llvm-17/llvm/IR/GlobalIFunc.h>
#include <llvm-17/llvm/IR/GlobalVariable.h>
#include <llvm-17/llvm/Support/Casting.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>
#include <unordered_set>

#define DEBUG_TYPE "codegenerator"
using namespace llvm;

//-----------------------------------------------------------------------------
// CodeGenerator implementation
//-----------------------------------------------------------------------------

PreservedAnalyses CodeGenerator::run(Module &M, ModuleAnalysisManager &MAM) {
  auto &CheckResult = MAM.getResult<BoundaryCheck>(M);
  errs() << "CodeGenerator begin...\n";
  for (auto &F : M) {
    std::string func_name = F.getName().str();
    if (CheckResult[func_name] != "exported") continue;
    errs() << func_name << " is exported\n";
   // Save the function name
    std::string OrigName = F.getName().str();

    // Create a new name for the original function
    std::string NewName = OrigName + "_real";

    // Rename the original function
    F.setName(NewName);

    // Create the new function with the original name
    Function *NewFunc = Function::Create(F.getFunctionType(), F.getLinkage(), OrigName, F.getParent());

    // Create a basic block for the new function
    BasicBlock *BB = BasicBlock::Create(F.getContext(), "entry", NewFunc);
    IRBuilder<> Builder(BB);

    // Create the call to the original function
    std::vector<Value *> Args;
    for (auto &Arg : NewFunc->args()) {
      Args.push_back(&Arg);
    }

    CallInst *Call = Builder.CreateCall(&F, Args);
    if (F.getReturnType()->isVoidTy()) {
      Builder.CreateRetVoid();
    } else {
      Builder.CreateRet(Call);
    }

    // Update all uses of the original function to use the new function
    for (auto UI = F.use_begin(), UE = F.use_end(); UI != UE; ++UI) {
      if (CallInst *CI = dyn_cast<CallInst>(*UI)) {
        CI->setCalledFunction(NewFunc);
      }
    }
  }
    return PreservedAnalyses::none();
}

//------------------------------------------------------------------------------
// New PM Registration
//------------------------------------------------------------------------------
PassPluginLibraryInfo getCodeGeneratorPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "CodeGenerator", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            // PB.registerPipelineParsingCallback(
            //     [](StringRef Name, ModulePassManager &MPM,
            //        ArrayRef<PassBuilder::PipelineElement>) {
            //       if (Name == "CodeGenerator") {
            //         MPM.addPass(CodeGenerator());
            //         return true;
            //       }
            //       return false;
            //     });
            PB.registerPipelineStartEPCallback(
                [](ModulePassManager &PM, OptimizationLevel Level) {
                  PM.addPass(CodeGenerator());
                });
          }};
}

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return getCodeGeneratorPluginInfo();
}
