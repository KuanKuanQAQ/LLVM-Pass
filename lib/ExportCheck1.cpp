#include <fstream>

#include "llvm/Analysis/CGSCCPassManager.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
#include <llvm-17/llvm/Support/Casting.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <llvm/Pass.h>
#include <llvm/Passes/OptimizationLevel.h>

#include <DebugInfoUtils.h>
#include <PDGUtils.h>


using namespace llvm;
#define DEBUG_TYPE "mypass"

cl::opt<std::string> BlackListFileName("libfile", cl::desc("Lib file"),
                                       cl::value_desc("lib filename"));

class TestPass {
public:
  std::set<std::string> _black_list_func_names;
  std::vector<std::string> _sentinel_fields;
  std::vector<std::string> _imported_funcs;
  std::vector<std::string> _exported_funcs;
  std::vector<std::string> _driver_domain_funcs;
  std::vector<std::string> _exported_func_ptrs;
  std::vector<std::string> _driver_globalvar_names;
  std::set<std::string> _exported_func_symbols;
  std::set<std::string> _global_op_struct_names;
  std::vector<std::string> _imported_vars;

  static StringRef name() {
    errs() << "name invoked\n";
    return "TestPass";
  }

  void printPipeline(raw_ostream &OS,
                     function_ref<StringRef(StringRef)> MapClassName2PassName) {
    StringRef ClassName = name();
    auto PassName = MapClassName2PassName(ClassName);
    OS << PassName;
  }

  static bool isRequired() {
    errs() << "isRequired invoked\n";
    return true;
  }

  bool runOnModule(llvm::Module &M);

  PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
    errs() << "Module name is " << M.getName() << "!\n";
    bool Changed = runOnModule(M);

