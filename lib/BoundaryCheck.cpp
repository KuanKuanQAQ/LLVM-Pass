//=============================================================================
// FILE:
//    OpcodeCounter.cpp
//
// DESCRIPTION:
//    Visits all instructions in a function and counts how many times every
//    LLVM IR opcode was used. Prints the output to stderr.
//
//    This example demonstrates how to insert your pass at one of the
//    predefined extension points, e.g. whenever the vectoriser is run (i.e. via
//    `registerVectorizerStartEPCallback` for the new PM).
//
// USAGE:
//    1. New PM
//      opt -load-pass-plugin libOpcodeCounter.dylib `\`
//        -passes="print<opcode-counter>" `\`
//        -disable-output <input-llvm-file>
//    2. Automatically through an optimisation pipeline - new PM
//      opt -load-pass-plugin libOpcodeCounter.dylib --passes='default<O1>' `\`
//        -disable-output <input-llvm-file>
//
// License: MIT
//=============================================================================
#include "BoundaryCheck.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/IR/InstIterator.h"
#include <llvm-17/llvm/Support/Casting.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Module.h>
#include <unordered_set>

using namespace llvm;

// Pretty-prints the result of this analysis
static void printBoundaryCheckResult(raw_ostream&,
                                     const ResultBoundaryCheck& OC);

//-----------------------------------------------------------------------------
// ExportCheck implementation
//-----------------------------------------------------------------------------
AnalysisKey BoundaryCheck::Key;

// BoundaryCheck::Result BoundaryCheck::computeImportedFuncs(Module& M) {
void BoundaryCheck::computeImportedFuncs(Module& M) {
  // Result res;
	for (auto& F : M) {
		std::string func_name = F.getName().str();
		if (F.isDeclaration()) {
			res[func_name] = "imported";
		} else {
			res[func_name] = "other";
		}
	}
	return;
}

void BoundaryCheck::computeExportedFuncs(Module& M) {
	for (Module::const_global_iterator global_var = M.global_begin();
	     global_var != M.global_end(); ++global_var) {
		Type* global_type = global_var->getValueType();
		if (global_var->hasInitializer() && global_type->isStructTy()) {
      for (unsigned i = 0; i < global_type->getStructNumElements(); ++i) {
        auto struct_element =
            global_var->getInitializer()->getAggregateElement(i);
        if (struct_element == nullptr)
          continue;
        Type *element_type = struct_element->getType();
        if (element_type->isPointerTy()) {
          auto* gep = dyn_cast<GetElementPtrInst>(element_type);
            Type *pointee_type = element_type;
            if (pointee_type->isFunctionTy()) {
              if (auto *FuncPtr = dyn_cast<ConstantExpr>(struct_element)) {
                if (FuncPtr->getOpcode() == Instruction::BitCast) {
                  if (auto *F = dyn_cast<Function>(FuncPtr->getOperand(0))) {
                    errs() << "  Function Pointer: " << F->getName() << "\n";
                  }
                }
              }
            }
          }
      }
		}
	}
  return;
}



// void BoundaryCheck::computeAddressTakenFuncs(Module& M) {
// 	for (Function& F : M) {
// 		for (Instruction& I : instructions(F)) {
// 			if (auto* callInst = dyn_cast<CallBase>(&I)) {
// 				if (Function* calledFunc = callInst->getCalledFunction()) {
//           Result[calledFunc->getName().str()] = "addressTaken1";
// 				}
// 			} else if (auto* storeInst = dyn_cast<StoreInst>(&I)) {
// 				if (Function* storedFunc =
// 				        dyn_cast<Function>(storeInst->getValueOperand())) {
//           Result[storedFunc->getName().str()] = "addressTaken2";
// 				}
// 			} else if (auto* bitCastInst = dyn_cast<BitCastInst>(&I)) {
// 				if (Function* bitCastedFunc =
// 				        dyn_cast<Function>(bitCastInst->getOperand(0))) {
//           Result[bitCastedFunc->getName().str()] = "addressTaken3";

// 				}
// 			} else if (auto* gepInst = dyn_cast<GetElementPtrInst>(&I)) {
// 				if (Function* gepFunc =
// 				        dyn_cast<Function>(gepInst->getPointerOperand())) {
//           Result[gepFunc->getName().str()] = "addressTaken4";
// 				}
// 			}
// 		}
// 	}
//   return;
// }

PreservedAnalyses BoundaryCheckPrinter::run(Module& M,
                                            ModuleAnalysisManager& MAM) {
	auto& CheckResult = MAM.getResult<BoundaryCheck>(M);

	// In the legacy PM, the following string is printed automatically by
	// the pass manager. For the sake of consistency, we're adding this here
	// so that it's also printed when using the new PM.
	OS << "Printing analysis 'BoundaryCheck Pass' for module '" << M.getName()
	   << "':\n";

	printBoundaryCheckResult(OS, CheckResult);
	return PreservedAnalyses::all();
}

PassPluginLibraryInfo getBoundaryCheckPluginInfo() {
	return {LLVM_PLUGIN_API_VERSION, "BoundaryCheck", LLVM_VERSION_STRING,
	        [](PassBuilder& PB) {
		        PB.registerPipelineStartEPCallback(
		            [](ModulePassManager& PM, OptimizationLevel Level) {
			            PM.addPass(BoundaryCheckPrinter(errs()));
		            });
		        PB.registerAnalysisRegistrationCallback(
		            [](ModuleAnalysisManager& MAM) {
			            MAM.registerPass([&] { return BoundaryCheck(); });
		            });
	        }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::PassPluginLibraryInfo llvmGetPassPluginInfo() {
	return getBoundaryCheckPluginInfo();
}

//------------------------------------------------------------------------------
// Helper functions - implementation
//------------------------------------------------------------------------------
static void printBoundaryCheckResult(raw_ostream& OutS,
                                     const ResultBoundaryCheck& FuncsType) {
	OutS << "================================================="
	     << "\n";
	OutS << "LLVM-PASS: BoundaryCheck results\n";
	OutS << "=================================================\n";
	const char* str1 = "FUNCS";
	const char* str2 = "TYPE";
	OutS << format("%-20s %-10s\n", str1, str2);
	OutS << "-------------------------------------------------"
	     << "\n";
	for (auto& Inst : FuncsType) {
		OutS << format("%-20s %-10s\n", Inst.first().str().c_str(),
		               Inst.second.str().c_str());
	}
	OutS << "-------------------------------------------------"
	     << "\n\n";
}
