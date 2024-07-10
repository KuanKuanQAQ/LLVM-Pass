//==============================================================================
// FILE:
//    OpcodeCounter.h
//
// DESCRIPTION:
//    Declares the OpcodeCounter Passes:
//      * new pass manager interface
//      * printer pass for the new pass manager
//
// License: MIT
//==============================================================================
#ifndef LLVM_TUTOR_OPCODECOUNTER_H
#define LLVM_TUTOR_OPCODECOUNTER_H

#include "llvm/ADT/StringMap.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include <llvm/IR/Module.h>

//------------------------------------------------------------------------------
// New PM interface
//------------------------------------------------------------------------------
using ResultBoundaryCheck = llvm::StringMap<llvm::StringRef>;

struct BoundaryCheck : public llvm::AnalysisInfoMixin<BoundaryCheck> {
  using Result = ResultBoundaryCheck;
  Result res;
  
  Result run(llvm::Module &M, llvm::ModuleAnalysisManager &) {
    computeImportedFuncs(M);
    return res;
  }

  void computeImportedFuncs(llvm::Module &M);
  void computeExportedFuncs(llvm::Module &M);
  void computeAddressTakenFuncs(llvm::Module &M);

  // Part of the official API:
  //  https://llvm.org/docs/WritingAnLLVMNewPMPass.html#required-passes
  static bool isRequired() { return true; }

private:
  // A special type used by analysis passes to provide an address that
  // identifies that particular analysis pass type.
  static llvm::AnalysisKey Key;
  friend struct llvm::AnalysisInfoMixin<BoundaryCheck>;
};

//------------------------------------------------------------------------------
// New PM interface for the printer pass
//------------------------------------------------------------------------------
class BoundaryCheckPrinter : public llvm::PassInfoMixin<BoundaryCheckPrinter> {
public:
  explicit BoundaryCheckPrinter(llvm::raw_ostream &OutS) : OS(OutS) {}
  llvm::PreservedAnalyses run(llvm::Module &Module,
                              llvm::ModuleAnalysisManager &MAM);
  // Part of the official API:
  //  https://llvm.org/docs/WritingAnLLVMNewPMPass.html#required-passes
  static bool isRequired() { return true; }

private:
  llvm::raw_ostream &OS;
};
#endif