    return (Changed ? llvm::PreservedAnalyses::none()
                    : llvm::PreservedAnalyses::all());
  }

  void setupBlackListFuncNames() {
    // some default filters
    _black_list_func_names.insert("llvm");
    // read default library func list from liblcd_func.txt
    if (BlackListFileName.empty())
      BlackListFileName = "liblcd_funcs.txt";
    std::ifstream black_list_func_file(BlackListFileName);
    if (!black_list_func_file) {
      errs() << "fail to locate black list function file!\n";
      return;
    }

    for (std::string line; std::getline(black_list_func_file, line);) {
      _black_list_func_names.insert(line);
    }
  }

  std::string stripFuncNameVersionNumber(std::string func_name) {
    auto deli_pos = func_name.find('.');
    if (deli_pos == std::string::npos)
      return func_name;
    return func_name.substr(0, deli_pos);
  }

  void computeDriverImportedFuncs(llvm::Module &M) {
    outs() << "imported funcs " << "\n";
    for (auto &F : M) {
      if (F.isDeclaration()) {
        std::string func_name = F.getName().str();
        func_name = stripFuncNameVersionNumber(func_name);
        if (isBlackListFunc(func_name))
          continue;
        _imported_funcs.push_back(func_name);
        outs() << func_name << ' ';
      }
    }
    outs() << "\n";
  }

  void computeDriverFuncs(llvm::Module &M) {
    outs() << "local funcs " << "\n";
    for (auto &F : M) {
      if (F.isDeclaration())
        continue;
      std::string func_name = F.getName().str();
      func_name = stripFuncNameVersionNumber(func_name);
      if (isBlackListFunc(func_name))
        continue;
      _driver_domain_funcs.push_back(func_name);
      outs() << func_name << ' ';
    }
    outs() << "\n";
  }

  void computeExportedFuncs(llvm::Module &M) {
    outs() << "exported funcs " << "\n";
    // read shared struct type names if exist
    std::set<std::string> shared_struct_type_names;
    std::ifstream shared_struct_name_file("shared_struct_types");
    if (shared_struct_name_file.good()) {
      // read shared data types
      for (std::string line; std::getline(shared_struct_name_file, line);) {
        shared_struct_type_names.insert(line);
      }
    }

    // used to store driver global
    std::ofstream driver_global_struct_types("driver_global_struct_types");
    for (Module::const_global_iterator global_var = M.global_begin();
         global_var != M.global_end(); ++global_var) {
      SmallVector<DIGlobalVariableExpression *, 4> sv;
      outs() << global_var->getName().str() << "\n";
      if (!global_var->hasInitializer()) {
        outs() << "no initializer \n";
        continue;
      }

      outs() << "has Initializer: " << global_var->getName().str() << "\n";
      DIGlobalVariable *di_gv = nullptr;
      global_var->getDebugInfo(sv);
      for (auto di_expr : sv) {
        outs() << "di_expr: ";
        di_expr->print(outs());
        outs() << "\n";
        if (di_expr->getVariable()->getName() == global_var->getName())
          di_gv =
              di_expr
                  ->getVariable(); // get global variable from global expression
      }
      if (!di_gv) {
        outs() << "no debuginfo: " << global_var->getName().str() << "\n";
        continue;
      }

      // if (!global_var.isConstant() && global_var.hasInitializer())
      if (global_var->hasInitializer()) {
        _driver_globalvar_names.push_back(global_var->getName().str());
        outs() << "has Initializer: " << global_var->getName().str() << "\n";
      }

      auto gv_di_type = di_gv->getType();
      auto gv_lowest_di_type = pdg::dbgutils::getLowestDIType(*gv_di_type);
      if (!gv_lowest_di_type ||
          gv_lowest_di_type->getTag() != dwarf::DW_TAG_structure_type)
        continue;
      auto gv_di_type_name =
          pdg::dbgutils::getSourceLevelTypeName(*gv_lowest_di_type, true);
      auto gv_name = global_var->getName().str();
      outs() << "gv_name: " << gv_name << "\n";
      gv_di_type_name = pdg::pdgutils::stripVersionTag(gv_di_type_name);
      // if (!shared_struct_type_names.empty() &&
      // shared_struct_type_names.find(gv_di_type_name) ==
      // shared_struct_type_names.end())
      //   continue;
      driver_global_struct_types << gv_di_type_name << "\n";
      // if (remove_ops.find(gv_di_type_name) != remove_ops.end())
      //   continue;

      const auto &typeArrRef =
          dyn_cast<DICompositeType>(gv_lowest_di_type)->getElements();
      Type *global_type = global_var->getValueType();
      if (auto t = dyn_cast<PointerType>(global_type)) {
        outs() << "it can be transform to pointertype\n";
        // global_type = t->getType();
      }
      if (auto t = dyn_cast<StructType>(global_type)) {
        outs() << "it can be transform to Structtype\n";
        // global_type = t->getElementType();
      }
      if (!global_type->isStructTy()) {
        outs() << "is not structty!!\n";
        outs() << global_type->getTypeID() << "\n";
        continue;
      }
      if (global_type->getStructNumElements() != typeArrRef.size()) {
        outs() << "sth wrong, but unknown\n";
        continue;
      }

      outs() << "cnt " << global_type->getStructNumElements() << "\n";
      for (unsigned i = 0; i < global_type->getStructNumElements(); ++i) {
        auto struct_element =
            global_var->getInitializer()->getAggregateElement(i);
        if (struct_element == nullptr)
          continue;
        std::string field_type_name = struct_element->getName().str();
        outs() << "field_type_name: " << field_type_name << "\n";
        if (DIType *struct_field_di_type = dyn_cast<DIType>(typeArrRef[i])) {
          // // if the field is a function pointer, directly print it to map
          // std::string field_type_name = struct_element->getName().str();
          // // if a field is a user of sentinel array (hold the content of
          // // sentinel array), then we need to record it and synchronize this
          // // field with special syntax in IDL generation
          // if (pdg::pdgutils::isUserOfSentinelTypeVal(*struct_element))
          //   _sentinel_fields.push_back(
          //       pdg::dbgutils::getSourceLevelVariableName(*struct_field_di_type));

          // // extract all the function pointer name exported by the driver
          // if (!field_type_name.empty()) {
          //   std::string field_source_name =
          //       pdg::dbgutils::getSourceLevelVariableName(*struct_field_di_type);
          //   // concate the ptr name with the outer ops struct name
          //   field_source_name = gv_di_type_name + "_" + field_source_name;
          //   if (pdg::dbgutils::isFuncPointerType(*struct_field_di_type)) {
          //     _exported_func_ptrs.push_back(field_source_name);
          //     _exported_funcs.push_back(field_type_name);
          //     _global_op_struct_names.insert(gv_di_type_name);
          //   }
          // }
          // // TODO: handle nested structs
          processStructElement(struct_element, struct_field_di_type,
                               gv_di_type_name);
        }
      }
    }
  }

  void processStructElement(Constant *struct_element,
                            DIType *struct_field_di_type,
                            const std::string &gv_di_type_name) {
    // outs() <<"processStructElement\n";

    // 如果struct_field_di_type是DICompositeType，说明是一个嵌套结构体
    if (auto compositeType = dyn_cast<DICompositeType>(struct_field_di_type)) {
      outs() << "嵌套结构体\n";

      const auto &elements = compositeType->getElements();
      Type *elementType = struct_element->getType();

      // 检查元素类型是否为结构体
      if (elementType->isStructTy()) {
        for (unsigned i = 0; i < elementType->getStructNumElements(); ++i) {
          auto nested_element = struct_element->getAggregateElement(i);
          if (nested_element == nullptr)
            continue;

          if (DIType *nested_field_di_type = dyn_cast<DIType>(elements[i])) {
            processStructElement(nested_element, nested_field_di_type,
                                 gv_di_type_name);
          }
        }
      }
    } else {
      // 处理非嵌套结构体成员
      outs() << "处理非嵌套结构体成员\n";

      std::string field_type_name = struct_element->getName().str();

      if (pdg::pdgutils::isUserOfSentinelTypeVal(*struct_element)) {
        _sentinel_fields.push_back(
            pdg::dbgutils::getSourceLevelVariableName(*struct_field_di_type));
      }

      if (!field_type_name.empty()) {
        std::string field_source_name =
            pdg::dbgutils::getSourceLevelVariableName(*struct_field_di_type);
        field_source_name = gv_di_type_name + "_" + field_source_name;

        if (pdg::dbgutils::isFuncPointerType(*struct_field_di_type)) {
          outs() << "gagagagag\n";
          outs() << field_source_name << " " << field_type_name << " "
                 << gv_di_type_name << "\n";
          _exported_func_ptrs.push_back(field_source_name);
          _exported_funcs.push_back(field_type_name);
          _global_op_struct_names.insert(gv_di_type_name);
        }
      }
    }
  }

  void computeImportedGVs(llvm::Module &M) {
    outs() << "imported GV " << "\n";
    for (Module::const_global_iterator it = M.global_begin();
         it != M.global_end(); ++it) {
      if (it->isDeclaration()) {
        _imported_vars.push_back(it->getName().str());
        outs() << it->getName().str() << ' ';
      }
    }
    outs() << "\n";
  }

  void computeExportedFuncSymbols(llvm::Module &M) {
    outs() << "exported func symbols " << "\n";
    for (Module::const_global_iterator it = M.global_begin();
         it != M.global_end(); ++it) {
      auto name = it->getName().str();
      // look for global name starts with __ksymtab or __kstrtab
      if (name.find("__ksymtab_") == 0 || name.find("__kstrtab_") == 0) {
        std::string func_name = name.erase(0, 10);
        Function *f = M.getFunction(StringRef(func_name));
        if (f != nullptr) {
          _exported_func_symbols.insert(func_name);
          outs() << func_name << ' ';
        }
      }
    }
    outs() << "\n";
  }

  void dumpToFiles() {
    errs() << "dumping to files\n";
    dumpToFile("imported_funcs", _imported_funcs);
    dumpToFile("driver_funcs", _driver_domain_funcs);
    dumpToFile("exported_funcs", _exported_funcs);
    dumpToFile("exported_func_ptrs", _exported_func_ptrs);
    dumpToFile("sentinel_fields", _sentinel_fields);
    dumpToFile("driver_globalvar_names", _driver_globalvar_names);
    std::vector<std::string> exported_func_symbols(
        _exported_func_symbols.begin(), _exported_func_symbols.end());
    dumpToFile("driver_exported_func_symbols", exported_func_symbols);
    std::vector<std::string> global_op_struct_names(
        _global_op_struct_names.begin(), _global_op_struct_names.end());
    dumpToFile("global_op_struct_names", global_op_struct_names);
    dumpToFile("imported_vars", _imported_vars);
    errs() << "dumping finished\n";
  }

  void dumpToFile(std::string file_name, std::vector<std::string> &names) {
    std::ofstream output_file(file_name);
    for (auto name : names) {
      output_file << name << "\n";
    }
    output_file.close();
  }

  bool isBlackListFunc(std::string func_name) {
    return _black_list_func_names.find(func_name) !=
           _black_list_func_names.end();
  }
};

