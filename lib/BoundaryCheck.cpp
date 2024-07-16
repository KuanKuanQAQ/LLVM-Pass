//=============================================================================
// FILE:
//    BoundaryCheck.cpp
//
// DESCRIPTION:
//    ...
//
// USAGE:
//    clang -S -fpass-plugin=./lib/libBoundaryCheck.so -c <input-c-file>
//
// License: MIT
//=============================================================================
#include "BoundaryCheck.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include <llvm-17/llvm/IR/GlobalIFunc.h>
#include <llvm-17/llvm/IR/GlobalVariable.h>
#include <llvm-17/llvm/Support/Casting.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Module.h>
#include <unordered_set>

using namespace llvm;

// Pretty-prints the result of this analysis
static void printBoundaryCheckResult(raw_ostream &,
                                     const ResultBoundaryCheck &OC);

//-----------------------------------------------------------------------------
// ExportCheck implementation
//-----------------------------------------------------------------------------
AnalysisKey BoundaryCheck::Key;

void BoundaryCheck::computeImportedFuncs(Module &M) {
  // Result res;
  for (auto &F : M) {
    std::string func_name = F.getName().str();
    if (F.isDeclaration()) {
      res[func_name] = "imported";
    } else {
      res[func_name] = "other";
    }
  }
  return;
}

void BoundaryCheck::computeExportedFuncs(Module &M) {
  for (GlobalVariable &GV : M.globals()) {
    if (dyn_cast<StructType>(GV.getValueType())) {
      if (!GV.hasInitializer())
        continue;
      TinyPtrVector<Constant *> workqueue;
      workqueue.push_back(GV.getInitializer());
      res[GV.getName()] = "processing struct";
      while (!workqueue.empty()) {
        Constant *C = workqueue.back();
        workqueue.pop_back();

        if (ConstantStruct *CS = dyn_cast<ConstantStruct>(C)) {
          for (unsigned i = 0; i < CS->getNumOperands(); ++i) {
            Constant *Op = CS->getOperand(i);

            if (dyn_cast<StructType>(Op->getType())) {
              if (Constant *InnerC = dyn_cast<Constant>(Op)) {
                workqueue.push_back(InnerC);
              }
            } else if (Function *F = dyn_cast<Function>(Op)) {
              res[F->getName()] = "exported";
            }
          }
        }
      }
      res[GV.getName()] = "struct";
    }
  }
  return;
}

PreservedAnalyses BoundaryCheckPrinter::run(Module &M,
                                            ModuleAnalysisManager &MAM) {
  auto &CheckResult = MAM.getResult<BoundaryCheck>(M);

  OS << "Printing analysis 'BoundaryCheck Pass' for module '" << M.getName()
     << "':\n";

  printBoundaryCheckResult(OS, CheckResult);
  return PreservedAnalyses::all();
}

PassPluginLibraryInfo getBoundaryCheckPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "BoundaryCheck", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineStartEPCallback(
                [](ModulePassManager &PM, OptimizationLevel Level) {
                  PM.addPass(BoundaryCheckPrinter(errs()));
                });
            PB.registerAnalysisRegistrationCallback(
                [](ModuleAnalysisManager &MAM) {
                  MAM.registerPass([&] { return BoundaryCheck(); });
                });
          }};
}

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return getBoundaryCheckPluginInfo();
}

//------------------------------------------------------------------------------
// Helper functions - implementation
//------------------------------------------------------------------------------
static void printBoundaryCheckResult(raw_ostream &OutS,
                                     const ResultBoundaryCheck &Res) {
  OutS << "================================================="
       << "\n";
  OutS << "LLVM-PASS: BoundaryCheck results\n";
  OutS << "=================================================\n";
  const char *str1 = "SYMBOL";
  const char *str2 = "TYPE";
  OutS << format("%-20s %-10s\n", str1, str2);
  OutS << "-------------------------------------------------"
       << "\n";
  for (auto &Inst : Res) {
    OutS << format("%-20s %-10s\n", Inst.first().str().c_str(),
                   Inst.second.str().c_str());
  }
  OutS << "-------------------------------------------------"
       << "\n\n";
}
