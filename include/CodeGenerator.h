//==============================================================================
// FILE:
//    CodeGenerator.h
//
// DESCRIPTION:
//    Declares the CodeGenerator Passes
//
// License: MIT
//==============================================================================
#ifndef LLVM_PASS_CODEGENERATOR_H
#define LLVM_PASS_CODEGENERATOR_H

#include "llvm/ADT/StringMap.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include <llvm/ADT/StringRef.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Module.h>
#include <vector>

//------------------------------------------------------------------------------
// New PM interface
//------------------------------------------------------------------------------

struct CodeGenerator : public llvm::PassInfoMixin<CodeGenerator> {
  llvm::PreservedAnalyses run(llvm::Module &M,
                              llvm::ModuleAnalysisManager &);

  static bool isRequired() { return true; }

private:
  // A special type used by analysis passes to provide an address that
  // identifies that particular analysis pass type.
  static llvm::AnalysisKey Key;
  friend struct llvm::AnalysisInfoMixin<CodeGenerator>;
};

#endif