//-----------------------------------------------------------------------------
// InjectFuncCall implementation
//-----------------------------------------------------------------------------
bool TestPass::runOnModule(Module &M) {
  bool InsertedAtLeastOnePrintf = false;

  auto &CTX = M.getContext();
  PointerType *PrintfArgTy = PointerType::getUnqual(Type::getInt8Ty(CTX));

  // STEP 1: Inject the declaration of printf
  // ----------------------------------------
  // Create (or _get_ in cases where it's already available) the following
  // declaration in the IR module:
  //    declare i32 @printf(i8*, ...)
  // It corresponds to the following C declaration:
  //    int printf(char *, ...)
  FunctionType *PrintfTy =
      FunctionType::get(IntegerType::getInt32Ty(CTX), PrintfArgTy,
                        /*IsVarArgs=*/true);

  FunctionCallee Printf = M.getOrInsertFunction("aa", PrintfTy);

  // Set attributes as per inferLibFuncAttributes in BuildLibCalls.cpp
  Function *PrintfF = dyn_cast<Function>(Printf.getCallee());
  PrintfF->setDoesNotThrow();
  PrintfF->addParamAttr(0, Attribute::NoCapture);
  PrintfF->addParamAttr(0, Attribute::ReadOnly);

  // STEP 2: Inject a global variable that will hold the printf format string
  // ------------------------------------------------------------------------
  llvm::Constant *PrintfFormatStr = llvm::ConstantDataArray::getString(
      CTX,
      "(llvm-tutor) Hello from: %s\n(llvm-tutor)   number of arguments: %d\n");

  Constant *PrintfFormatStrVar =
      M.getOrInsertGlobal("PrintfFormatStr", PrintfFormatStr->getType());
  dyn_cast<GlobalVariable>(PrintfFormatStrVar)->setInitializer(PrintfFormatStr);

  // STEP 3: For each function in the module, inject a call to printf
  // ----------------------------------------------------------------
  for (auto &F : M) {
    if (F.isDeclaration())
      continue;

    // Get an IR builder. Sets the insertion point to the top of the function
    IRBuilder<> Builder(&*F.getEntryBlock().getFirstInsertionPt());

    // Inject a global variable that contains the function name
    auto FuncName = Builder.CreateGlobalStringPtr(F.getName());

    // Printf requires i8*, but PrintfFormatStrVar is an array: [n x i8]. Add
    // a cast: [n x i8] -> i8*
    llvm::Value *FormatStrPtr =
        Builder.CreatePointerCast(PrintfFormatStrVar, PrintfArgTy, "formatStr");

    // The following is visible only if you pass -debug on the command line
    // *and* you have an assert build.
    LLVM_DEBUG(dbgs() << " Injecting call to printf inside " << F.getName()
                      << "\n");

    // Finally, inject a call to printf
    Builder.CreateCall(
        Printf, {FormatStrPtr, FuncName, Builder.getInt32(F.arg_size())});

    InsertedAtLeastOnePrintf = true;
  }

  // setupBlackListFuncNames();
  computeDriverImportedFuncs(M); //
  computeDriverFuncs(M);
  computeExportedFuncs(M); //
  computeExportedFuncSymbols(M);
  computeImportedGVs(M);
  dumpToFiles();

  return InsertedAtLeastOnePrintf;
}

class HelloWorld {
public:
  static StringRef name() {
    errs() << "name invoked\n";
    return "HelloWorld";
  }

  void printPipeline(raw_ostream &OS,
                     function_ref<StringRef(StringRef)> MapClassName2PassName) {
    StringRef ClassName = name();
    auto PassName = MapClassName2PassName(ClassName);
    OS << PassName;
  }

  static bool isRequired() {
    errs() << "isRequired invoked\n";
    return true;
  }

  PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
    runOnFunction(F);
    errs() << "Function name is " << F.getName() << "!\n";
    return PreservedAnalyses::all();
  }
  bool runOnFunction(Function &F) {
    LLVMContext &Context = F.getContext();
    Module *M = F.getParent();
    IRBuilder<> Builder(Context);

    // 声明或获取函数x
    FunctionCallee FuncX = M->getOrInsertFunction(
        "x", FunctionType::get(Type::getVoidTy(Context),
                               {Type::getInt8PtrTy(Context)}, false));

    bool modified = false;

    for (auto &BB : F) {
      for (auto &I : BB) {
        if (auto *BI = dyn_cast<BranchInst>(&I)) {
          if (BI->isConditional()) {
            errs() << "Conditional Branch instruction: " << I.getOpcodeName()
                   << "\n";
          } else {
            errs() << "Unconditional Branch instruction: " << I.getOpcodeName()
                   << "\n";
          }
        }
        // 检查是否为 SwitchInst
        else if (isa<SwitchInst>(&I)) {
          errs() << "Switch instruction: " << I.getOpcodeName() << "\n";
        }
        // 检查是否为 IndirectBrInst
        else if (isa<IndirectBrInst>(&I)) {
          errs() << "Indirect Branch instruction: " << I.getOpcodeName()
                 << "\n";
        }
        // 找到间接跳转指令
        if (auto *IndirectBr = dyn_cast<IndirectBrInst>(&I)) {
          errs() << "here is indirect jump instr!\n";
          Builder.SetInsertPoint(IndirectBr);

          // 获取间接跳转的目的地址
          Value *TargetAddr = IndirectBr->getAddress();

          // 创建调用指令
          Builder.CreateCall(
              FuncX,
              Builder.CreateBitCast(TargetAddr, Type::getInt8PtrTy(Context)));

          modified = true;
        }
      }
    }

    return modified;
  }
};

//------------------------------------------------------------------------------
// New PM Registration
//------------------------------------------------------------------------------
llvm::PassPluginLibraryInfo getPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "mypass", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineStartEPCallback(
                [](ModulePassManager &PM, OptimizationLevel Level) {
                  PM.addPass(TestPass());
                });
            PB.registerPipelineStartEPCallback(
                [](ModulePassManager &PM, OptimizationLevel Level) {
                  FunctionPassManager FPM;
                  FPM.addPass(HelloWorld());
                  PM.addPass(createModuleToFunctionPassAdaptor(std::move(FPM)));
                });
          }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getPassPluginInfo();
}
