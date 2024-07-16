OVERVIEW: clang LLVM compiler

USAGE: clang [options] file...

OPTIONS:
  -###                    Print (but do not run) the commands to run for this compilation
  --amdgpu-arch-tool=<value>
                          Tool used for detecting AMD GPU arch in the system.
  --analyzer-output <value>
                          Static analyzer report output format (html|plist|plist-multi-file|plist-html|sarif|sarif-html|text).
  --analyze               Run the static analyzer
  -arcmt-migrate-emit-errors
                          Emit ARC errors even if the migrator can fix them
  -arcmt-migrate-report-output <value>
                          Output path for the plist report
  -B <prefix>             Search $prefix$file for executables, libraries, and data files. If $prefix is a directory, search $prefix/$file
  -b <arg>                Pass -b <arg> to the linker on AIX
  -CC                     Include comments from within macros in preprocessed output
  -cl-denorms-are-zero    OpenCL only. Allow denormals to be flushed to zero.
  -cl-ext=<value>         OpenCL only. Enable or disable OpenCL extensions/optional features. The argument is a comma-separated sequence of one or more extension names, each prefixed by '+' or '-'.
  -cl-fast-relaxed-math   OpenCL only. Sets -cl-finite-math-only and -cl-unsafe-math-optimizations, and defines __FAST_RELAXED_MATH__.
  -cl-finite-math-only    OpenCL only. Allow floating-point optimizations that assume arguments and results are not NaNs or +-Inf.
  -cl-fp32-correctly-rounded-divide-sqrt
                          OpenCL only. Specify that single precision floating-point divide and sqrt used in the program source are correctly rounded.
  -cl-kernel-arg-info     OpenCL only. Generate kernel argument metadata.
  -cl-mad-enable          OpenCL only. Allow use of less precise MAD computations in the generated binary.
  -cl-no-signed-zeros     OpenCL only. Allow use of less precise no signed zeros computations in the generated binary.
  -cl-no-stdinc           OpenCL only. Disables all standard includes containing non-native compiler types and functions.
  -cl-opt-disable         OpenCL only. This option disables all optimizations. By default optimizations are enabled.
  -cl-single-precision-constant
                          OpenCL only. Treat double precision floating-point constant as single precision constant.
  -cl-std=<value>         OpenCL language standard to compile for.
  -cl-strict-aliasing     OpenCL only. This option is added for compatibility with OpenCL 1.0.
  -cl-uniform-work-group-size
                          OpenCL only. Defines that the global work-size be a multiple of the work-group size specified to clEnqueueNDRangeKernel
  -cl-unsafe-math-optimizations
                          OpenCL only. Allow unsafe floating-point optimizations.  Also implies -cl-no-signed-zeros and -cl-mad-enable.
  --config=<file>         Specify configuration file
  --cuda-compile-host-device
                          Compile CUDA code for both host and device (default). Has no effect on non-CUDA compilations.
  --cuda-device-only      Compile CUDA code for device only
  --cuda-feature=<value>  Manually specify the CUDA feature to use
  --cuda-host-only        Compile CUDA code for host only. Has no effect on non-CUDA compilations.
  --cuda-include-ptx=<value>
                          Include PTX for the following GPU architecture (e.g. sm_35) or 'all'. May be specified more than once.
  --cuda-noopt-device-debug
                          Enable device-side debug info generation. Disables ptxas optimizations.
  --cuda-path-ignore-env  Ignore environment variables to detect CUDA installation
  --cuda-path=<value>     CUDA installation path
  -cuid=<value>           An ID for compilation unit, which should be the same for the same compilation unit but different for different compilation units. It is used to externalize device-side static variables for single source offloading languages CUDA and HIP so that they can be accessed by the host code of the same compilation unit.
  -cxx-isystem <directory>
                          Add directory to the C++ SYSTEM include search path
  -C                      Include comments in preprocessed output
  -c                      Only run preprocess, compile, and assemble steps
  -darwin-target-variant-triple <value>
                          Specify the darwin target variant triple
  -darwin-target-variant <value>
                          Generate code for an additional runtime variant of the deployment target
  -dD                     Print macro definitions in -E mode in addition to normal output
  -dependency-dot <value> Filename to write DOT-formatted header dependencies to
  -dependency-file <value>
                          Filename (or -) to write dependency output to
  -dI                     Print include directives in -E mode in addition to normal output
  -dM                     Print macro definitions in -E mode instead of normal output
  -dsym-dir <dir>         Directory to output dSYM's (if any) to
  -dumpdir <dumppfx>      Use <dumpfpx> as a prefix to form auxiliary and dump file names
  -D <macro>=<value>      Define <macro> to <value> (or 1 if <value> omitted)
  -emit-ast               Emit Clang AST files for source inputs
  -emit-interface-stubs   Generate Interface Stub Files.
  -emit-llvm              Use the LLVM representation for assembler and object files
  -emit-merged-ifs        Generate Interface Stub Files, emit merged text not binary.
  --emit-static-lib       Enable linker job to emit a static library.
  --emit-symbol-graph= <value>
                          Generate Extract API information as a side effect of compilation.
  --end-no-unused-arguments
                          Start emitting warnings for unused driver arguments
  --extract-api-ignores=<value>
                          Comma separated list of files containing a new line separated list of API symbols to ignore when extracting API information.
  -extract-api            Extract API information
  -E                      Only run the preprocessor
  -faapcs-bitfield-load   Follows the AAPCS standard that all volatile bit-field write generates at least one load. (ARM only).
  -faapcs-bitfield-width  Follow the AAPCS standard requirement stating that volatile bit-field width is dictated by the field container type. (ARM only).
  -faddrsig               Emit an address-significance table
  -falign-loops=<N>       N must be a power of two. Align loops to the boundary
  -faligned-allocation    Enable C++17 aligned allocation functions
  -fallow-editor-placeholders
                          Treat editor placeholders as valid source code
  -faltivec-src-compat=<value>
                          Source-level compatibility for Altivec vectors (for PowerPC targets). This includes results of vector comparison (scalar for 'xl', vector for 'gcc') as well as behavior when initializing with a scalar (splatting for 'xl', element zero only for 'gcc'). For 'mixed', the compatibility is as 'gcc' for 'vector bool/vector pixel' and as 'xl' for other types. Current default is 'mixed'.
  -fansi-escape-codes     Use ANSI escape codes for diagnostics
  -fapple-kext            Use Apple's kernel extensions ABI
  -fapple-link-rtlib      Force linking the clang builtins runtime library
  -fapple-pragma-pack     Enable Apple gcc-compatible #pragma pack handling
  -fapplication-extension Restrict code to those available for App Extensions
  -fapprox-func           Allow certain math function calls to be replaced with an approximately equivalent calculation
  -fasync-exceptions      Enable EH Asynchronous exceptions
  -fbasic-block-sections=<value>
                          Place each function's basic blocks in unique sections (ELF Only)
  -fbinutils-version=<major.minor>
                          Produced object files can use all ELF features supported by this binutils version and newer. If -fno-integrated-as is specified, the generated assembly will consider GNU as support. 'none' means that all ELF features can be used, regardless of binutils support. Defaults to 2.26.
  -fblocks                Enable the 'blocks' language feature
  -fborland-extensions    Accept non-standard constructs supported by the Borland compiler
  -fbuild-session-file=<file>
                          Use the last modification time of <file> as the build session timestamp
  -fbuild-session-timestamp=<time since Epoch in seconds>
                          Time when the current build session started
  -fbuiltin-module-map    Load the clang builtins module map file.
  -fc++-abi=<value>       C++ ABI to use. This will override the target C++ ABI.
  -fcall-saved-x10        Make the x10 register call-saved (AArch64 only)
  -fcall-saved-x11        Make the x11 register call-saved (AArch64 only)
  -fcall-saved-x12        Make the x12 register call-saved (AArch64 only)
  -fcall-saved-x13        Make the x13 register call-saved (AArch64 only)
  -fcall-saved-x14        Make the x14 register call-saved (AArch64 only)
  -fcall-saved-x15        Make the x15 register call-saved (AArch64 only)
  -fcall-saved-x18        Make the x18 register call-saved (AArch64 only)
  -fcall-saved-x8         Make the x8 register call-saved (AArch64 only)
  -fcall-saved-x9         Make the x9 register call-saved (AArch64 only)
  -fcaret-diagnostics-max-lines=<value>
                          Set the maximum number of source lines to show in a caret diagnostic (0 = no limit).
  -fcf-protection=<value> Instrument control-flow architecture protection
  -fcf-protection         Enable cf-protection in 'full' mode
  -fchar8_t               Enable C++ builtin type char8_t
  -fcheck-new             Do not assume C++ operator new may not return NULL
  -fclang-abi-compat=<version>
                          Attempt to match the ABI of Clang <version>
  -fcolor-diagnostics     Enable colors in diagnostics
  -fcomment-block-commands=<arg>
                          Treat each comma separated argument in <arg> as a documentation comment block command
  -fcommon                Place uninitialized global variables in a common block
  -fcomplete-member-pointers
                          Require member pointer base types to be complete if they would be significant under the Microsoft ABI
  -fconstexpr-backtrace-limit=<value>
                          Set the maximum number of entries to print in a constexpr evaluation backtrace (0 = no limit)
  -fconstexpr-depth=<value>
                          Set the maximum depth of recursive constexpr function calls
  -fconstexpr-steps=<value>
                          Set the maximum number of steps in constexpr function evaluation
  -fcoro-aligned-allocation
                          Prefer aligned allocation for C++ Coroutines
  -fcoroutines            Enable support for the C++ Coroutines
  -fcoverage-compilation-dir=<value>
                          The compilation directory to embed in the coverage mapping.
  -fcoverage-mapping      Generate coverage mapping to enable code coverage analysis
  -fcoverage-prefix-map=<old>=<new>
                          remap file source paths <old> to <new> in coverage mapping. If there are multiple options, prefix replacement is applied in reverse order starting from the last one
  -fcrash-diagnostics-dir=<dir>
                          Put crash-report files in <dir>
  -fcrash-diagnostics=<value>
                          Set level of crash diagnostic reporting, (option: off, compiler, all)
  -fcrash-diagnostics     Enable crash diagnostic reporting (default)
  -fcs-profile-generate=<directory>
                          Generate instrumented code to collect context sensitive execution counts into <directory>/default.profraw (overridden by LLVM_PROFILE_FILE env var)
  -fcs-profile-generate   Generate instrumented code to collect context sensitive execution counts into default.profraw (overridden by LLVM_PROFILE_FILE env var)
  -fcuda-approx-transcendentals
                          Use approximate transcendental functions
  -fcuda-short-ptr        Use 32-bit pointers for accessing const/local/shared address spaces
  -fcxx-exceptions        Enable C++ exceptions
  -fcxx-modules           Enable modules for C++
  -fdata-sections         Place each data in its own section
  -fdebug-compilation-dir=<value>
                          The compilation directory to embed in the debug info
  -fdebug-default-version=<value>
                          Default DWARF version to use, if a -g option caused DWARF debug info to be produced
  -fdebug-info-for-profiling
                          Emit extra debug info to make sample profile more accurate
  -fdebug-macro           Emit macro debug information
  -fdebug-prefix-map=<old>=<new>
                          For paths in debug info, remap directory <old> to <new>. If multiple options match a path, the last option wins
  -fdebug-ranges-base-address
                          Use DWARF base address selection entries in .debug_ranges
  -fdebug-types-section   Place debug types in their own section (ELF Only)
  -fdeclspec              Allow __declspec as a keyword
  -fdelayed-template-parsing
                          Parse templated function definitions at the end of the translation unit
  -fdelete-null-pointer-checks
                          Treat usage of null pointers as undefined behavior (default)
  -fdiagnostics-absolute-paths
                          Print absolute paths in diagnostics
  -fdiagnostics-hotness-threshold=<value>
                          Prevent optimization remarks from being output if they do not have at least this profile count. Use 'auto' to apply the threshold from profile summary
  -fdiagnostics-misexpect-tolerance=<value>
                          Prevent misexpect diagnostics from being output if the profile counts are within N% of the expected. 
  -fdiagnostics-parseable-fixits
                          Print fix-its in machine parseable form
  -fdiagnostics-print-source-range-info
                          Print source range spans in numeric form
  -fdiagnostics-show-hotness
                          Enable profile hotness information in diagnostic line
  -fdiagnostics-show-note-include-stack
                          Display include stacks for diagnostic notes
  -fdiagnostics-show-option
                          Print option name with mappable diagnostics
  -fdiagnostics-show-template-tree
                          Print a template comparison tree for differing templates
  -fdigraphs              Enable alternative token representations '<:', ':>', '<%', '%>', '%:', '%:%:' (default)
  -fdirect-access-external-data
                          Don't use GOT indirection to reference external data symbols
  -fdiscard-value-names   Discard value names in LLVM IR
  -fdollars-in-identifiers
                          Allow '$' in identifiers
  -fdriver-only           Only run the driver.
  -fdwarf-exceptions      Use DWARF style exceptions
  -feliminate-unused-debug-types
                          Do not emit  debug info for defined but unused types
  -fembed-bitcode-marker  Embed placeholder LLVM IR data as a marker
  -fembed-bitcode=<option>
                          Embed LLVM bitcode
  -fembed-bitcode         Embed LLVM IR bitcode as data
  -fembed-offload-object=<value>
                          Embed Offloading device-side binary into host object file as a section.
  -femit-all-decls        Emit all declarations, even if unused
  -femit-compact-unwind-non-canonical
                          Try emitting Compact-Unwind for non-canonical entries. Maybe overriden by other constraints
  -femit-dwarf-unwind=<value>
                          When to emit DWARF unwind (EH frame) info
  -femulated-tls          Use emutls functions to access thread_local variables
  -fenable-matrix         Enable matrix data type and related builtin functions
  -fexceptions            Enable support for exception handling
  -fexcess-precision=<value>
                          Allows control over excess precision on targets where native support for the precision types is not available. By default, excess precision is used to calculate intermediate results following the rules specified in ISO C99.
  -fexperimental-library  Control whether unstable and experimental library features are enabled. This option enables various library features that are either experimental (also known as TSes), or have been but are not stable yet in the selected Standard Library implementation. It is not recommended to use this option in production code, since neither ABI nor API stability are guaranteed. This is intended to provide a preview of features that will ship in the future for experimentation purposes
  -fexperimental-new-constant-interpreter
                          Enable the experimental new constant interpreter
  -fexperimental-relative-c++-abi-vtables
                          Use the experimental C++ class ABI for classes with virtual tables
  -fexperimental-sanitize-metadata-ignorelist=<value>
                          Disable sanitizer metadata for modules and functions that match the provided special case list
  -fexperimental-sanitize-metadata=<value>
                          Specify the type of metadata to emit for binary analysis sanitizers
  -fexperimental-strict-floating-point
                          Enables the use of non-default rounding modes and non-default exception handling on targets that are not currently ready.
  -fextend-arguments=<value>
                          Controls how scalar integer arguments are extended in calls to unprototyped and varargs functions
  -ffast-math             Allow aggressive, lossy floating-point optimizations
  -ffile-compilation-dir=<value>
                          The compilation directory to embed in the debug info and coverage mapping.
  -ffile-prefix-map=<value>
                          remap file source paths in debug info, predefined preprocessor macros and __builtin_FILE(). Implies -ffile-reproducible.
  -ffile-reproducible     Use the target's platform-specific path separator character when expanding the __FILE__ macro
  -ffine-grained-bitfield-accesses
                          Use separate accesses for consecutive bitfield runs with legal widths and alignments.
  -ffinite-loops          Assume all loops are finite.
  -ffinite-math-only      Allow floating-point optimizations that assume arguments and results are not NaNs or +-inf. This defines the \_\_FINITE\_MATH\_ONLY\_\_ preprocessor macro.
  -ffixed-a0              Reserve the a0 register (M68k only)
  -ffixed-a1              Reserve the a1 register (M68k only)
  -ffixed-a2              Reserve the a2 register (M68k only)
  -ffixed-a3              Reserve the a3 register (M68k only)
  -ffixed-a4              Reserve the a4 register (M68k only)
  -ffixed-a5              Reserve the a5 register (M68k only)
  -ffixed-a6              Reserve the a6 register (M68k only)
  -ffixed-d0              Reserve the d0 register (M68k only)
  -ffixed-d1              Reserve the d1 register (M68k only)
  -ffixed-d2              Reserve the d2 register (M68k only)
  -ffixed-d3              Reserve the d3 register (M68k only)
  -ffixed-d4              Reserve the d4 register (M68k only)
  -ffixed-d5              Reserve the d5 register (M68k only)
  -ffixed-d6              Reserve the d6 register (M68k only)
  -ffixed-d7              Reserve the d7 register (M68k only)
  -ffixed-point           Enable fixed point types
  -ffixed-r19             Reserve register r19 (Hexagon only)
  -ffixed-r9              Reserve the r9 register (ARM only)
  -ffixed-x10             Reserve the x10 register (AArch64/RISC-V only)
  -ffixed-x11             Reserve the x11 register (AArch64/RISC-V only)
  -ffixed-x12             Reserve the x12 register (AArch64/RISC-V only)
  -ffixed-x13             Reserve the x13 register (AArch64/RISC-V only)
  -ffixed-x14             Reserve the x14 register (AArch64/RISC-V only)
  -ffixed-x15             Reserve the x15 register (AArch64/RISC-V only)
  -ffixed-x16             Reserve the x16 register (AArch64/RISC-V only)
  -ffixed-x17             Reserve the x17 register (AArch64/RISC-V only)
  -ffixed-x18             Reserve the x18 register (AArch64/RISC-V only)
  -ffixed-x19             Reserve the x19 register (AArch64/RISC-V only)
  -ffixed-x1              Reserve the x1 register (AArch64/RISC-V only)
  -ffixed-x20             Reserve the x20 register (AArch64/RISC-V only)
  -ffixed-x21             Reserve the x21 register (AArch64/RISC-V only)
  -ffixed-x22             Reserve the x22 register (AArch64/RISC-V only)
  -ffixed-x23             Reserve the x23 register (AArch64/RISC-V only)
  -ffixed-x24             Reserve the x24 register (AArch64/RISC-V only)
  -ffixed-x25             Reserve the x25 register (AArch64/RISC-V only)
  -ffixed-x26             Reserve the x26 register (AArch64/RISC-V only)
  -ffixed-x27             Reserve the x27 register (AArch64/RISC-V only)
  -ffixed-x28             Reserve the x28 register (AArch64/RISC-V only)
  -ffixed-x29             Reserve the x29 register (AArch64/RISC-V only)
  -ffixed-x2              Reserve the x2 register (AArch64/RISC-V only)
  -ffixed-x30             Reserve the x30 register (AArch64/RISC-V only)
  -ffixed-x31             Reserve the x31 register (AArch64/RISC-V only)
  -ffixed-x3              Reserve the x3 register (AArch64/RISC-V only)
  -ffixed-x4              Reserve the x4 register (AArch64/RISC-V only)
  -ffixed-x5              Reserve the x5 register (AArch64/RISC-V only)
  -ffixed-x6              Reserve the x6 register (AArch64/RISC-V only)
  -ffixed-x7              Reserve the x7 register (AArch64/RISC-V only)
  -ffixed-x8              Reserve the x8 register (AArch64/RISC-V only)
  -ffixed-x9              Reserve the x9 register (AArch64/RISC-V only)
  -fforce-dwarf-frame     Always emit a debug frame section
  -fforce-emit-vtables    Emits more virtual tables to improve devirtualization
  -fforce-enable-int128   Enable support for int128_t type
  -ffp-contract=<value>   Form fused FP ops (e.g. FMAs)
  -ffp-eval-method=<value>
                          Specifies the evaluation method to use for floating-point arithmetic.
  -ffp-exception-behavior=<value>
                          Specifies the exception behavior of floating-point operations.
  -ffp-model=<value>      Controls the semantics of floating-point calculations.
  -ffreestanding          Assert that the compilation takes place in a freestanding environment
  -ffuchsia-api-level=<value>
                          Set Fuchsia API level
  -ffunction-sections     Place each function in its own section
  -fglobal-isel           Enables the global instruction selector
  -fgnu-keywords          Allow GNU-extension keywords regardless of language standard
  -fgnu-runtime           Generate output compatible with the standard GNU Objective-C runtime
  -fgnu89-inline          Use the gnu89 inline semantics
  -fgnuc-version=<value>  Sets various macros to claim compatibility with the given GCC version (default is 4.2.1)
  -fgpu-allow-device-init Allow device side init function in HIP (experimental)
  -fgpu-default-stream=<value>
                          Specify default stream. The default value is 'legacy'. (HIP only)
  -fgpu-defer-diag        Defer host/device related diagnostic messages for CUDA/HIP
  -fgpu-flush-denormals-to-zero
                          Flush denormal floating point values to zero in CUDA/HIP device mode.
  -fgpu-rdc               Generate relocatable device code, also known as separate compilation mode
  -fgpu-sanitize          Enable sanitizer for AMDGPU target
  -fhip-emit-relocatable  Compile HIP source to relocatable
  -fhip-fp32-correctly-rounded-divide-sqrt
                          Specify that single precision floating-point divide and sqrt used in the program source are correctly rounded (HIP device compilation only)
  -fhip-kernel-arg-name   Specify that kernel argument names are preserved (HIP only)
  -fhip-new-launch-api    Use new kernel launching API for HIP
  -fhonor-infinities      Specify that floating-point optimizations are not allowed that assume arguments and results are not +-inf.
  -fhonor-nans            Specify that floating-point optimizations are not allowed that assume arguments and results are not NANs.
  -fignore-exceptions     Enable support for ignoring exception handling constructs
  -fimplicit-module-maps  Implicitly search the file system for module map files.
  -fincremental-extensions
                          Enable incremental processing extensions such as processingstatements on the global scope.
  -finline-functions      Inline suitable functions
  -finline-hint-functions Inline functions which are (explicitly or implicitly) marked inline
  -finline-max-stacksize=<value>
                          Suppress inlining of functions whose stack size exceeds the given value
  -finput-charset=<value> Specify the default character set for source files
  -finstrument-function-entry-bare
                          Instrument function entry only, after inlining, without arguments to the instrumentation call
  -finstrument-functions-after-inlining
                          Like -finstrument-functions, but insert the calls after inlining
  -finstrument-functions  Generate calls to instrument function entry and exit
  -fintegrated-as         Enable the integrated assembler
  -fintegrated-cc1        Run cc1 in-process
  -fintegrated-objemitter Use internal machine object code emitter.
  -fjmc                   Enable just-my-code debugging
  -fjump-tables           Use jump tables for lowering switches
  -fkeep-persistent-storage-variables
                          Enable keeping all variables that have a persistent storage duration, including global, static and thread-local variables, to guarantee that they can be directly addressed
  -fkeep-static-consts    Keep static const variables even if unused
  -flax-vector-conversions=<value>
                          Enable implicit vector bit-casts
  -flto-jobs=<value>      Controls the backend parallelism of -flto=thin (default of 0 means the number of threads will be derived from the number of CPUs detected)
  -flto=auto              Enable LTO in 'full' mode
  -flto=jobserver         Enable LTO in 'full' mode
  -flto=<value>           Set LTO mode
  -flto                   Enable LTO in 'full' mode
  -fmacro-backtrace-limit=<value>
                          Set the maximum number of entries to print in a macro expansion backtrace (0 = no limit)
  -fmacro-prefix-map=<value>
                          remap file source paths in predefined preprocessor macros and __builtin_FILE(). Implies -ffile-reproducible.
  -fmath-errno            Require math functions to indicate errors by setting errno
  -fmax-tokens=<value>    Max total number of preprocessed tokens for -Wmax-tokens.
  -fmax-type-align=<value>
                          Specify the maximum alignment to enforce on pointers lacking an explicit alignment
  -fmemory-profile-use=<pathname>
                          Use memory profile for profile-guided memory optimization
  -fmemory-profile=<directory>
                          Enable heap memory profiling and dump results into <directory>
  -fmemory-profile        Enable heap memory profiling
  -fmerge-all-constants   Allow merging of constants
  -fmessage-length=<value>
                          Format message diagnostics so that they fit within N columns
  -fminimize-whitespace   Ignore the whitespace from the input file when emitting preprocessor output. It will only contain whitespace when necessary, e.g. to keep two minus signs from merging into to an increment operator. Useful with the -P option to normalize whitespace such that two files with only formatting changes are equal.

Only valid with -E on C-like inputs and incompatible with -traditional-cpp.
  -fmodule-file=[<name>=]<file>
                          Specify the mapping of module name to precompiled module file, or load a module file if name is omitted.
  -fmodule-header=<kind>  Build a C++20 Header Unit from a header that should be found in the user (fmodule-header=user) or system (fmodule-header=system) search path.
  -fmodule-header         Build a C++20 Header Unit from a header.
  -fmodule-map-file=<file>
                          Load this module map file
  -fmodule-name=<name>    Specify the name of the module to build
  -fmodule-output=<value> Save intermediate module file results when compiling a standard C++ module unit.
  -fmodule-output         Save intermediate module file results when compiling a standard C++ module unit.
  -fmodules-cache-path=<directory>
                          Specify the module cache path
  -fmodules-decluse       Require declaration of modules used within a module
  -fmodules-disable-diagnostic-validation
                          Disable validation of the diagnostic options when loading the module
  -fmodules-ignore-macro=<value>
                          Ignore the definition of the given macro when building and loading modules
  -fmodules-prune-after=<seconds>
                          Specify the interval (in seconds) after which a module file will be considered unused
  -fmodules-prune-interval=<seconds>
                          Specify the interval (in seconds) between attempts to prune the module cache
  -fmodules-search-all    Search even non-imported modules to resolve references
  -fmodules-strict-decluse
                          Like -fmodules-decluse but requires all headers to be in modules
  -fmodules-user-build-path <directory>
                          Specify the module user build path
  -fmodules-validate-input-files-content
                          Validate PCM input files based on content if mtime differs
  -fmodules-validate-once-per-build-session
                          Don't verify input files for the modules if the module has been successfully validated or loaded during this build session
  -fmodules-validate-system-headers
                          Validate the system headers that a module depends on when loading the module
  -fmodules               Enable the 'modules' language feature
  -fms-compatibility-version=<value>
                          Dot-separated value representing the Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))
  -fms-compatibility      Enable full Microsoft Visual C++ compatibility
  -fms-extensions         Accept some non-standard constructs supported by the Microsoft compiler
  -fms-hotpatch           Ensure that all functions can be hotpatched at runtime
  -fms-runtime-lib=<value>
                          Select Windows run-time library
  -fmsc-version=<value>   Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))
  -fnew-alignment=<align> Specifies the largest alignment guaranteed by '::operator new(size_t)'
  -fnew-infallible        Enable treating throwing global C++ operator new as always returning valid memory (annotates with __attribute__((returns_nonnull)) and throw()). This is detectable in source.
  -fno-aapcs-bitfield-width
                          Do not follow the AAPCS standard requirement stating that volatile bit-field width is dictated by the field container type. (ARM only).
  -fno-access-control     Disable C++ access control
  -fno-addrsig            Don't emit an address-significance table
  -fno-assume-sane-operator-new
                          Don't assume that C++'s global operator new can't alias any pointer
  -fno-assume-unique-vtables
                          Disable optimizations based on vtable pointer identity
  -fno-autolink           Disable generation of linker directives for automatic library linking
  -fno-builtin-<value>    Disable implicit builtin knowledge of a specific function
  -fno-builtin            Disable implicit builtin knowledge of functions
  -fno-c++-static-destructors
                          Disable C++ static destructor registration
  -fno-char8_t            Disable C++ builtin type char8_t
  -fno-color-diagnostics  Disable colors in diagnostics
  -fno-common             Compile common globals like normal definitions
  -fno-complete-member-pointers
                          Do not require member pointer base types to be complete if they would be significant under the Microsoft ABI
  -fno-constant-cfstrings Disable creation of CodeFoundation-type constant strings
  -fno-convergent-functions
                          Assume all functions may be convergent.
  -fno-coverage-mapping   Disable code coverage analysis
  -fno-crash-diagnostics  Disable auto-generation of preprocessed source files and a script for reproduction during a clang crash
  -fno-cuda-approx-transcendentals
                          Don't use approximate transcendental functions
  -fno-cxx-modules        Disable modules for C++
  -fno-debug-macro        Do not emit macro debug information
  -fno-declspec           Disallow __declspec as a keyword
  -fno-delayed-template-parsing
                          Disable delayed template parsing
  -fno-delete-null-pointer-checks
                          Do not treat usage of null pointers as undefined behavior
  -fno-diagnostics-fixit-info
                          Do not include fixit information in diagnostics
  -fno-diagnostics-show-line-numbers
                          Show line numbers in diagnostic code snippets
  -fno-digraphs           Disallow alternative token representations '<:', ':>', '<%', '%>', '%:', '%:%:'
  -fno-direct-access-external-data
                          Use GOT indirection to reference external data symbols
  -fno-discard-value-names
                          Do not discard value names in LLVM IR
  -fno-dollars-in-identifiers
                          Disallow '$' in identifiers
  -fno-elide-constructors Disable C++ copy constructor elision
  -fno-elide-type         Do not elide types when printing diagnostics
  -fno-eliminate-unused-debug-types
                          Emit  debug info for defined but unused types
  -fno-exceptions         Disable support for exception handling
  -fno-experimental-relative-c++-abi-vtables
                          Do not use the experimental C++ class ABI for classes with virtual tables
  -fno-experimental-sanitize-metadata=<value>
                          Disable emitting metadata for binary analysis sanitizers
  -fno-file-reproducible  Use the host's platform-specific path separator character when expanding the __FILE__ macro
  -fno-fine-grained-bitfield-accesses
                          Use large-integer access for consecutive bitfield runs.
  -fno-finite-loops       Do not assume that any loop is finite.
  -fno-fixed-point        Disable fixed point types
  -fno-force-enable-int128
                          Disable support for int128_t type
  -fno-global-isel        Disables the global instruction selector
  -fno-gnu-inline-asm     Disable GNU style inline asm
  -fno-gpu-allow-device-init
                          Don't allow device side init function in HIP (experimental)
  -fno-gpu-defer-diag     Don't defer host/device related diagnostic messages for CUDA/HIP
  -fno-hip-emit-relocatable
                          Do not override toolchain to compile HIP source to relocatable
  -fno-hip-fp32-correctly-rounded-divide-sqrt
                          Don't specify that single precision floating-point divide and sqrt used in the program source are correctly rounded (HIP device compilation only)
  -fno-hip-kernel-arg-name
                          Don't specify that kernel argument names are preserved (HIP only)
  -fno-hip-new-launch-api Don't use new kernel launching API for HIP
  -fno-integrated-as      Disable the integrated assembler
  -fno-integrated-cc1     Spawn a separate process for each cc1
  -fno-integrated-objemitter
                          Use external machine object code emitter.
  -fno-jump-tables        Do not use jump tables for lowering switches
  -fno-keep-persistent-storage-variables
                          Disable keeping all variables that have a persistent storage duration, including global, static and thread-local variables, to guarantee that they can be directly addressed
  -fno-keep-static-consts Don't keep static const variables even if unused
  -fno-knr-functions      Disable support for K&R C function declarations
  -fno-lto                Disable LTO mode (default)
  -fno-memory-profile     Disable heap memory profiling
  -fno-merge-all-constants
                          Disallow merging of constants
  -fno-modules-check-relocated<value>
                          Skip checks for relocated modules when loading PCM files
  -fno-modules-validate-textual-header-includes
                          Do not enforce -fmodules-decluse and private header restrictions for textual headers. This flag will be removed in a future Clang release.
  -fno-new-infallible     Disable treating throwing global C++ operator new as always returning valid memory (annotates with __attribute__((returns_nonnull)) and throw()). This is detectable in source.
  -fno-objc-infer-related-result-type
                          do not infer Objective-C related result type based on method family
  -fno-offload-lto        Disable LTO mode (default) for offload compilation
  -fno-openmp-extensions  Disable all Clang extensions for OpenMP directives and clauses
  -fno-operator-names     Do not treat C++ operator name keywords as synonyms for operators
  -fno-optimize-sibling-calls
                          Disable tail call optimization, keeping the call stack accurate
  -fno-pch-codegen        Do not generate code for uses of this PCH that assumes an explicit object file will be built for the PCH
  -fno-pch-debuginfo      Do not generate debug info for types in an object file built from this PCH and do not generate them elsewhere
  -fno-plt                Use GOT indirection instead of PLT to make external function calls (x86 only)
  -fno-preserve-as-comments
                          Do not preserve comments in inline assembly
  -fno-profile-generate   Disable generation of profile instrumentation.
  -fno-profile-instr-generate
                          Disable generation of profile instrumentation.
  -fno-profile-instr-use  Disable using instrumentation data for profile-guided optimization
  -fno-pseudo-probe-for-profiling
                          Do not emit pseudo probes for sample profiling
  -fno-register-global-dtors-with-atexit
                          Don't use atexit or __cxa_atexit to register global destructors
  -fno-rtlib-add-rpath    Do not add -rpath with architecture-specific resource directory to the linker flags. When --hip-link is specified, do not add -rpath with HIP runtime library directory to the linker flags
  -fno-rtti-data          Disable generation of RTTI data
  -fno-rtti               Disable generation of rtti information
  -fno-sanitize-address-globals-dead-stripping
                          Disable linker dead stripping of globals in AddressSanitizer
  -fno-sanitize-address-outline-instrumentation
                          Use default code inlining logic for the address sanitizer
  -fno-sanitize-address-poison-custom-array-cookie
                          Disable poisoning array cookies when using custom operator new[] in AddressSanitizer
  -fno-sanitize-address-use-after-scope
                          Disable use-after-scope detection in AddressSanitizer
  -fno-sanitize-address-use-odr-indicator
                          Disable ODR indicator globals
  -fno-sanitize-cfi-canonical-jump-tables
                          Do not make the jump table addresses canonical in the symbol table
  -fno-sanitize-cfi-cross-dso
                          Disable control flow integrity (CFI) checks for cross-DSO calls.
  -fno-sanitize-coverage=<value>
                          Disable features of coverage instrumentation for Sanitizers
  -fno-sanitize-hwaddress-experimental-aliasing
                          Disable aliasing mode in HWAddressSanitizer
  -fno-sanitize-ignorelist
                          Don't use ignorelist file for sanitizers
  -fno-sanitize-memory-param-retval
                          Disable detection of uninitialized parameters and return values
  -fno-sanitize-memory-track-origins
                          Disable origins tracking in MemorySanitizer
  -fno-sanitize-memory-use-after-dtor
                          Disable use-after-destroy detection in MemorySanitizer
  -fno-sanitize-recover=<value>
                          Disable recovery for specified sanitizers
  -fno-sanitize-stable-abi
                          Conventional ABI instrumentation for sanitizer runtime. Default: Conventional
  -fno-sanitize-stats     Disable sanitizer statistics gathering.
  -fno-sanitize-thread-atomics
                          Disable atomic operations instrumentation in ThreadSanitizer
  -fno-sanitize-thread-func-entry-exit
                          Disable function entry/exit instrumentation in ThreadSanitizer
  -fno-sanitize-thread-memory-access
                          Disable memory access instrumentation in ThreadSanitizer
  -fno-sanitize-trap=<value>
                          Disable trapping for specified sanitizers
  -fno-sanitize-trap      Disable trapping for all sanitizers
  -fno-short-wchar        Force wchar_t to be an unsigned int
  -fno-show-column        Do not include column number on diagnostics
  -fno-show-source-location
                          Do not include source location information with diagnostics
  -fno-signed-char        char is unsigned
  -fno-signed-zeros       Allow optimizations that ignore the sign of floating point zeros
  -fno-spell-checking     Disable spell-checking
  -fno-split-machine-functions
                          Disable late function splitting using profile information (x86 ELF)
  -fno-split-stack        Wouldn't use segmented stack
  -fno-stack-clash-protection
                          Disable stack clash protection
  -fno-stack-protector    Disable the use of stack protectors
  -fno-standalone-debug   Limit debug information produced to reduce size of debug binary
  -fno-strict-float-cast-overflow
                          Relax language rules and try to match the behavior of the target's native float-to-int conversion instructions
  -fno-strict-return      Don't treat control flow paths that fall off the end of a non-void function as unreachable
  -fno-sycl               Disables SYCL kernels compilation for device
  -fno-temp-file          Directly create compilation output files. This may lead to incorrect incremental builds if the compiler crashes
  -fno-threadsafe-statics Do not emit code to make initialization of local statics thread safe
  -fno-trigraphs          Do not process trigraph sequences
  -fno-unified-lto        Use distinct LTO pipelines
  -fno-unique-section-names
                          Don't use unique names for text and data sections
  -fno-unroll-loops       Turn off loop unroller
  -fno-use-cxa-atexit     Don't use __cxa_atexit for calling destructors
  -fno-use-init-array     Use .ctors/.dtors instead of .init_array/.fini_array
  -fno-visibility-inlines-hidden-static-local-var
                          Disables -fvisibility-inlines-hidden-static-local-var (this is the default on non-darwin targets)
  -fno-xray-function-index
                          Omit function index section at the expense of single-function patching performance
  -fno-zero-initialized-in-bss
                          Don't place zero initialized data in BSS
  -fobjc-arc-exceptions   Use EH-safe code when synthesizing retains and releases in -fobjc-arc
  -fobjc-arc              Synthesize retain and release calls for Objective-C pointers
  -fobjc-disable-direct-methods-for-testing
                          Ignore attribute objc_direct so that direct methods can be tested
  -fobjc-encode-cxx-class-template-spec
                          Fully encode c++ class template specialization
  -fobjc-exceptions       Enable Objective-C exceptions
  -fobjc-runtime=<value>  Specify the target Objective-C runtime kind and version
  -fobjc-weak             Enable ARC-style weak references in Objective-C
  -foffload-lto=<value>   Set LTO mode for offload compilation
  -foffload-lto           Enable LTO in 'full' mode for offload compilation
  -fomit-frame-pointer    Omit the frame pointer from functions that don't need it. Some stack unwinding cases, such as profilers and sanitizers, may prefer specifying -fno-omit-frame-pointer. On many targets, -O1 and higher omit the frame pointer by default. -m[no-]omit-leaf-frame-pointer takes precedence for leaf functions
  -fopenmp-extensions     Enable all Clang extensions for OpenMP directives and clauses
  -fopenmp-offload-mandatory
                          Do not create a host fallback if offloading to the device fails.
  -fopenmp-simd           Emit OpenMP code only for SIMD-based constructs.
  -fopenmp-target-debug   Enable debugging in the OpenMP offloading device RTL
  -fopenmp-target-jit     Emit code that can be JIT compiled for OpenMP offloading. Implies -foffload-lto=full
  -fopenmp-targets=<value>
                          Specify comma-separated list of triples OpenMP offloading targets to be supported
  -fopenmp-version=<value>
                          Set OpenMP version (e.g. 45 for OpenMP 4.5, 50 for OpenMP 5.0). Default value is 50 for Clang and 11 for Flang
  -fopenmp                Parse OpenMP pragmas and generate parallel code.
  -foperator-arrow-depth=<value>
                          Maximum number of 'operator->'s to call for a member access
  -foptimization-record-file=<file>
                          Specify the output name of the file containing the optimization remarks. Implies -fsave-optimization-record. On Darwin platforms, this cannot be used with multiple -arch <arch> options.
  -foptimization-record-passes=<regex>
                          Only include passes which match a specified regular expression in the generated optimization record (by default, include all passes)
  -forder-file-instrumentation
                          Generate instrumented code to collect order file into default.profraw file (overridden by '=' form of option or LLVM_PROFILE_FILE env var)
  -fpack-struct=<value>   Specify the default maximum struct packing alignment
  -fpascal-strings        Recognize and construct Pascal-style string literals
  -fpass-plugin=<dsopath> Load pass plugin from a dynamic shared object file (only with new pass manager).
  -fpatchable-function-entry=<N,M>
                          Generate M NOPs before function entry and N-M NOPs after function entry
  -fpcc-struct-return     Override the default ABI to return all structs on the stack
  -fpch-codegen           Generate code for uses of this PCH that assumes an explicit object file will be built for the PCH
  -fpch-debuginfo         Generate debug info for types in an object file built from this PCH and do not generate them elsewhere
  -fpch-instantiate-templates
                          Instantiate templates already while building a PCH
  -fpch-validate-input-files-content
                          Validate PCH input files based on content if mtime differs
  -fplugin-arg-<name>-<arg>
                          Pass <arg> to plugin <name>
  -fplugin=<dsopath>      Load the named plugin (dynamic shared object)
  -fprebuilt-implicit-modules
                          Look up implicit modules in the prebuilt module path
  -fprebuilt-module-path=<directory>
                          Specify the prebuilt module path
  -fproc-stat-report=<value>
                          Save subprocess statistics to the given file
  -fproc-stat-report<value>
                          Print subprocess statistics
  -fprofile-arcs          Instrument code to produce gcov data files (*.gcda)
  -fprofile-exclude-files=<value>
                          Instrument only functions from files where names don't match all the regexes separated by a semi-colon
  -fprofile-filter-files=<value>
                          Instrument only functions from files where names match any regex separated by a semi-colon
  -fprofile-function-groups=<N>
                          Partition functions into N groups and select only functions in group i to be instrumented using -fprofile-selected-function-group
  -fprofile-generate=<directory>
                          Generate instrumented code to collect execution counts into <directory>/default.profraw (overridden by LLVM_PROFILE_FILE env var)
  -fprofile-generate      Generate instrumented code to collect execution counts into default.profraw (overridden by LLVM_PROFILE_FILE env var)
  -fprofile-instr-generate=<file>
                          Generate instrumented code to collect execution counts into <file> (overridden by LLVM_PROFILE_FILE env var)
  -fprofile-instr-generate
                          Generate instrumented code to collect execution counts into default.profraw file (overridden by '=' form of option or LLVM_PROFILE_FILE env var)
  -fprofile-instr-use=<value>
                          Use instrumentation data for profile-guided optimization
  -fprofile-list=<value>  Filename defining the list of functions/files to instrument. The file uses the sanitizer special case list format.
  -fprofile-remapping-file=<file>
                          Use the remappings described in <file> to match the profile data against names in the program
  -fprofile-sample-accurate
                          Specifies that the sample profile is accurate
  -fprofile-sample-use=<value>
                          Enable sample-based profile guided optimizations
  -fprofile-selected-function-group=<i>
                          Partition functions into N groups using -fprofile-function-groups and select only functions in group i to be instrumented. The valid range is 0 to N-1 inclusive
  -fprofile-update=<method>
                          Set update method of profile counters
  -fprofile-use=<pathname>
                          Use instrumentation data for profile-guided optimization. If pathname is a directory, it reads from <pathname>/default.profdata. Otherwise, it reads from file <pathname>.
  -fprotect-parens        Determines whether the optimizer honors parentheses when floating-point expressions are evaluated
  -fpseudo-probe-for-profiling
                          Emit pseudo probes for sample profiling
  -frandomize-layout-seed-file=<file>
                          File holding the seed used by the randomize structure layout feature
  -frandomize-layout-seed=<seed>
                          The seed used by the randomize structure layout feature
  -freciprocal-math       Allow division operations to be reassociated
  -freg-struct-return     Override the default ABI to return small structs in registers
  -fregister-global-dtors-with-atexit
                          Use atexit or __cxa_atexit to register global destructors
  -frelaxed-template-template-args
                          Enable C++17 relaxed template template argument matching
  -freroll-loops          Turn on loop reroller
  -fropi                  Generate read-only position independent code (ARM only)
  -frtlib-add-rpath       Add -rpath with architecture-specific resource directory to the linker flags. When --hip-link is specified, also add -rpath with HIP runtime library directory to the linker flags
  -frwpi                  Generate read-write position independent code (ARM only)
  -fsafe-buffer-usage-suggestions
                          Display suggestions to update code associated with -Wunsafe-buffer-usage warnings
  -fsample-profile-use-profi
                          Use profi to infer block and edge counts
  -fsanitize-address-destructor=<value>
                          Set the kind of module destructors emitted by AddressSanitizer instrumentation. These destructors are emitted to unregister instrumented global variables when code is unloaded (e.g. via `dlclose()`).
  -fsanitize-address-field-padding=<value>
                          Level of field padding for AddressSanitizer
  -fsanitize-address-globals-dead-stripping
                          Enable linker dead stripping of globals in AddressSanitizer
  -fsanitize-address-outline-instrumentation
                          Always generate function calls for address sanitizer instrumentation
  -fsanitize-address-poison-custom-array-cookie
                          Enable poisoning array cookies when using custom operator new[] in AddressSanitizer
  -fsanitize-address-use-after-return=<mode>
                          Select the mode of detecting stack use-after-return in AddressSanitizer
  -fsanitize-address-use-after-scope
                          Enable use-after-scope detection in AddressSanitizer
  -fsanitize-address-use-odr-indicator
                          Enable ODR indicator globals to avoid false ODR violation reports in partially sanitized programs at the cost of an increase in binary size
  -fsanitize-blacklist=<value>
                          Alias for -fsanitize-ignorelist=
  -fsanitize-cfi-canonical-jump-tables
                          Make the jump table addresses canonical in the symbol table
  -fsanitize-cfi-cross-dso
                          Enable control flow integrity (CFI) checks for cross-DSO calls.
  -fsanitize-cfi-icall-experimental-normalize-integers
                          Normalize integers in CFI indirect call type signature checks
  -fsanitize-cfi-icall-generalize-pointers
                          Generalize pointers in CFI indirect call type signature checks
  -fsanitize-coverage-allowlist=<value>
                          Restrict sanitizer coverage instrumentation exclusively to modules and functions that match the provided special case list, except the blocked ones
  -fsanitize-coverage-ignorelist=<value>
                          Disable sanitizer coverage instrumentation for modules and functions that match the provided special case list, even the allowed ones
  -fsanitize-coverage=<value>
                          Specify the type of coverage instrumentation for Sanitizers
  -fsanitize-hwaddress-abi=<value>
                          Select the HWAddressSanitizer ABI to target (interceptor or platform, default interceptor). This option is currently unused.
  -fsanitize-hwaddress-experimental-aliasing
                          Enable aliasing mode in HWAddressSanitizer
  -fsanitize-ignorelist=<value>
                          Path to ignorelist file for sanitizers
  -fsanitize-memory-param-retval
                          Enable detection of uninitialized parameters and return values
  -fsanitize-memory-track-origins=<value>
                          Enable origins tracking in MemorySanitizer
  -fsanitize-memory-track-origins
                          Enable origins tracking in MemorySanitizer
  -fsanitize-memory-use-after-dtor
                          Enable use-after-destroy detection in MemorySanitizer
  -fsanitize-memtag-mode=<value>
                          Set default MTE mode to 'sync' (default) or 'async'
  -fsanitize-recover=<value>
                          Enable recovery for specified sanitizers
  -fsanitize-stable-abi   Stable  ABI instrumentation for sanitizer runtime. Default: Conventional
  -fsanitize-stats        Enable sanitizer statistics gathering.
  -fsanitize-system-ignorelist=<value>
                          Path to system ignorelist file for sanitizers
  -fsanitize-thread-atomics
                          Enable atomic operations instrumentation in ThreadSanitizer (default)
  -fsanitize-thread-func-entry-exit
                          Enable function entry/exit instrumentation in ThreadSanitizer (default)
  -fsanitize-thread-memory-access
                          Enable memory access instrumentation in ThreadSanitizer (default)
  -fsanitize-trap=<value> Enable trapping for specified sanitizers
  -fsanitize-trap         Enable trapping for all sanitizers
  -fsanitize-undefined-strip-path-components=<number>
                          Strip (or keep only, if negative) a given number of path components when emitting check metadata.
  -fsanitize=<check>      Turn on runtime checks for various forms of undefined or suspicious behavior. See user manual for available checks
  -fsave-optimization-record=<format>
                          Generate an optimization record file in a specific format
  -fsave-optimization-record
                          Generate a YAML optimization record file
  -fseh-exceptions        Use SEH style exceptions
  -fshort-enums           Allocate to an enum type only as many bytes as it needs for the declared range of possible values
  -fshort-wchar           Force wchar_t to be a short unsigned int
  -fshow-overloads=<value>
                          Which overload candidates to show when overload resolution fails. Defaults to 'all'
  -fshow-skipped-includes Show skipped includes in -H output.
  -fsigned-char           char is signed
  -fsized-deallocation    Enable C++14 sized global deallocation functions
  -fsjlj-exceptions       Use SjLj style exceptions
  -fslp-vectorize         Enable the superword-level parallelism vectorization passes
  -fspell-checking-limit=<value>
                          Set the maximum number of times to perform spell checking on unrecognized identifiers (0 = no limit)
  -fsplit-dwarf-inlining  Provide minimal debug info in the object/executable to facilitate online symbolication/stack traces in the absence of .dwo/.dwp files when using Split DWARF
  -fsplit-lto-unit        Enables splitting of the LTO unit
  -fsplit-machine-functions
                          Enable late function splitting using profile information (x86 ELF)
  -fsplit-stack           Use segmented stack
  -fstack-clash-protection
                          Enable stack clash protection
  -fstack-protector-all   Enable stack protectors for all functions
  -fstack-protector-strong
                          Enable stack protectors for some functions vulnerable to stack smashing. Compared to -fstack-protector, this uses a stronger heuristic that includes functions containing arrays of any size (and any type), as well as any calls to alloca or the taking of an address from a local variable
  -fstack-protector       Enable stack protectors for some functions vulnerable to stack smashing. This uses a loose heuristic which considers functions vulnerable if they contain a char (or 8bit integer) array or constant sized calls to alloca , which are of greater size than ssp-buffer-size (default: 8 bytes). All variable sized calls to alloca are considered vulnerable. A function with a stack protector has a guard value added to the stack frame that is checked on function exit. The guard value must be positioned in the stack frame such that a buffer overflow from a vulnerable variable will overwrite the guard value before overwriting the function's return address. The reference stack guard value is stored in a global variable.
  -fstack-size-section    Emit section containing metadata on function stack sizes
  -fstack-usage           Emit .su file containing information on function stack sizes
  -fstandalone-debug      Emit full debug info for all types used by the program
  -fstrict-enums          Enable optimizations based on the strict definition of an enum's value range
  -fstrict-flex-arrays=<n>
                          Enable optimizations based on the strict definition of flexible arrays
  -fstrict-float-cast-overflow
                          Assume that overflowing float-to-int casts are undefined (default)
  -fstrict-vtable-pointers
                          Enable optimizations based on the strict rules for overwriting polymorphic C++ objects
  -fswift-async-fp=<option>
                          Control emission of Swift async extended frame info
  -fsycl                  Enables SYCL kernels compilation for device
  -fsyntax-only           Run the preprocessor, parser and semantic analysis stages
  -fsystem-module         Build this module as a system module. Only used with -emit-module
  -ftemplate-backtrace-limit=<value>
                          Set the maximum number of entries to print in a template instantiation backtrace (0 = no limit)
  -ftemplate-depth=<value>
                          Set the maximum depth of recursive template instantiation
  -ftest-coverage         Produce gcov notes files (*.gcno)
  -fthin-link-bitcode=<value>
                          Write minimized bitcode to <file> for the ThinLTO thin link only
  -fthinlto-index=<value> Perform ThinLTO importing using provided function summary index
  -ftime-report=<value>   (For new pass manager) 'per-pass': one report for each pass; 'per-pass-run': one report for each pass invocation
  -ftime-trace-granularity=<value>
                          Minimum time granularity (in microseconds) traced by time profiler
  -ftime-trace=<value>    Similar to -ftime-trace. Specify the JSON file or a directory which will contain the JSON file
  -ftime-trace            Turn on time profiler. Generates JSON file based on output filename.
  -ftrap-function=<value> Issue call to specified function rather than a trap instruction
  -ftrapv-handler=<function name>
                          Specify the function to be called on overflow
  -ftrapv                 Trap on integer overflow
  -ftrigraphs             Process trigraph sequences
  -ftrivial-auto-var-init-stop-after=<value>
                          Stop initializing trivial automatic stack variables after the specified number of instances
  -ftrivial-auto-var-init=<value>
                          Initialize trivial automatic stack variables. Defaults to 'uninitialized'
  -funified-lto           Use the unified LTO pipeline
  -funique-basic-block-section-names
                          Use unique names for basic block sections (ELF Only)
  -funique-internal-linkage-names
                          Uniqueify Internal Linkage Symbol Names by appending the MD5 hash of the module path
  -funroll-loops          Turn on loop unroller
  -funsafe-math-optimizations
                          Allow unsafe floating-point math optimizations which may decrease precision
  -fuse-cuid=<value>      Method to generate ID's for compilation units for single source offloading languages CUDA and HIP: 'hash' (ID's generated by hashing file path and command line options) | 'random' (ID's generated as random numbers) | 'none' (disabled). Default is 'hash'. This option will be overridden by option '-cuid=[ID]' if it is specified.
  -fuse-line-directives   Use #line in preprocessed output
  -fvalidate-ast-input-files-content
                          Compute and store the hash of input files used to build an AST. Files with mismatching mtime's are considered valid if both contents is identical
  -fveclib=<value>        Use the given vector functions library
  -fvectorize             Enable the loop vectorization passes
  -fverbose-asm           Generate verbose assembly output
  -fvirtual-function-elimination
                          Enables dead virtual function elimination optimization. Requires -flto=full
  -fvisibility-dllexport=<value>
                          The visibility for dllexport definitions [-fvisibility-from-dllstorageclass]
  -fvisibility-externs-dllimport=<value>
                          The visibility for dllimport external declarations [-fvisibility-from-dllstorageclass]
  -fvisibility-externs-nodllstorageclass=<value>
                          The visibility for external declarations without an explicit DLL dllstorageclass [-fvisibility-from-dllstorageclass]
  -fvisibility-from-dllstorageclass
                          Set the visibility of symbols in the generated code from their DLL storage class
  -fvisibility-global-new-delete-hidden
                          Give global C++ operator new and delete declarations hidden visibility
  -fvisibility-inlines-hidden-static-local-var
                          When -fvisibility-inlines-hidden is enabled, static variables in inline C++ member functions will also be given hidden visibility by default
  -fvisibility-inlines-hidden
                          Give inline C++ member functions hidden visibility by default
  -fvisibility-ms-compat  Give global types 'default' visibility and global functions and variables 'hidden' visibility by default
  -fvisibility-nodllstorageclass=<value>
                          The visibility for definitions without an explicit DLL export class [-fvisibility-from-dllstorageclass]
  -fvisibility=<value>    Set the default symbol visibility for all global definitions
  -fwasm-exceptions       Use WebAssembly style exceptions
  -fwhole-program-vtables Enables whole-program vtable optimization. Requires -flto
  -fwrapv                 Treat signed integer overflow as two's complement
  -fwritable-strings      Store string literals as writable data
  -fxl-pragma-pack        Enable IBM XL #pragma pack handling
  -fxray-always-emit-customevents
                          Always emit __xray_customevent(...) calls even if the containing function is not always instrumented
  -fxray-always-emit-typedevents
                          Always emit __xray_typedevent(...) calls even if the containing function is not always instrumented
  -fxray-always-instrument=<value>
                          DEPRECATED: Filename defining the whitelist for imbuing the 'always instrument' XRay attribute.
  -fxray-attr-list=<value>
                          Filename defining the list of functions/types for imbuing XRay attributes.
  -fxray-function-groups=<value>
                          Only instrument 1 of N groups
  -fxray-ignore-loops     Don't instrument functions with loops unless they also meet the minimum function size
  -fxray-instruction-threshold=<value>
                          Sets the minimum function size to instrument with XRay
  -fxray-instrumentation-bundle=<value>
                          Select which XRay instrumentation points to emit. Options: all, none, function-entry, function-exit, function, custom. Default is 'all'.  'function' includes both 'function-entry' and 'function-exit'.
  -fxray-instrument       Generate XRay instrumentation sleds on function entry and exit
  -fxray-link-deps        Link XRay runtime library when -fxray-instrument is specified (default)
  -fxray-modes=<value>    List of modes to link in by default into XRay instrumented binaries.
  -fxray-never-instrument=<value>
                          DEPRECATED: Filename defining the whitelist for imbuing the 'never instrument' XRay attribute.
  -fxray-selected-function-group=<value>
                          When using -fxray-function-groups, select which group of functions to instrument. Valid range is 0 to fxray-function-groups - 1
  -fzero-call-used-regs=<value>
                          Clear call-used registers upon function return (AArch64/x86 only)
  -fzvector               Enable System z vector language extension
  -F <value>              Add directory to framework include search path
  --gcc-install-dir=<value>
                          Use GCC installation in the specified directory. The directory ends with path components like 'lib{,32,64}/gcc{,-cross}/$triple/$version'. Note: executables (e.g. ld) used by the compiler are not overridden by the selected GCC installation
  --gcc-toolchain=<value> Specify a directory where Clang can find 'include' and 'lib{,32,64}/gcc{,-cross}/$triple/$version'. Clang will use the GCC installation with the largest version
  -gcodeview-command-line Emit compiler path and command line into CodeView debug information
  -gcodeview-ghash        Emit type record hashes in a .debug$H section
  -gcodeview              Generate CodeView debug information
  -gdwarf-2               Generate source-level debug information with dwarf version 2
  -gdwarf-3               Generate source-level debug information with dwarf version 3
  -gdwarf-4               Generate source-level debug information with dwarf version 4
  -gdwarf-5               Generate source-level debug information with dwarf version 5
  -gdwarf32               Enables DWARF32 format for ELF binaries, if debug information emission is enabled.
  -gdwarf64               Enables DWARF64 format for ELF binaries, if debug information emission is enabled.
  -gdwarf                 Generate source-level debug information with the default dwarf version
  -gembed-source          Embed source text in DWARF debug sections
  -gen-reproducer=<value> Emit reproducer on (option: off, crash (default), error, always)
  -gline-directives-only  Emit debug line info directives only
  -gline-tables-only      Emit debug line number tables only
  -gmodules               Generate debug info with external references to clang modules or precompiled headers
  -gno-codeview-command-line
                          Don't emit compiler path and command line into CodeView debug information
  -gno-embed-source       Restore the default behavior of not embedding source text in DWARF debug sections
  -gno-inline-line-tables Don't emit inline line tables.
  --gpu-bundle-output     Bundle output files of HIP device compilation
  --gpu-instrument-lib=<value>
                          Instrument device library for HIP, which is a LLVM bitcode containing __cyg_profile_func_enter and __cyg_profile_func_exit
  --gpu-max-threads-per-block=<value>
                          Default max threads per block for kernel launch bounds for HIP
  -gsplit-dwarf=<value>   Set DWARF fission mode
  -gstrict-dwarf          Restrict DWARF features to those defined in the specified version, avoiding features from later versions.
  -gz=<value>             DWARF debug sections compression type
  -G <size>               Put objects of at most <size> bytes into small data section (MIPS / Hexagon)
  -g                      Generate source-level debug information
  --help-hidden           Display help for hidden options
  -help                   Display available options
  --hip-device-lib=<value>
                          HIP device library
  --hip-link              Link clang-offload-bundler bundles for HIP
  --hip-path=<value>      HIP runtime installation path, used for finding HIP version and adding HIP include path.
  --hip-version=<value>   HIP version in the format of major.minor.patch
  --hipspv-pass-plugin=<dsopath>
                          path to a pass plugin for HIP to SPIR-V passes.
  -H                      Show header includes and nesting depth
  -I-                     Restrict all prior -I flags to double-quoted inclusion and remove current directory from include path
  -ibuiltininc            Enable builtin #include directories even when -nostdinc is used before or after -ibuiltininc. Using -nobuiltininc after the option disables it
  -idirafter <value>      Add directory to AFTER include search path
  -iframeworkwithsysroot <directory>
                          Add directory to SYSTEM framework search path, absolute paths are relative to -isysroot
  -iframework <value>     Add directory to SYSTEM framework search path
  -imacros <file>         Include macros from file before parsing
  -include-pch <file>     Include precompiled header file
  -include <file>         Include file before parsing
  -index-header-map       Make the next included directory (-I or -F) an indexer header map
  -iprefix <dir>          Set the -iwithprefix/-iwithprefixbefore prefix
  -iquote <directory>     Add directory to QUOTE include search path
  -isysroot <dir>         Set the system root directory (usually /)
  -isystem-after <directory>
                          Add directory to end of the SYSTEM include search path
  -isystem <directory>    Add directory to SYSTEM include search path
  -ivfsoverlay <value>    Overlay the virtual filesystem described by file over the real file system
  -iwithprefixbefore <dir>
                          Set directory to include search path with prefix
  -iwithprefix <dir>      Set directory to SYSTEM include search path with prefix
  -iwithsysroot <directory>
                          Add directory to SYSTEM include search path, absolute paths are relative to -isysroot
  -I <dir>                Add directory to the end of the list of include search paths
  --libomptarget-amdgcn-bc-path=<value>
                          Path to libomptarget-amdgcn bitcode library
  --libomptarget-amdgpu-bc-path=<value>
                          Path to libomptarget-amdgcn bitcode library
  --libomptarget-nvptx-bc-path=<value>
                          Path to libomptarget-nvptx bitcode library
  -L <dir>                Add directory to library search path
  -mabi=quadword-atomics  Enable quadword atomics ABI on AIX (AIX PPC64 only). Uses lqarx/stqcx. instructions.
  -mabicalls              Enable SVR4-style position-independent code (Mips only)
  -maix-struct-return     Return all structs in memory (PPC32 only)
  -malign-branch-boundary=<value>
                          Specify the boundary's size to align branches
  -malign-branch=<value>  Specify types of branches to align
  -malign-double          Align doubles to two words in structs (x86 only)
  -maltivec               Enable AltiVec vector initializer syntax
  -mamdgpu-ieee           Sets the IEEE bit in the expected default floating point  mode register. Floating point opcodes that support exception flag gathering quiet and propagate signaling NaN inputs per IEEE 754-2008. This option changes the ABI. (AMDGPU only)
  -march=<value>          For a list of available architectures for the target use '-mcpu=help'
  -mbackchain             Link stack frames through backchain on System Z
  -mbranch-protection=<value>
                          Enforce targets of indirect branches and function returns
  -mbranches-within-32B-boundaries
                          Align selected branches (fused, jcc, jmp) within 32-byte boundary
  -mcabac                 Enable CABAC instructions
  -mcmodel=medany         Equivalent to -mcmodel=medium, compatible with RISC-V gcc.
  -mcmodel=medlow         Equivalent to -mcmodel=small, compatible with RISC-V gcc.
  -mcmse                  Allow use of CMSE (Armv8-M Security Extensions)
  -mcode-object-version=<value>
                          Specify code object ABI version. Defaults to 4. (AMDGPU only)
  -mcpu=<value>           For a list of available CPUs for the target use '-mcpu=help'
  -mcrbits                Control the CR-bit tracking feature on PowerPC. ``-mcrbits`` (the enablement of CR-bit tracking support) is the default for POWER8 and above, as well as for all other CPUs when optimization is applied (-O2 and above).
  -mcrc                   Allow use of CRC instructions (ARM/Mips only)
  -mcumode                Specify CU wavefront execution mode (AMDGPU only)
  -mdefault-visibility-export-mapping=<value>
                          Mapping between default visibility and export
  -mdouble=<n             Force double to be <n> bits
  -MD                     Write a depfile containing user and system headers
  -meabi <value>          Set EABI type. Default depends on triple)
  -membedded-data         Place constants in the .rodata section instead of the .sdata section even if they meet the -G <size> threshold (MIPS)
  -menable-experimental-extensions
                          Enable use of experimental RISC-V extensions.
  -mexec-model=<value>    Execution model (WebAssembly only)
  -mexecute-only          Disallow generation of data access to code sections (ARM only)
  -mextern-sdata          Assume that externally defined data is in the small data if it meets the -G <size> threshold (MIPS)
  -mfentry                Insert calls to fentry at function entry (x86/SystemZ only)
  -mfix-cmse-cve-2021-35465
                          Work around VLLDM erratum CVE-2021-35465 (ARM only)
  -mfix-cortex-a53-835769 Workaround Cortex-A53 erratum 835769 (AArch64 only)
  -mfix-cortex-a57-aes-1742098
                          Work around Cortex-A57 Erratum 1742098 (ARM only)
  -mfix-cortex-a72-aes-1655431
                          Work around Cortex-A72 Erratum 1655431 (ARM only)
  -mfp32                  Use 32-bit floating point registers (MIPS only)
  -mfp64                  Use 64-bit floating point registers (MIPS only)
  -mframe-chain=<value>   Select the frame chain model used to emit frame records (Arm only).
  -mfunction-return=<value>
                          Replace returns with jumps to ``__x86_return_thunk`` (x86 only, error otherwise)
  -MF <file>              Write depfile output from -MMD, -MD, -MM, or -M to <file>
  -mgeneral-regs-only     Generate code which only uses the general purpose registers (AArch64/x86 only)
  -mglobal-merge          Enable merging of globals
  -mgpopt                 Use GP relative accesses for symbols known to be in a small data section (MIPS)
  -mguard=<value>         Enable or disable Control Flow Guard checks and guard tables emission
  -MG                     Add missing headers to depfile
  -mharden-sls=<value>    Select straight-line speculation hardening scope (ARM/AArch64/X86 only). <arg> must be: all, none, retbr(ARM/AArch64), blr(ARM/AArch64), comdat(ARM/AArch64), nocomdat(ARM/AArch64), return(X86), indirect-jmp(X86)
  -mhvx-ieee-fp           Enable Hexagon HVX IEEE floating-point
  -mhvx-length=<value>    Set Hexagon Vector Length
  -mhvx-qfloat            Enable Hexagon HVX QFloat instructions
  -mhvx=<value>           Enable Hexagon Vector eXtensions
  -mhvx                   Enable Hexagon Vector eXtensions
  -miamcu                 Use Intel MCU ABI
  -mignore-xcoff-visibility
                          Not emit the visibility attribute for asm in AIX OS or give all symbols 'unspecified' visibility in XCOFF object file
  --migrate               Run the migrator
  -mincremental-linker-compatible
                          (integrated-as) Emit an object file which can be used with an incremental linker
  -mindirect-branch-cs-prefix
                          Add cs prefix to call and jmp to indirect thunk
  -mindirect-jump=<value> Change indirect jump instructions to inhibit speculation
  -mios-version-min=<value>
                          Set iOS deployment target
  -MJ <value>             Write a compilation database entry per input
  -mllvm=<arg>            Alias for -mllvm
  -mllvm <value>          Additional arguments to forward to LLVM's option processing
  -mlocal-sdata           Extend the -G behaviour to object local data (MIPS)
  -mlong-calls            Generate branches with extended addressability, usually via indirect jumps.
  -mlong-double-128       Force long double to be 128 bits
  -mlong-double-64        Force long double to be 64 bits
  -mlong-double-80        Force long double to be 80 bits, padded to 128 bits for storage
  -mlvi-cfi               Enable only control-flow mitigations for Load Value Injection (LVI)
  -mlvi-hardening         Enable all mitigations for Load Value Injection (LVI)
  -mmacos-version-min=<value>
                          Set macOS deployment target
  -mmadd4                 Enable the generation of 4-operand madd.s, madd.d and related instructions.
  -mmark-bti-property     Add .note.gnu.property with BTI to assembly files (AArch64 only)
  -MMD                    Write a depfile containing user headers
  -mmemops                Enable generation of memop instructions
  -mmlir <value>          Additional arguments to forward to MLIR's option processing
  -mms-bitfields          Set the default structure layout to be compatible with the Microsoft compiler standard
  -mmsa                   Enable MSA ASE (MIPS only)
  -mmt                    Enable MT ASE (MIPS only)
  -MM                     Like -MMD, but also implies -E and writes to stdout by default
  -mno-abicalls           Disable SVR4-style position-independent code (Mips only)
  -mno-bti-at-return-twice
                          Do not add a BTI instruction after a setjmp or other return-twice construct (Arm/AArch64 only)
  -mno-crc                Disallow use of CRC instructions (Mips only)
  -mno-cumode             Specify WGP wavefront execution mode (AMDGPU only)
  -mno-embedded-data      Do not place constants in the .rodata section instead of the .sdata if they meet the -G <size> threshold (MIPS)
  -mno-execute-only       Allow generation of data access to code sections (ARM only)
  -mno-extern-sdata       Do not assume that externally defined data is in the small data if it meets the -G <size> threshold (MIPS)
  -mno-fix-cmse-cve-2021-35465
                          Don't work around VLLDM erratum CVE-2021-35465 (ARM only)
  -mno-fix-cortex-a53-835769
                          Don't workaround Cortex-A53 erratum 835769 (AArch64 only)
  -mno-fix-cortex-a57-aes-1742098
                          Don't work around Cortex-A57 Erratum 1742098 (ARM only)
  -mno-fix-cortex-a72-aes-1655431
                          Don't work around Cortex-A72 Erratum 1655431 (ARM only)
  -mno-fmv                Disable function multiversioning
  -mno-gather             Disable generation of gather instructions in auto-vectorization(x86 only)
  -mno-global-merge       Disable merging of globals
  -mno-gpopt              Do not use GP relative accesses for symbols known to be in a small data section (MIPS)
  -mno-hvx-ieee-fp        Disable Hexagon HVX IEEE floating-point
  -mno-hvx-qfloat         Disable Hexagon HVX QFloat instructions
  -mno-hvx                Disable Hexagon Vector eXtensions
  -mno-implicit-float     Don't generate implicit floating point or vector instructions
  -mno-incremental-linker-compatible
                          (integrated-as) Emit an object file which cannot be used with an incremental linker
  -mno-local-sdata        Do not extend the -G behaviour to object local data (MIPS)
  -mno-long-calls         Restore the default behaviour of not generating long calls
  -mno-lvi-cfi            Disable control-flow mitigations for Load Value Injection (LVI)
  -mno-lvi-hardening      Disable mitigations for Load Value Injection (LVI)
  -mno-madd4              Disable the generation of 4-operand madd.s, madd.d and related instructions.
  -mno-memops             Disable generation of memop instructions
  -mno-movt               Disallow use of movt/movw pairs (ARM only)
  -mno-ms-bitfields       Do not set the default structure layout to be compatible with the Microsoft compiler standard
  -mno-msa                Disable MSA ASE (MIPS only)
  -mno-mt                 Disable MT ASE (MIPS only)
  -mno-neg-immediates     Disallow converting instructions with negative immediates to their negation or inversion.
  -mno-nvj                Disable generation of new-value jumps
  -mno-nvs                Disable generation of new-value stores
  -mno-outline-atomics    Don't generate local calls to out-of-line atomic operations
  -mno-outline            Disable function outlining (AArch64 only)
  -mno-packets            Disable generation of instruction packets
  -mno-pic-data-is-text-relative
                          Don't assume data segments are relative to text segment
  -mno-relax              Disable linker relaxation
  -mno-restrict-it        Allow generation of complex IT blocks.
  -mno-save-restore       Disable using library calls for save and restore
  -mno-scatter            Disable generation of scatter instructions in auto-vectorization(x86 only)
  -mno-seses              Disable speculative execution side effect suppression (SESES)
  -mno-stack-arg-probe    Disable stack probes which are enabled by default
  -mno-tgsplit            Disable threadgroup split execution mode (AMDGPU only)
  -mno-tls-direct-seg-refs
                          Disable direct TLS access through segment registers
  -mno-unaligned-access   Force all memory accesses to be aligned (AArch32/AArch64/LoongArch only)
  -mno-wavefrontsize64    Specify wavefront size 32 mode (AMDGPU only)
  -mnocrc                 Disallow use of CRC instructions (ARM only)
  -mnop-mcount            Generate mcount/__fentry__ calls as nops. To activate they need to be patched in.
  -mnvj                   Enable generation of new-value jumps
  -mnvs                   Enable generation of new-value stores
  -module-dependency-dir <value>
                          Directory to dump module dependencies to
  -module-file-info       Provide information about a particular module file
  -momit-leaf-frame-pointer
                          Omit frame pointer setup for leaf functions
  -moutline-atomics       Generate local calls to out-of-line atomic operations
  -moutline               Enable function outlining (AArch64 only)
  -mpacked-stack          Use packed stack layout (SystemZ only).
  -mpackets               Enable generation of instruction packets
  -mpad-max-prefix-size=<value>
                          Specify maximum number of prefixes to use for padding
  -mpic-data-is-text-relative
                          Assume data segments are relative to text segment
  -mprefer-vector-width=<value>
                          Specifies preferred vector width for auto-vectorization. Defaults to 'none' which allows target specific decisions.
  -mprintf-kind=<value>   Specify the printf lowering scheme (AMDGPU only), allowed values are "hostcall"(printing happens during kernel execution, this scheme relies on hostcalls which require system to support pcie atomics) and "buffered"(printing happens after all kernel threads exit, this uses a printf buffer and does not rely on pcie atomic support)
  -MP                     Create phony target for each dependency (other than main file)
  -mqdsp6-compat          Enable hexagon-qdsp6 backward compatibility
  -MQ <value>             Specify name of main file output to quote in depfile
  -mrecip=<value>         Control use of approximate reciprocal and reciprocal square root instructions followed by <n> iterations of Newton-Raphson refinement. <value> = ( ['!'] ['vec-'] ('rcp'|'sqrt') [('h'|'s'|'d')] [':'<n>] ) | 'all' | 'default' | 'none'
  -mrecip                 Equivalent to '-mrecip=all'
  -mrecord-mcount         Generate a __mcount_loc section entry for each __fentry__ call.
  -mrelax-all             (integrated-as) Relax all machine instructions
  -mrelax                 Enable linker relaxation
  -mrestrict-it           Disallow generation of complex IT blocks. It is off by default.
  -mrtd                   Make StdCall calling convention the default
  -mrvv-vector-bits=<value>
                          Specify the size in bits of an RVV vector register. Defaults to the vector length agnostic value of "scalable". Accepts power of 2 values between 64 and 65536. Also accepts "zvl" to use the value implied by -march/-mcpu. Value will be reflected in __riscv_v_fixed_vlen preprocessor define (RISC-V only)
  -msave-restore          Enable using library calls for save and restore
  -mseses                 Enable speculative execution side effect suppression (SESES). Includes LVI control flow integrity mitigations
  -msign-return-address=<value>
                          Select return address signing scope
  -mskip-rax-setup        Skip setting up RAX register when passing variable arguments (x86 only)
  -msmall-data-limit=<value>
                          Put global and static data smaller than the limit into a special section
  -msoft-float            Use software floating point
  -mstack-alignment=<value>
                          Set the stack alignment
  -mstack-arg-probe       Enable stack probes
  -mstack-probe-size=<value>
                          Set the stack probe size
  -mstack-protector-guard-offset=<value>
                          Use the given offset for addressing the stack-protector guard
  -mstack-protector-guard-reg=<value>
                          Use the given reg for addressing the stack-protector guard
  -mstack-protector-guard-symbol=<value>
                          Use the given symbol for addressing the stack-protector guard
  -mstack-protector-guard=<value>
                          Use the given guard (global, tls) for addressing the stack-protector guard
  -mstackrealign          Force realign the stack at entry to every function
  -msve-vector-bits=<value>
                          Specify the size in bits of an SVE vector register. Defaults to the vector length agnostic value of "scalable". (AArch64 only)
  -msvr4-struct-return    Return small structs in registers (PPC32 only)
  -mtargetos=<value>      Set the deployment target to be the specified OS and OS version
  -mtgsplit               Enable threadgroup split execution mode (AMDGPU only)
  -mthread-model <value>  The thread model to use. Defaults to 'posix')
  -mtls-direct-seg-refs   Enable direct TLS access through segment registers (default)
  -mtls-size=<value>      Specify bit size of immediate TLS offsets (AArch64 ELF only): 12 (for 4KB) | 24 (for 16MB, default) | 32 (for 4GB) | 48 (for 256TB, needs -mcmodel=large)
  -mtp=<value>            Thread pointer access method. For AArch32: 'soft' uses a function call, or 'tpidrurw', 'tpidruro' or 'tpidrprw' use the three CP15 registers. 'cp15' is an alias for 'tpidruro'. For AArch64: 'tpidr_el0', 'tpidr_el1', 'tpidr_el2', 'tpidr_el3' or 'tpidrro_el0' use the five system registers. 'elN' is an alias for 'tpidr_elN'.
  -mtune=<value>          Only supported on AArch64, PowerPC, RISC-V, SystemZ, and X86
  -MT <value>             Specify name of main file output in depfile
  -munaligned-access      Allow memory accesses to be unaligned (AArch32/AArch64/LoongArch only)
  -munsafe-fp-atomics     Enable generation of unsafe floating point atomic instructions. May generate more efficient code, but may not respect rounding and denormal modes, and may give incorrect results for certain memory destinations. (AMDGPU only)
  -mvscale-max=<value>    Specify the vscale maximum. Defaults to the vector length agnostic value of "0". (AArch64/RISC-V only)
  -mvscale-min=<value>    Specify the vscale minimum. Defaults to "1". (AArch64/RISC-V only)
  -MV                     Use NMake/Jom format for the depfile
  -mwavefrontsize64       Specify wavefront size 64 mode (AMDGPU only)
  -mxcoff-build-id=<0xHEXSTRING>
                          On AIX, request creation of a build-id string, "0xHEXSTRING", in the string table of the loader section inside the linked binary
  -mxcoff-roptr           Place constant objects with relocatable address values in the RO data section and add -bforceimprw to the linker flags (AIX only)
  -mzos-hlq-clang=<ClangHLQ>
                          High level qualifier for z/OS C++RT side deck datasets
  -mzos-hlq-csslib=<CsslibHLQ>
                          High level qualifier for z/OS CSSLIB dataset
  -mzos-hlq-le=<LeHLQ>    High level qualifier for z/OS Language Environment datasets
  -mzos-sys-include=<SysInclude>
                          Path to system headers on z/OS
  -M                      Like -MD, but also implies -E and writes to stdout by default
  --no-cuda-include-ptx=<value>
                          Do not include PTX for the following GPU architecture (e.g. sm_35) or 'all'. May be specified more than once.
  --no-cuda-version-check Don't error out if the detected version of the CUDA install is too low for the requested CUDA gpu architecture.
  --no-default-config     Disable loading default configuration files
  --no-gpu-bundle-output  Do not bundle output files of HIP device compilation
  -no-hip-rt              Do not link against HIP runtime libraries
  --no-offload-arch=<value>
                          Remove CUDA/HIP offloading device architecture (e.g. sm_35, gfx906) from the list of devices to compile for. 'all' resets the list to its default value.
  --no-offload-new-driver Don't Use the new driver for offloading compilation.
  --no-system-header-prefix=<prefix>
                          Treat all #include paths starting with <prefix> as not including a system header.
  -nobuiltininc           Disable builtin #include directories
  -nogpuinc               Do not add include paths for CUDA/HIP and do not include the default CUDA/HIP wrapper headers
  -nogpulib               Do not link device library for CUDA/HIP device compilation
  -nohipwrapperinc        Do not include the default HIP wrapper headers and include paths
  -nostdinc++             Disable standard #include directories for the C++ standard library
  --nvptx-arch-tool=<value>
                          Tool used for detecting NVIDIA GPU arch in the system.
  -ObjC++                 Treat source input files as Objective-C++ inputs
  -objcmt-allowlist-dir-path=<value>
                          Only modify files with a filename contained in the provided directory path
  -objcmt-atomic-property Make migration to 'atomic' properties
  -objcmt-migrate-all     Enable migration to modern ObjC
  -objcmt-migrate-annotation
                          Enable migration to property and method annotations
  -objcmt-migrate-designated-init
                          Enable migration to infer NS_DESIGNATED_INITIALIZER for initializer methods
  -objcmt-migrate-instancetype
                          Enable migration to infer instancetype for method result type
  -objcmt-migrate-literals
                          Enable migration to modern ObjC literals
  -objcmt-migrate-ns-macros
                          Enable migration to NS_ENUM/NS_OPTIONS macros
  -objcmt-migrate-property-dot-syntax
                          Enable migration of setter/getter messages to property-dot syntax
  -objcmt-migrate-property
                          Enable migration to modern ObjC property
  -objcmt-migrate-protocol-conformance
                          Enable migration to add protocol conformance on classes
  -objcmt-migrate-readonly-property
                          Enable migration to modern ObjC readonly property
  -objcmt-migrate-readwrite-property
                          Enable migration to modern ObjC readwrite property
  -objcmt-migrate-subscripting
                          Enable migration to modern ObjC subscripting
  -objcmt-ns-nonatomic-iosonly
                          Enable migration to use NS_NONATOMIC_IOSONLY macro for setting property's 'atomic' attribute
  -objcmt-returns-innerpointer-property
                          Enable migration to annotate property with NS_RETURNS_INNER_POINTER
  -objcmt-whitelist-dir-path=<value>
                          Alias for -objcmt-allowlist-dir-path
  -ObjC                   Treat source input files as Objective-C inputs
  -object-file-name=<file>
                          Set the output <file> for debug infos
  --offload-arch=<value>  Specify an offloading device architecture for CUDA, HIP, or OpenMP. (e.g. sm_35). If 'native' is used the compiler will detect locally installed architectures. For HIP offloading, the device architecture can be followed by target ID features delimited by a colon (e.g. gfx908:xnack+:sramecc-). May be specified more than once.
  --offload-device-only   Only compile for the offloading device.
  --offload-host-device   Only compile for the offloading host.
  --offload-host-only     Only compile for the offloading host.
  --offload-link          Use the new offloading linker to perform the link job.
  --offload-new-driver    Use the new driver for offloading compilation.
  --offload=<value>       Specify comma-separated list of offloading target triples (CUDA and HIP only)
  -o <file>               Write output to <file>
  -pedantic               Warn on language extensions
  -pg                     Enable mcount instrumentation
  -pipe                   Use pipes between commands, when possible
  --precompile            Only precompile the input
  -print-diagnostic-options
                          Print all of Clang's warning options
  -print-effective-triple Print the effective target triple
  -print-file-name=<file> Print the full library path of <file>
  -print-ivar-layout      Enable Objective-C Ivar layout bitmap print trace
  -print-libgcc-file-name Print the library path for the currently used compiler runtime library ("libgcc.a" or "libclang_rt.builtins.*.a")
  -print-multi-flags-experimental
                          Print the flags used for selecting multilibs (experimental)
  -print-prog-name=<name> Print the full program path of <name>
  -print-resource-dir     Print the resource directory pathname
  -print-rocm-search-dirs Print the paths used for finding ROCm installation
  -print-runtime-dir      Print the directory pathname containing clangs runtime libraries
  -print-search-dirs      Print the paths used for finding libraries and programs
  -print-supported-cpus   Print supported cpu models for the given target (if target is not specified, it will print the supported cpus for the default target)
  -print-target-triple    Print the normalized target triple
  -print-targets          Print the registered targets
  -pthread                Support POSIX threads in generated code
  --ptxas-path=<value>    Path to ptxas (used for compiling CUDA code)
  -P                      Disable linemarker output in -E mode
  -p                      Enable mcount instrumentation with prof
  -Qn                     Do not emit metadata containing compiler name and version
  -Qunused-arguments      Don't emit warning for unused driver arguments
  -Qy                     Emit metadata containing compiler name and version
  -relocatable-pch        Whether to build a relocatable precompiled header
  -rewrite-legacy-objc    Rewrite Legacy Objective-C source to C++
  -rewrite-objc           Rewrite Objective-C source to C++
  --rocm-device-lib-path=<value>
                          ROCm device library path. Alternative to rocm-path.
  --rocm-path=<value>     ROCm installation path, used for finding and automatically linking required bitcode libraries.
  -Rpass-analysis=<value> Report transformation analysis from optimization passes whose name matches the given POSIX regular expression
  -Rpass-missed=<value>   Report missed transformations by optimization passes whose name matches the given POSIX regular expression
  -Rpass=<value>          Report transformations performed by optimization passes whose name matches the given POSIX regular expression
  -rtlib=<value>          Compiler runtime library to use
  -R<remark>              Enable the specified remark
  -save-stats=<value>     Save llvm statistics.
  -save-stats             Save llvm statistics.
  -save-temps=<value>     Save intermediate compilation results.
  -save-temps             Save intermediate compilation results
  -serialize-diagnostics <value>
                          Serialize compiler diagnostics to a file
  -shared-libsan          Dynamically link the sanitizer runtime
  --start-no-unused-arguments
                          Don't emit warnings about unused arguments for the following arguments
  -static-libsan          Statically link the sanitizer runtime (Not supported for ASan, TSan or UBSan on darwin)
  -static-openmp          Use the static host OpenMP runtime while linking.
  -std=<value>            Language standard to compile for
  -stdlib++-isystem <directory>
                          Use directory as the C++ standard library include path
  -stdlib=<value>         C++ standard library to use
  -sycl-std=<value>       SYCL language standard to compile for.
  --system-header-prefix=<prefix>
                          Treat all #include paths starting with <prefix> as including a system header.
  -S                      Only run preprocess and compilation steps
  --target=<value>        Generate code for the given target
  -time                   Time individual commands
  -traditional-cpp        Enable some traditional CPP emulation
  -trigraphs              Process trigraph sequences
  -T <script>             Specify <script> as linker script
  -undef                  undef all system defines
  -unwindlib=<value>      Unwind library to use
  -U <macro>              Undefine macro <macro>
  --verify-debug-info     Verify the binary representation of debug output
  -verify-pch             Load and verify that a pre-compiled header file is not stale
  --version               Print version information
  -vfsoverlay <value>     Overlay the virtual filesystem described by file over the real file system. Additionally, pass this overlay file to the linker if it supports it
  -v                      Show commands to run and use verbose output
  -Wa,<arg>               Pass the comma separated arguments in <arg> to the assembler
  -Wdeprecated            Enable warnings for deprecated constructs and define __DEPRECATED
  -Wl,<arg>               Pass the comma separated arguments in <arg> to the linker
  -working-directory <value>
                          Resolve file paths relative to the specified directory
  -Wp,<arg>               Pass the comma separated arguments in <arg> to the preprocessor
  -W<warning>             Enable the specified warning
  -w                      Suppress all warnings
  -Xanalyzer <arg>        Pass <arg> to the static analyzer
  -Xarch_device <arg>     Pass <arg> to the CUDA/HIP device compilation
  -Xarch_host <arg>       Pass <arg> to the CUDA/HIP host compilation
  -Xassembler <arg>       Pass <arg> to the assembler
  -Xclang=<arg>           Alias for -Xclang
  -Xclang <arg>           Pass <arg> to clang -cc1
  -Xcuda-fatbinary <arg>  Pass <arg> to fatbinary invocation
  -Xcuda-ptxas <arg>      Pass <arg> to the ptxas assembler
  -Xlinker <arg>          Pass <arg> to the linker
  -Xoffload-linker<triple> <arg>
                          Pass <arg> to the offload linkers or the ones idenfied by -<triple>
  -Xopenmp-target=<triple> <arg>
                          Pass <arg> to the target offloading toolchain identified by <triple>.
  -Xopenmp-target <arg>   Pass <arg> to the target offloading toolchain.
  -Xpreprocessor <arg>    Pass <arg> to the preprocessor
  -x <language>           Treat subsequent input files as having type <language>
  -z <arg>                Pass -z <arg> to the linker




OVERVIEW: llvm .bc -> .bc modular optimizer and analysis printer

USAGE: opt [options] <input bitcode file>

OPTIONS:

Color Options:

  --color                                                               - Use colors in output (default=autodetect)

General options:

  --O0                                                                  - Optimization level 0. Similar to clang -O0. Use -passes='default<O0>' for the new PM
  --O1                                                                  - Optimization level 1. Similar to clang -O1. Use -passes='default<O1>' for the new PM
  --O2                                                                  - Optimization level 2. Similar to clang -O2. Use -passes='default<O2>' for the new PM
  --O3                                                                  - Optimization level 3. Similar to clang -O3. Use -passes='default<O3>' for the new PM
  --Os                                                                  - Like -O2 but size-conscious. Similar to clang -Os. Use -passes='default<Os>' for the new PM
  --Oz                                                                  - Like -O2 but optimize for code size above all else. Similar to clang -Oz. Use -passes='default<Oz>' for the new PM
  -S                                                                    - Write output as LLVM assembly
  --aarch64-neon-syntax=<value>                                         - Choose style of NEON code to emit from AArch64 backend:
    =generic                                                            -   Emit generic NEON assembly
    =apple                                                              -   Emit Apple-style NEON assembly
  --aarch64-use-aa                                                      - Enable the use of AA during codegen.
  --abort-on-max-devirt-iterations-reached                              - Abort when the max iterations for devirtualization CGSCC repeat pass is reached
  --addrsig                                                             - Emit an address-significance table
  --align-loops=<uint>                                                  - Default alignment for loops
  --allow-ginsert-as-artifact                                           - Allow G_INSERT to be considered an artifact. Hack around AMDGPU test infinite loops.
  --amdgpu-atomic-optimizer-strategy=<value>                            - Select DPP or Iterative strategy for scan
    =DPP                                                                -   Use DPP operations for scan
    =Iterative                                                          -   Use Iterative approach for scan
    =None                                                               -   Disable atomic optimizer
  --amdgpu-bypass-slow-div                                              - Skip 64-bit divide for dynamic 32-bit values
  --amdgpu-disable-loop-alignment                                       - Do not align and prefetch loops
  --amdgpu-dpp-combine                                                  - Enable DPP combiner
  --amdgpu-dump-hsa-metadata                                            - Dump AMDGPU HSA Metadata
  --amdgpu-enable-merge-m0                                              - Merge and hoist M0 initializations
  --amdgpu-enable-power-sched                                           - Enable scheduling to minimize mAI power bursts
  --amdgpu-promote-alloca-to-vector-limit=<uint>                        - Maximum byte size to consider promote alloca to vector
  --amdgpu-sdwa-peephole                                                - Enable SDWA peepholer
  --amdgpu-use-aa-in-codegen                                            - Enable the use of AA during codegen.
  --amdgpu-verify-hsa-metadata                                          - Verify AMDGPU HSA Metadata
  --amdgpu-vgpr-index-mode                                              - Use GPR indexing mode instead of movrel for vector indexing
  --arm-add-build-attributes                                            - 
  --arm-implicit-it=<value>                                             - Allow conditional instructions outdside of an IT block
    =always                                                             -   Accept in both ISAs, emit implicit ITs in Thumb
    =never                                                              -   Warn in ARM, reject in Thumb
    =arm                                                                -   Accept in ARM, reject in Thumb
    =thumb                                                              -   Warn in ARM, emit implicit ITs in Thumb
  --asm-show-inst                                                       - Emit internal instruction representation to assembly file
  --atomic-counter-update-promoted                                      - Do counter update using atomic fetch add  for promoted counters only
  --atomic-first-counter                                                - Use atomic fetch add for first counter in a function (usually the entry counter)
  --basic-block-sections=<all | <function list (file)> | labels | none> - Emit basic blocks into separate sections
  --bounds-checking-single-trap                                         - Use one trap block per function
  --bpf-stack-size=<int>                                                - Specify the BPF stack size limit
  --bugpoint-enable-legacy-pm                                           - Enable the legacy pass manager. This is strictly for bugpoint due to it not working with the new PM, please do not use otherwise.
  --cfg-hide-cold-paths=<number>                                        - Hide blocks with relative frequency below the given value
  --cfg-hide-deoptimize-paths                                           - 
  --cfg-hide-unreachable-paths                                          - 
  --code-model=<value>                                                  - Choose code model
    =tiny                                                               -   Tiny code model
    =small                                                              -   Small code model
    =kernel                                                             -   Kernel code model
    =medium                                                             -   Medium code model
    =large                                                              -   Large code model
  --codegen-opt-level=<uint>                                            - Override optimization level for codegen hooks, legacy PM only
  --cost-kind=<value>                                                   - Target cost kind
    =throughput                                                         -   Reciprocal throughput
    =latency                                                            -   Instruction latency
    =code-size                                                          -   Code size
    =size-latency                                                       -   Code size and latency
  --cs-profile-generate                                                 - Perform context sensitive PGO instrumentation
  --cs-profile-path=<string>                                            - Context sensitive profile file path
  --data-layout=<layout-string>                                         - data layout string to use
  --data-sections                                                       - Emit data into separate sections
  --debug-entry-values                                                  - Enable debug info for the debug entry values.
  --debug-info-correlate                                                - Use debug info to correlate profiles.
  --debugger-tune=<value>                                               - Tune debug info for a particular debugger
    =gdb                                                                -   gdb
    =lldb                                                               -   lldb
    =dbx                                                                -   dbx
    =sce                                                                -   SCE targets (e.g. PS4)
  --debugify-each                                                       - Start each pass with debugify and end it with check-debugify
  --debugify-export=<filename>                                          - Export per-pass debugify statistics to this file
  --debugify-func-limit=<ulong>                                         - Set max number of processed functions per pass.
  --debugify-level=<value>                                              - Kind of debug info to add
    =locations                                                          -   Locations only
    =location+variables                                                 -   Locations and Variables
  --debugify-quiet                                                      - Suppress verbose debugify output
  --denormal-fp-math=<value>                                            - Select which denormal numbers the code is permitted to require
    =ieee                                                               -   IEEE 754 denormal numbers
    =preserve-sign                                                      -   the sign of a  flushed-to-zero number is preserved in the sign of 0
    =positive-zero                                                      -   denormals are flushed to positive zero
    =dynamic                                                            -   denormals have unknown treatment
  --denormal-fp-math-f32=<value>                                        - Select which denormal numbers the code is permitted to require for float
    =ieee                                                               -   IEEE 754 denormal numbers
    =preserve-sign                                                      -   the sign of a  flushed-to-zero number is preserved in the sign of 0
    =positive-zero                                                      -   denormals are flushed to positive zero
    =dynamic                                                            -   denormals have unknown treatment
  --disable-auto-upgrade-debug-info                                     - Disable autoupgrade of debug info
  --disable-builtin=<string>                                            - Disable specific target library builtin function
  --disable-debug-info-type-map                                         - Don't use a uniquing type map for debug info
  --disable-i2p-p2i-opt                                                 - Disables inttoptr/ptrtoint roundtrip optimization
  --disable-loop-unrolling                                              - Disable loop unrolling in all relevant passes
  --disable-promote-alloca-to-lds                                       - Disable promote alloca to LDS
  --disable-promote-alloca-to-vector                                    - Disable promote alloca to vector
  --disable-simplify-libcalls                                           - Disable simplify-libcalls
  --disable-tail-calls                                                  - Never emit tail calls
  --do-counter-promotion                                                - Do counter register promotion
  --dot-cfg-mssa=<file name for generated dot file>                     - file name for generated dot file
  --dwarf-version=<int>                                                 - Dwarf version
  --dwarf64                                                             - Generate debugging info in the 64-bit DWARF format
  --emit-call-site-info                                                 - Emit call site debug information, if debug information is enabled.
  --emit-compact-unwind-non-canonical                                   - Whether to try to emit Compact Unwind for non canonical entries.
  --emit-dwarf-unwind=<value>                                           - Whether to emit DWARF EH frame entries.
    =always                                                             -   Always emit EH frame entries
    =no-compact-unwind                                                  -   Only emit EH frame entries when compact unwind is not available
    =default                                                            -   Use target platform default
  --emscripten-cxx-exceptions-allowed=<string>                          - The list of function names in which Emscripten-style exception handling is enabled (see emscripten EMSCRIPTEN_CATCHING_ALLOWED options)
  --emulated-tls                                                        - Use emulated TLS model
  --enable-approx-func-fp-math                                          - Enable FP math optimizations that assume approx func
  --enable-cse-in-irtranslator                                          - Should enable CSE in irtranslator
  --enable-cse-in-legalizer                                             - Should enable CSE in Legalizer
  --enable-debugify                                                     - Start the pipeline with debugify and end it with check-debugify
  --enable-emscripten-cxx-exceptions                                    - WebAssembly Emscripten-style exception handling
  --enable-emscripten-sjlj                                              - WebAssembly Emscripten-style setjmp/longjmp handling
  --enable-gvn-hoist                                                    - Enable the GVN hoisting pass (default = off)
  --enable-gvn-memdep                                                   - 
  --enable-gvn-sink                                                     - Enable the GVN sinking pass (default = off)
  --enable-jmc-instrument                                               - Instrument functions with a call to __CheckForDebuggerJustMyCode
  --enable-load-in-loop-pre                                             - 
  --enable-load-pre                                                     - 
  --enable-loop-simplifycfg-term-folding                                - 
  --enable-name-compression                                             - Enable name/filename string compression
  --enable-no-infs-fp-math                                              - Enable FP math optimizations that assume no +-Infs
  --enable-no-nans-fp-math                                              - Enable FP math optimizations that assume no NaNs
  --enable-no-signed-zeros-fp-math                                      - Enable FP math optimizations that assume the sign of 0 is insignificant
  --enable-no-trapping-fp-math                                          - Enable setting the FP exceptions build attribute not to use exceptions
  --enable-split-backedge-in-load-pre                                   - 
  --enable-unsafe-fp-math                                               - Enable optimizations that may decrease FP precision
  --exception-model=<value>                                             - exception model
    =default                                                            -   default exception handling model
    =dwarf                                                              -   DWARF-like CFI based exception handling
    =sjlj                                                               -   SjLj exception handling
    =arm                                                                -   ARM EHABI exceptions
    =wineh                                                              -   Windows exception model
    =wasm                                                               -   WebAssembly exception handling
  --experimental-debug-variable-locations                               - Use experimental new value-tracking variable locations
  -f                                                                    - Enable binary output on terminals
  --fatal-warnings                                                      - Treat warnings as errors
  --filetype=<value>                                                    - Choose a file type (not all types are supported by all targets):
    =asm                                                                -   Emit an assembly ('.s') file
    =obj                                                                -   Emit a native object ('.o') file
    =null                                                               -   Emit nothing, for performance testing
  --float-abi=<value>                                                   - Choose float ABI type
    =default                                                            -   Target default float ABI type
    =soft                                                               -   Soft float ABI (implied by -soft-float)
    =hard                                                               -   Hard float ABI (uses FP registers)
  --force-dwarf-frame-section                                           - Always emit a debug frame section.
  --force-tail-folding-style=<value>                                    - Force the tail folding style
    =none                                                               -   Disable tail folding
    =data                                                               -   Create lane mask for data only, using active.lane.mask intrinsic
    =data-without-lane-mask                                             -   Create lane mask with compare/stepvector
    =data-and-control                                                   -   Create lane mask using active.lane.mask intrinsic, and use it for both data and control flow
    =data-and-control-without-rt-check                                  -   Similar to data-and-control, but remove the runtime check
  --fp-contract=<value>                                                 - Enable aggressive formation of fused FP ops
    =fast                                                               -   Fuse FP ops whenever profitable
    =on                                                                 -   Only fuse 'blessed' FP ops.
    =off                                                                -   Only fuse FP ops when the result won't be affected.
  --frame-pointer=<value>                                               - Specify frame pointer elimination optimization
    =all                                                                -   Disable frame pointer elimination
    =non-leaf                                                           -   Disable frame pointer elimination for non-leaf frame
    =none                                                               -   Enable frame pointer elimination
  --fs-profile-debug-bw-threshold=<uint>                                - Only show debug message if the source branch weight is greater  than this value.
  --fs-profile-debug-prob-diff-threshold=<uint>                         - Only show debug message if the branch probility is greater than this value (in percentage).
  --function-sections                                                   - Emit functions into separate sections
  --generate-merged-base-profiles                                       - When generating nested context-sensitive profiles, always generate extra base profile for function with all its context profiles merged into it.
  --gpsize=<uint>                                                       - Global Pointer Addressing Size.  The default size is 8.
  --hash-based-counter-split                                            - Rename counter variable of a comdat function based on cfg hash
  --hexagon-rdf-limit=<uint>                                            - 
  --hot-cold-split                                                      - Enable hot-cold splitting pass
  --ignore-xcoff-visibility                                             - Not emit the visibility attribute for asm in AIX OS or give all symbols 'unspecified' visibility in XCOFF object file
  --import-all-index                                                    - Import all external functions in index.
  --incremental-linker-compatible                                       - When used with filetype=obj, emit an object file which can be used with an incremental linker
  --instcombine-code-sinking                                            - Enable code sinking
  --instcombine-guard-widening-window=<uint>                            - How wide an instruction window to bypass looking for another guard
  --instcombine-max-num-phis=<uint>                                     - Maximum number phis to handle in intptr/ptrint folding
  --instcombine-max-sink-users=<uint>                                   - Maximum number of undroppable users for instruction sinking
  --instcombine-maxarray-size=<uint>                                    - Maximum array size considered when doing a combine
  --instcombine-negator-enabled                                         - Should we attempt to sink negations?
  --instcombine-negator-max-depth=<uint>                                - What is the maximal lookup depth when trying to check for viability of negation sinking.
  --instrprof-atomic-counter-update-all                                 - Make all profile counter updates atomic (for testing only)
  --internalize-public-api-file=<filename>                              - A file containing list of symbol names to preserve
  --internalize-public-api-list=<list>                                  - A list of symbol names to preserve
  --iterative-counter-promotion                                         - Allow counter promotion across the whole loop nest.
  --load=<pluginfilename>                                               - Load the specified plugin
  --load-pass-plugin=<string>                                           - Load passes from plugin library
  Optimizations available (use '-passes=' for the new pass manager)
      --aa                                                                 - Function Alias Analysis Results
      --aa-eval                                                            - Exhaustive Alias Analysis Precision Evaluator
      --aarch64-O0-prelegalizer-combiner                                   - Combine AArch64 machine instrs before legalization
      --aarch64-a57-fp-load-balancing                                      - AArch64 A57 FP Load-Balancing
      --aarch64-branch-targets                                             - AArch64 Branch Targets
      --aarch64-ccmp                                                       - AArch64 CCMP Pass
      --aarch64-collect-loh                                                - AArch64 Collect Linker Optimization Hint (LOH)
      --aarch64-condopt                                                    - AArch64 CondOpt Pass
      --aarch64-copyelim                                                   - AArch64 redundant copy elimination pass
      --aarch64-dead-defs                                                  - AArch64 Dead register definitions
      --aarch64-expand-pseudo                                              - AArch64 pseudo instruction expansion pass
      --aarch64-falkor-hwpf-fix                                            - Falkor HW Prefetch Fix
      --aarch64-falkor-hwpf-fix-late                                       - Falkor HW Prefetch Fix Late Phase
      --aarch64-fix-cortex-a53-835769-pass                                 - AArch64 fix for A53 erratum 835769
      --aarch64-globals-tagging                                            - AArch64 Globals Tagging Pass
      --aarch64-isel                                                       - AArch64 Instruction Selection
      --aarch64-jump-tables                                                - AArch64 compress jump tables pass
      --aarch64-ldst-opt                                                   - AArch64 load / store optimization pass
      --aarch64-local-dynamic-tls-cleanup                                  - AArch64 Local Dynamic TLS Access Clean-up
      --aarch64-lower-homogeneous-prolog-epilog                            - AArch64 homogeneous prolog/epilog lowering pass
      --aarch64-mi-peephole-opt                                            - AArch64 MI Peephole Optimization
      --aarch64-post-select-optimize                                       - Optimize AArch64 selected instructions
      --aarch64-postlegalizer-combiner                                     - Combine AArch64 MachineInstrs after legalization
      --aarch64-postlegalizer-lowering                                     - Lower AArch64 MachineInstrs after legalization
      --aarch64-prelegalizer-combiner                                      - Combine AArch64 machine instrs before legalization
      --aarch64-promote-const                                              - AArch64 Promote Constant Pass
      --aarch64-simd-scalar                                                - AdvSIMD Scalar Operation Optimization
      --aarch64-simdinstr-opt                                              - AArch64 SIMD instructions optimization pass
      --aarch64-sls-hardening                                              - AArch64 sls hardening pass
      --aarch64-sme-abi                                                    - SME ABI Pass
      --aarch64-speculation-hardening                                      - AArch64 speculation hardening pass
      --aarch64-stack-tagging                                              - AArch64 Stack Tagging
      --aarch64-stack-tagging-pre-ra                                       - AArch64 Stack Tagging PreRA Pass
      --aarch64-stp-suppress                                               - AArch64 Store Pair Suppression
      --aarch64-sve-intrinsic-opts                                         - SVE intrinsics optimizations
      --alloca-hoisting                                                    - Hoisting alloca instructions in non-entry blocks to the entry block
      --always-inline                                                      - Inliner for always_inline functions
      --amdgpu-aa                                                          - AMDGPU Address space based Alias Analysis
      --amdgpu-aa-wrapper                                                  - AMDGPU Address space based Alias Analysis Wrapper
      --amdgpu-always-inline                                               - AMDGPU Inline All Functions
      --amdgpu-annotate-kernel-features                                    - Add AMDGPU function attributes
      --amdgpu-annotate-uniform                                            - Add AMDGPU uniform metadata
      --amdgpu-argument-reg-usage-info                                     - Argument Register Usage Information Storage
      --amdgpu-atomic-optimizer                                            - AMDGPU atomic optimizations
      --amdgpu-attributor                                                  - AMDGPU Attributor
      --amdgpu-codegenprepare                                              - AMDGPU IR optimizations
      --amdgpu-insert-delay-alu                                            - AMDGPU Insert Delay ALU
      --amdgpu-isel                                                        - AMDGPU DAG->DAG Pattern Instruction Selection
      --amdgpu-late-codegenprepare                                         - AMDGPU IR late optimizations
      --amdgpu-lower-ctor-dtor                                             - Lower ctors and dtors for AMDGPU
      --amdgpu-lower-enqueued-block                                        - Lower OpenCL enqueued blocks
      --amdgpu-lower-kernel-arguments                                      - AMDGPU Lower Kernel Arguments
      --amdgpu-lower-kernel-attributes                                     - AMDGPU Kernel Attributes
      --amdgpu-lower-module-lds                                            - Lower uses of LDS variables from non-kernel functions
      --amdgpu-nsa-reassign                                                - GCN NSA Reassign
      --amdgpu-perf-hint                                                   - Analysis if a function is memory bound
      --amdgpu-postlegalizer-combiner                                      - Combine AMDGPU machine instrs after legalization
      --amdgpu-pre-ra-long-branch-reg                                      - AMDGPU Pre-RA Long Branch Reg
      --amdgpu-pre-ra-optimizations                                        - Pre-RA optimizations
      --amdgpu-prelegalizer-combiner                                       - Combine AMDGPU machine instrs before legalization
      --amdgpu-printf-runtime-binding                                      - AMDGPU Printf lowering
      --amdgpu-promote-alloca                                              - AMDGPU promote alloca to vector or LDS
      --amdgpu-promote-alloca-to-vector                                    - AMDGPU promote alloca to vector
      --amdgpu-promote-kernel-arguments                                    - AMDGPU Promote Kernel Arguments
      --amdgpu-regbank-combiner                                            - Combine AMDGPU machine instrs after regbankselect
      --amdgpu-regbankselect                                               - AMDGPU Register Bank Select
      --amdgpu-remove-incompatible-functions                               - AMDGPU Remove Incompatible Functions
      --amdgpu-resource-usage                                              - Function register usage analysis
      --amdgpu-rewrite-out-arguments                                       - AMDGPU Rewrite Out Arguments
      --amdgpu-rewrite-undef-for-phi                                       - Rewrite undef for PHI
      --amdgpu-simplifylib                                                 - Simplify well-known AMD library calls
      --amdgpu-unify-divergent-exit-nodes                                  - Unify divergent function exit nodes
      --amdgpu-unify-metadata                                              - Unify multiple OpenCL metadata due to linking
      --amdgpu-usenative                                                   - Replace builtin math calls with that native versions.
      --amode-opt                                                          - Optimize addressing mode
      --arm-block-placement                                                - ARM block placement
      --arm-branch-targets                                                 - ARM Branch Targets
      --arm-cp-islands                                                     - ARM constant island placement and branch shortening pass
      --arm-execution-domain-fix                                           - ARM Execution Domain Fix
      --arm-fix-cortex-a57-aes-1742098                                     - ARM fix for Cortex-A57 AES Erratum 1742098
      --arm-isel                                                           - ARM Instruction Selection
      --arm-ldst-opt                                                       - ARM load / store optimization pass
      --arm-low-overhead-loops                                             - ARM Low Overhead Loops pass
      --arm-mve-gather-scatter-lowering                                    - MVE gather/scattering lowering pass
      --arm-mve-vpt                                                        - ARM MVE VPT block pass
      --arm-mve-vpt-opts                                                   - ARM MVE TailPred and VPT Optimisations pass
      --arm-parallel-dsp                                                   - Transform functions to use DSP intrinsics
      --arm-prera-ldst-opt                                                 - ARM pre- register allocation load / store optimization pass
      --arm-pseudo                                                         - ARM pseudo instruction expansion pass
      --arm-sls-hardening                                                  - ARM sls hardening pass
      --assume-builder                                                     - Assume Builder
      --assumption-cache-tracker                                           - Assumption Cache Tracker
      --atomic-expand                                                      - Expand Atomic instructions
      --avr-expand-pseudo                                                  - AVR pseudo instruction expansion pass
      --avr-isel                                                           - AVR DAG->DAG Instruction Selection
      --avr-shift-expand                                                   - AVR Shift Expansion
      --barrier                                                            - A No-Op Barrier Pass
      --basic-aa                                                           - Basic Alias Analysis (stateless AA impl)
      --basiccg                                                            - CallGraph Construction
      --bbsections-profile-reader                                          - Reads and parses a basic block sections profile.
      --block-freq                                                         - Block Frequency Analysis
      --bpf-check-and-opt-ir                                               - BPF Check And Adjust IR
      --bpf-isel                                                           - BPF DAG->DAG Pattern Instruction Selection
      --bpf-mi-trunc-elim                                                  - BPF MachineSSA Peephole Optimization For TRUNC Eliminate
      --bpf-mi-zext-elim                                                   - BPF MachineSSA Peephole Optimization For ZEXT Eliminate
      --branch-prob                                                        - Branch Probability Analysis
      --break-crit-edges                                                   - Break critical edges in CFG
      --callbrprepare                                                      - Prepare callbr
      --canon-freeze                                                       - Canonicalize Freeze Instructions in Loops
      --check-debugify                                                     - Check debug info from -debugify
      --check-debugify-function                                            - Check debug info from -debugify-function
      --codegenprepare                                                     - Optimize for code generation
      --consthoist                                                         - Constant Hoisting
      --cost-model                                                         - Cost Model Analysis
      --cseinfo                                                            - Analysis containing CSE Info
      --cycles                                                             - Cycle Info Analysis
      --da                                                                 - Dependence Analysis
      --dce                                                                - Dead Code Elimination
      --deadargelim                                                        - Dead Argument Elimination
      --deadarghaX0r                                                       - Dead Argument Hacking (BUGPOINT USE ONLY; DO NOT USE)
      --debugify                                                           - Attach debug info to everything
      --debugify-function                                                  - Attach debug info to a function
      --delinearize                                                        - Delinearization
      --domfrontier                                                        - Dominance Frontier Construction
      --domtree                                                            - Dominator Tree Construction
      --dot-callgraph                                                      - Print call graph to 'dot' file
      --dot-cfg                                                            - Print CFG of function to 'dot' file
      --dot-cfg-only                                                       - Print CFG of function to 'dot' file (with no function bodies)
      --dot-dom                                                            - Print dominance tree of function to 'dot' file
      --dot-dom-only                                                       - Print dominance tree of function to 'dot' file (with no function bodies)
      --dot-postdom                                                        - Print postdominance tree of function to 'dot' file
      --dot-postdom-only                                                   - Print postdominance tree of function to 'dot' file (with no function bodies)
      --dot-regions                                                        - Print regions of function to 'dot' file
      --dot-regions-only                                                   - Print regions of function to 'dot' file (with no function bodies)
      --dot-scops                                                          - Polly - Print Scops of function
      --dot-scops-only                                                     - Polly - Print Scops of function (with no function bodies)
      --dwarfehprepare                                                     - Prepare DWARF exceptions
      --early-cse                                                          - Early CSE
      --early-cse-memssa                                                   - Early CSE w/ MemorySSA
      --edge-bundles                                                       - Bundle Machine CFG Edges
      --expand-large-div-rem                                               - Expand large div/rem
      --expand-large-fp-convert                                            - Expand large fp convert
      --expand-reductions                                                  - Expand reduction intrinsics
      --expandmemcmp                                                       - Expand memcmp() to load/stores
      --expandvp                                                           - Expand vector predication intrinsics
      --external-aa                                                        - External Alias Analysis
      --fastpretileconfig                                                  - Fast Tile Register Preconfigure
      --fasttileconfig                                                     - Fast Tile Register Configure
      --fix-irreducible                                                    - Convert irreducible control-flow into natural loops
      --flattencfg                                                         - Flatten the CFG
      --gcn-create-vopd                                                    - GCN Create VOPD Instructions
      --gcn-dpp-combine                                                    - GCN DPP Combine
      --generic-to-nvvm                                                    - Ensure that the global variables are in the global address space
      --gisel-known-bits                                                   - Analysis for ComputingKnownBits
      --global-merge                                                       - Merge global variables
      --globals-aa                                                         - Globals Alias Analysis
      --guard-widening                                                     - Widen guards
      --gvn                                                                - Global Value Numbering
      --hexagon-bit-simplify                                               - Hexagon bit simplification
      --hexagon-cext-opt                                                   - Hexagon constant-extender optimization
      --hexagon-constp                                                     - Hexagon Constant Propagation
      --hexagon-copy-combine                                               - Hexagon Copy-To-Combine Pass
      --hexagon-early-if                                                   - Hexagon early if conversion
      --hexagon-gen-mux                                                    - Hexagon generate mux instructions
      --hexagon-isel                                                       - Hexagon DAG->DAG Pattern Instruction Selection
      --hexagon-loop-idiom                                                 - Recognize Hexagon-specific loop idioms
      --hexagon-nvj                                                        - Hexagon NewValueJump
      --hexagon-packetizer                                                 - Hexagon Packetizer
      --hexagon-rdf-opt                                                    - Hexagon RDF optimizations
      --hexagon-split-double                                               - Hexagon Split Double Registers
      --hexagon-vc                                                         - Hexagon Vector Combine
      --hexagon-vextract                                                   - Hexagon optimize vextract
      --hexagon-vlcr                                                       - Hexagon-specific predictive commoning for HVX vectors
      --hwloops                                                            - Hexagon Hardware Loops
      --indirectbr-expand                                                  - Expand indirectbr instructions
      --infer-address-spaces                                               - Infer address spaces
      --instcombine                                                        - Combine redundant instructions
      --instcount                                                          - Counts the various types of Instructions
      --instruction-select                                                 - Select target instructions out of generic instructions
      --instsimplify                                                       - Remove redundant instructions
      --interleaved-access                                                 - Lower interleaved memory accesses to target specific intrinsics
      --interleaved-load-combine                                           - Combine interleaved loads into wide loads and shufflevector instructions
      --intervals                                                          - Interval Partition Construction
      --ir-similarity-identifier                                           - ir-similarity-identifier
      --irtranslator                                                       - IRTranslator LLVM IR -> MI
      --iv-users                                                           - Induction Variable Users
      --jmc-instrument                                                     - Instrument function entry with call to __CheckForDebuggerJustMyCode
      --kcfi                                                               - Insert KCFI indirect call checks
      --lanai-isel                                                         - Lanai DAG->DAG Pattern Instruction Selection
      --lazy-block-freq                                                    - Lazy Block Frequency Analysis
      --lazy-branch-prob                                                   - Lazy Branch Probability Analysis
      --lazy-value-info                                                    - Lazy Value Information Analysis
      --lcssa                                                              - Loop-Closed SSA Form Pass
      --lcssa-verification                                                 - LCSSA Verifier
      --legalizer                                                          - Legalize the Machine IR a function's Machine IR
      --licm                                                               - Loop Invariant Code Motion
      --liveintervals                                                      - Live Interval Analysis
      --liveregmatrix                                                      - Live Register Matrix
      --livevars                                                           - Live Variable Analysis
      --load-store-vectorizer                                              - Vectorize load and store instructions
      --loadstore-opt                                                      - Generic memory optimizations
      --localizer                                                          - Move/duplicate certain instructions close to their use
      --loongarch-isel                                                     - LoongArch DAG->DAG Pattern Instruction Selection
      --loongarch-prera-expand-pseudo                                      - LoongArch Pre-RA pseudo instruction expansion pass
      --loop-data-prefetch                                                 - Loop Data Prefetch
      --loop-extract                                                       - Extract loops into new functions
      --loop-extract-single                                                - Extract at most one loop into a new function
      --loop-guard-widening                                                - Widen guards (within a single loop, as a loop pass)
      --loop-instsimplify                                                  - Simplify instructions in loops
      --loop-predication                                                   - Loop predication
      --loop-reduce                                                        - Loop Strength Reduction
      --loop-rotate                                                        - Rotate Loops
      --loop-simplify                                                      - Canonicalize natural loops
      --loop-simplifycfg                                                   - Simplify loop CFG
      --loop-sink                                                          - Loop Sink
      --loop-unroll                                                        - Unroll loops
      --loops                                                              - Natural Loop Information
      --lower-amx-intrinsics                                               - Lower AMX intrinsics
      --lower-amx-type                                                     - Lower AMX type for load/store
      --lower-constant-intrinsics                                          - Lower constant intrinsics
      --lower-expect                                                       - Lower 'expect' Intrinsics
      --lower-global-dtors                                                 - Lower @llvm.global_dtors via `__cxa_atexit`
      --lower-guard-intrinsic                                              - Lower the guard intrinsic to normal control flow
      --lower-widenable-condition                                          - Lower the widenable condition to default true value
      --loweratomic                                                        - Lower atomic intrinsics to non-atomic form
      --lowerinvoke                                                        - Lower invoke and unwind, for unwindless code generators
      --lowerswitch                                                        - Lower SwitchInst's to branches
      --lowertilecopy                                                      - Tile Copy Lowering
      --m68k-collapse-movem                                                - M68k MOVEM collapser pass
      --m68k-create-global-base-reg                                        - M68k PIC Global Base Reg Initialization
      --m68k-expand-pseudo                                                 - M68k pseudo instruction expansion pass
      --m68k-isel                                                          - M68k DAG->DAG Pattern Instruction Selection
      --machine-block-freq                                                 - Machine Block Frequency Analysis
      --machine-branch-prob                                                - Machine Branch Probability Analysis
      --machine-cycles                                                     - Machine Cycle Info Analysis
      --machine-domfrontier                                                - Machine Dominance Frontier Construction
      --machine-loops                                                      - Machine Natural Loop Construction
      --machine-trace-metrics                                              - Machine Trace Metrics
      --machinedomtree                                                     - MachineDominator Tree Construction
      --machinepostdomtree                                                 - MachinePostDominator Tree Construction
      --make-guards-explicit                                               - Lower the guard intrinsic to explicit control flow form
      --mem2reg                                                            - Promote Memory to Register
      --memdep                                                             - Memory Dependence Analysis
      --memoryssa                                                          - Memory SSA
      --mergeicmps                                                         - Merge contiguous icmps into a memcmp
      --mergereturn                                                        - Unify function exit nodes
      --micromips-reduce-size                                              - MicroMips instruction size reduce pass
      --mips-branch-expansion                                              - Expand out of range branch instructions and fix forbidden slot hazards
      --mips-delay-slot-filler                                             - Fill delay slot for MIPS
      --mips-isel                                                          - MIPS DAG->DAG Pattern Instruction Selection
      --mips-postlegalizer-combiner                                        - Combine Mips machine instrs after legalization
      --mips-prelegalizer-combiner                                         - Combine Mips machine instrs before legalization
      --mips-vr4300-mulmul-fix                                             - Mips VR4300 mulmul bugfix
      --mldst-motion                                                       - MergedLoadStoreMotion
      --module-summary-analysis                                            - Module Summary Analysis
      --module-summary-info                                                - Module summary info
      --msp430-isel                                                        - MSP430 DAG->DAG Pattern Instruction Selection
      --mve-laneinterleave                                                 - MVE lane interleaving
      --mve-tail-predication                                               - Transform predicated vector loops to use MVE tail predication
      --nary-reassociate                                                   - Nary reassociation
      --nvptx-aa                                                           - NVPTX Address space based Alias Analysis
      --nvptx-aa-wrapper                                                   - NVPTX Address space based Alias Analysis Wrapper
      --nvptx-assign-valid-global-names                                    - Assign valid PTX names to globals
      --nvptx-atomic-lower                                                 - Lower atomics of local memory to simple load/stores
      --nvptx-isel                                                         - NVPTX DAG->DAG Pattern Instruction Selection
      --nvptx-lower-aggr-copies                                            - Lower aggregate copies, and llvm.mem* intrinsics into loops
      --nvptx-lower-alloca                                                 - Lower Alloca
      --nvptx-lower-args                                                   - Lower arguments (NVPTX)
      --nvptx-lower-ctor-dtor                                              - Lower ctors and dtors for NVPTX
      --nvptx-lower-unreachable                                            - Lower Unreachable
      --nvptx-proxyreg-erasure                                             - NVPTX ProxyReg Erasure
      --nvvm-intr-range                                                    - Add !range metadata to NVVM intrinsics.
      --nvvm-reflect                                                       - Replace occurrences of __nvvm_reflect() calls with 0/1
      --opt-remark-emitter                                                 - Optimization Remark Emitter
      --packets                                                            - R600 Packetizer
      --partially-inline-libcalls                                          - Partially inline calls to library functions
      --phi-values                                                         - Phi Values Analysis
      --place-backedge-safepoints-impl                                     - Place Backedge Safepoints
      --polly-ast                                                          - Polly - Generate an AST from the SCoP (isl)
      --polly-canonicalize                                                 - Polly - Run canonicalization passes
      --polly-codegen                                                      - Polly - Create LLVM-IR from SCoPs
      --polly-dce                                                          - Polly - Remove dead iterations
      --polly-delicm                                                       - Polly - DeLICM/DePRE
      --polly-dependences                                                  - Polly - Calculate dependences
      --polly-detect                                                       - Polly - Detect static control parts (SCoPs)
      --polly-dump-module                                                  - Polly - Dump Module
      --polly-export-jscop                                                 - Polly - Export Scops as JSON (Writes a .jscop file for each Scop)
      --polly-flatten-schedule                                             - Polly - Flatten schedule
      --polly-function-dependences                                         - Polly - Calculate dependences for all the SCoPs of a function
      --polly-function-scops                                               - Polly - Create polyhedral description of all Scops of a function
      --polly-import-jscop                                                 - Polly - Import Scops from JSON (Reads a .jscop file for each Scop)
      --polly-mse                                                          - Polly - Maximal static expansion of SCoP
      --polly-opt-isl                                                      - Polly - Optimize schedule of SCoP
      --polly-optree                                                       - Polly - Forward operand tree
      --polly-prepare                                                      - Polly - Prepare code for polly
      --polly-print-ast                                                    - Polly - Print the AST from a SCoP (isl)
      --polly-print-delicm                                                 - Polly - Print DeLICM/DePRE
      --polly-print-dependences                                            - Polly - Print dependences
      --polly-print-detect                                                 - Polly - Print static control parts (SCoPs)
      --polly-print-flatten-schedule                                       - Polly - Print flattened schedule
      --polly-print-function-dependences                                   - Polly - Print dependences for all the SCoPs of a function
      --polly-print-function-scops                                         - Polly - Print polyhedral description of all Scops of a function
      --polly-print-import-jscop                                           - Polly - Print Scop import result
      --polly-print-opt-isl                                                - Polly - Print optimizer schedule of SCoP
      --polly-print-optree                                                 - Polly - Print forward operand tree result
      --polly-print-scops                                                  - Polly - Print polyhedral description of Scops
      --polly-print-simplify                                               - Polly - Print Simplify actions
      --polly-prune-unprofitable                                           - Polly - Prune unprofitable SCoPs
      --polly-scop-inliner                                                 - inline functions based on how much of the function is a scop.
      --polly-scops                                                        - Polly - Create polyhedral description of Scops
      --polly-simplify                                                     - Polly - Simplify
      --polyhedral-info                                                    - Polly - Interface to polyhedral analysis engine
      --postdomtree                                                        - Post-Dominator Tree Construction
      --ppc-atomic-expand                                                  - PowerPC Expand Atomic
      --ppc-bool-ret-to-int                                                - Convert i1 constants to i32/i64 if they are returned
      --ppc-branch-coalescing                                              - Branch Coalescing
      --ppc-branch-select                                                  - PowerPC Branch Selector
      --ppc-ctrloops                                                       - PowerPC CTR loops generation
      --ppc-early-ret                                                      - PowerPC Early-Return Creation
      --ppc-expand-isel                                                    - PowerPC Expand ISEL Generation
      --ppc-gen-scalar-mass                                                - Generate Scalar MASS entries
      --ppc-isel                                                           - PowerPC DAG->DAG Pattern Instruction Selection
      --ppc-loop-instr-form-prep                                           - Prepare loop for ppc preferred instruction forms
      --ppc-lower-massv-entries                                            - Lower MASSV entries
      --ppc-mi-peepholes                                                   - PowerPC MI Peephole Optimization
      --ppc-pre-emit-peephole                                              - PowerPC Pre-Emit Peephole
      --ppc-reduce-cr-ops                                                  - PowerPC Reduce CR logical Operation
      --ppc-tls-dynamic-call                                               - PowerPC TLS Dynamic Call Fixup
      --ppc-toc-reg-deps                                                   - PowerPC TOC Register Dependencies
      --ppc-vsx-copy                                                       - PowerPC VSX Copy Legalization
      --ppc-vsx-fma-mutate                                                 - PowerPC VSX FMA Mutation
      --ppc-vsx-swaps                                                      - PowerPC VSX Swap Removal
      --pre-amx-config                                                     - Pre AMX Tile Config
      --pre-isel-intrinsic-lowering                                        - Pre-ISel Intrinsic Lowering
      --print-callgraph                                                    - Print a call graph
      --print-function                                                     - Print function to stderr
      --print-lazy-value-info                                              - Lazy Value Info Printer Pass
      --print-module                                                       - Print module to stderr
      --print-polyhedral-info                                              - Polly - Print interface to polyhedral analysis engine analysis
      --print-predicateinfo                                                - PredicateInfo Printer
      --profile-summary-info                                               - Profile summary info
      --pseudo-probe-inserter                                              - Insert pseudo probe annotations for value profiling
      --r600-expand-special-instrs                                         - R600ExpandSpecialInstrs
      --r600cf                                                             - R600 Control Flow Finalizer
      --r600mergeclause                                                    - R600 Clause Merge
      --reaching-deps-analysis                                             - ReachingDefAnalysis
      --reassociate                                                        - Reassociate expressions
      --redundant-dbg-inst-elim                                            - Redundant Dbg Instruction Elimination
      --reg2mem                                                            - Demote all values to stack slots
      --regbankselect                                                      - Assign register bank of generic virtual registers
      --regions                                                            - Detect single entry single exit regions
      --replace-with-veclib                                                - Replace intrinsics with calls to vector library
      --rewrite-partial-reg-uses                                           - Rewrite Partial Register Uses
      --riscv-codegenprepare                                               - RISC-V CodeGenPrepare
      --riscv-expand-pseudo                                                - RISC-V pseudo instruction expansion pass
      --riscv-gather-scatter-lowering                                      - RISC-V gather/scatter lowering pass
      --riscv-init-undef                                                   - RISC-V init undef pass
      --riscv-insert-read-write-csr                                        - RISC-V Insert Read/Write CSR Pass
      --riscv-insert-vsetvli                                               - RISC-V Insert VSETVLI pass
      --riscv-isel                                                         - RISC-V DAG->DAG Pattern Instruction Selection
      --riscv-make-compressible                                            - RISC-V Make Compressible
      --riscv-merge-base-offset                                            - RISC-V Merge Base Offset
      --riscv-move-merge                                                   - RISC-V Zcmp move merging pass
      --riscv-opt-w-instrs                                                 - RISC-V Optimize W Instructions
      --riscv-prera-expand-pseudo                                          - RISC-V Pre-RA pseudo instruction expansion pass
      --riscv-push-pop-opt                                                 - RISC-V Zcmp Push/Pop optimization pass
      --safe-stack                                                         - Safe Stack instrumentation pass
      --scalar-evolution                                                   - Scalar Evolution Analysis
      --scalarize-masked-mem-intrin                                        - Scalarize unsupported masked memory intrinsics
      --scalarizer                                                         - Scalarize vector operations
      --scev-aa                                                            - ScalarEvolution-based Alias Analysis
      --scoped-noalias-aa                                                  - Scoped NoAlias Alias Analysis
      --select-optimize                                                    - Optimize selects
      --separate-const-offset-from-gep                                     - Split GEPs to a variadic base and a constant offset for better CSE
      --si-annotate-control-flow                                           - Annotate SI Control Flow
      --si-fix-sgpr-copies                                                 - SI Fix SGPR copies
      --si-fix-vgpr-copies                                                 - SI Fix VGPR copies
      --si-fold-operands                                                   - SI Fold Operands
      --si-form-memory-clauses                                             - SI Form memory clauses
      --si-i1-copies                                                       - SI Lower i1 Copies
      --si-insert-hard-clauses                                             - SI Insert Hard Clauses
      --si-insert-waitcnts                                                 - SI Insert Waitcnts
      --si-late-branch-lowering                                            - SI insert s_cbranch_execz instructions
      --si-load-store-opt                                                  - SI Load Store Optimizer
      --si-lower-control-flow                                              - SI lower control flow
      --si-lower-sgpr-spills                                               - SI lower SGPR spill instructions
      --si-memory-legalizer                                                - SI Memory Legalizer
      --si-mode-register                                                   - Insert required mode register values
      --si-opt-vgpr-liverange                                              - SI Optimize VGPR LiveRange
      --si-optimize-exec-masking                                           - SI optimize exec mask operations
      --si-optimize-exec-masking-pre-ra                                    - SI optimize exec mask operations pre-RA
      --si-peephole-sdwa                                                   - SI Peephole SDWA
      --si-post-ra-bundler                                                 - SI post-RA bundler
      --si-pre-allocate-wwm-regs                                           - SI Pre-allocate WWM Registers
      --si-pre-emit-peephole                                               - SI peephole optimizations
      --si-shrink-instructions                                             - SI Shrink Instructions
      --si-wqm                                                             - SI Whole Quad Mode
      --simple-loop-unswitch                                               - Simple unswitch loops
      --simplifycfg                                                        - Simplify the CFG
      --sink                                                               - Code sinking
      --sjljehprepare                                                      - Prepare SjLj exceptions
      --slotindexes                                                        - Slot index numbering
      --slsr                                                               - Straight line strength reduction
      --sparc-isel                                                         - SPARC DAG->DAG Pattern Instruction Selection
      --speculative-execution                                              - Speculatively execute instructions
      --sroa                                                               - Scalar Replacement Of Aggregates
      --stack-protector                                                    - Insert stack protectors
      --stack-safety                                                       - Stack Safety Analysis
      --stack-safety-local                                                 - Stack Safety Local Analysis
      --strip-gc-relocates                                                 - Strip gc.relocates inserted through RewriteStatepointsForGC
      --structurizecfg                                                     - Structurize the CFG
      --systemz-elim-compare                                               - SystemZ Comparison Elimination
      --systemz-isel                                                       - SystemZ DAG->DAG Pattern Instruction Selection
      --systemz-ld-cleanup                                                 - SystemZ Local Dynamic TLS Access Clean-up
      --systemz-long-branch                                                - SystemZ Long Branch
      --systemz-post-rewrite                                               - SystemZ Post Rewrite pass
      --systemz-shorten-inst                                               - SystemZ Instruction Shortening
      --systemz-tdc                                                        - SystemZ Test Data Class optimization
      --tailcallelim                                                       - Tail Call Elimination
      --targetlibinfo                                                      - Target Library Information
      --targetpassconfig                                                   - Target Pass Configuration
      --tbaa                                                               - Type-Based Alias Analysis
      --thumb2-reduce-size                                                 - Thumb2 instruction size reduce pass
      --tileconfig                                                         - Tile Register Configure
      --tilepreconfig                                                      - Tile Register Pre-configure
      --tlshoist                                                           - TLS Variable Hoist
      --tti                                                                - Target Transform Information
      --uniformity                                                         - Uniformity Analysis
      --unify-loop-exits                                                   - Fixup each natural loop to have a single exit block
      --unreachable-mbb-elimination                                        - Remove unreachable machine basic blocks
      --unreachableblockelim                                               - Remove unreachable blocks from the CFG
      --ve-isel                                                            - VE DAG->DAG Pattern Instruction Selection
      --vec-merger                                                         - R600 Vector Reg Merger
      --verify                                                             - Module Verifier
      --verify-safepoint-ir                                                - Safepoint IR Verifier
      --view-callgraph                                                     - View call graph
      --view-cfg                                                           - View CFG of function
      --view-cfg-only                                                      - View CFG of function (with no function bodies)
      --view-dom                                                           - View dominance tree of function
      --view-dom-only                                                      - View dominance tree of function (with no function bodies)
      --view-postdom                                                       - View postdominance tree of function
      --view-postdom-only                                                  - View postdominance tree of function (with no function bodies)
      --view-regions                                                       - View regions of function
      --view-regions-only                                                  - View regions of function (with no function bodies)
      --view-scops                                                         - Polly - View Scops of function
      --view-scops-only                                                    - Polly - View Scops of function (with no function bodies)
      --virtregmap                                                         - Virtual Register Map
      --wasm-add-missing-prototypes                                        - Add prototypes to prototypes-less functions
      --wasm-argument-move                                                 - Move ARGUMENT instructions for WebAssembly
      --wasm-cfg-sort                                                      - Reorders blocks in topological order
      --wasm-cfg-stackify                                                  - Insert BLOCK/LOOP/TRY markers for WebAssembly scopes
      --wasm-debug-fixup                                                   - Ensures debug_value's that have been stackified become stack relative
      --wasm-exception-info                                                - WebAssembly Exception Information
      --wasm-explicit-locals                                               - Convert registers to WebAssembly locals
      --wasm-fix-br-table-defaults                                         - Removes range checks and sets br_table default targets
      --wasm-fix-function-bitcasts                                         - Fix mismatching bitcasts for WebAssembly
      --wasm-fix-irreducible-control-flow                                  - Removes irreducible control flow
      --wasm-isel                                                          - WebAssembly Instruction Selection
      --wasm-late-eh-prepare                                               - WebAssembly Late Exception Preparation
      --wasm-lower-br_unless                                               - Lowers br_unless into inverted br_if
      --wasm-lower-em-ehsjlj                                               - WebAssembly Lower Emscripten Exceptions / Setjmp / Longjmp
      --wasm-lower-reftypes-intptr-conv                                    - WebAssembly Lower RefTypes Int-Ptr Conversions
      --wasm-mclower-prepass                                               - Collects information ahead of time for MC lowering
      --wasm-mem-intrinsic-results                                         - Optimize memory intrinsic result values for WebAssembly
      --wasm-nullify-dbg-value-lists                                       - WebAssembly Nullify DBG_VALUE_LISTs
      --wasm-optimize-live-intervals                                       - Optimize LiveIntervals for WebAssembly
      --wasm-optimize-returned                                             - Optimize calls with "returned" attributes for WebAssembly
      --wasm-peephole                                                      - WebAssembly peephole optimizations
      --wasm-reg-coloring                                                  - Minimize number of registers used
      --wasm-reg-numbering                                                 - Assigns WebAssembly register numbers for virtual registers
      --wasm-reg-stackify                                                  - Reorder instructions to use the WebAssembly value stack
      --wasm-replace-phys-regs                                             - Replace physical registers with virtual registers
      --wasm-set-p2align-operands                                          - Set the p2align operands for WebAssembly loads and stores
      --wasmehprepare                                                      - Prepare WebAssembly exceptions
      --winehprepare                                                       - Prepare Windows exceptions
      --write-bitcode                                                      - Write Bitcode
      --x86-avoid-SFB                                                      - Machine code sinking
      --x86-avoid-trailing-call                                            - X86 avoid trailing call pass
      --x86-cf-opt                                                         - X86 Call Frame Optimization
      --x86-cmov-conversion                                                - X86 cmov Conversion
      --x86-codegen                                                        - X86 FP Stackifier
      --x86-domain-reassignment                                            - X86 Domain Reassignment Pass
      --x86-evex-to-vex-compress                                           - Compressing EVEX instrs to VEX encoding when possible
      --x86-execution-domain-fix                                           - X86 Execution Domain Fix
      --x86-fixup-LEAs                                                     - X86 LEA Fixup
      --x86-fixup-bw-insts                                                 - X86 Byte/Word Instruction Fixup
      --x86-fixup-setcc                                                    - x86-fixup-setcc
      --x86-flags-copy-lowering                                            - X86 EFLAGS copy lowering
      --x86-isel                                                           - X86 DAG->DAG Instruction Selection
      --x86-lvi-load                                                       - X86 LVI load hardening
      --x86-lvi-ret                                                        - X86 LVI ret hardener
      --x86-optimize-LEAs                                                  - X86 optimize LEA pass
      --x86-partial-reduction                                              - X86 Partial Reduction
      --x86-pseudo                                                         - X86 pseudo instruction expansion pass
      --x86-return-thunks                                                  - X86 Return Thunks
      --x86-seses                                                          - X86 Speculative Execution Side Effect Suppression
      --x86-slh                                                            - X86 speculative load hardener
      --x86-winehstate                                                     - Insert stores for EH state numbers
      --x86argumentstackrebase                                             - Argument Stack Rebase
      --xcore-isel                                                         - XCore DAG->DAG Pattern Instruction Selection
  --lto-aix-system-assembler=<path>                                     - Path to a system assembler, picked up on AIX only
  --lto-embed-bitcode=<value>                                           - Embed LLVM bitcode in object files produced by LTO
    =none                                                               -   Do not embed
    =optimized                                                          -   Embed after all optimization passes
    =post-merge-pre-opt                                                 -   Embed post merge, but before optimizations
  --lto-pass-remarks-filter=<regex>                                     - Only record optimization remarks from passes whose names match the given regular expression
  --lto-pass-remarks-format=<format>                                    - The format used for serializing remarks (default: YAML)
  --lto-pass-remarks-output=<filename>                                  - Output filename for pass remarks
  --march=<string>                                                      - Architecture to generate code for (see --version)
  --matrix-default-layout=<value>                                       - Sets the default matrix layout
    =column-major                                                       -   Use column-major layout
    =row-major                                                          -   Use row-major layout
  --matrix-print-after-transpose-opt                                    - 
  --mattr=<a1,+a2,-a3,...>                                              - Target specific attributes (-mattr=help for details)
  --max-counter-promotions=<int>                                        - Max number of allowed counter promotions
  --max-counter-promotions-per-loop=<uint>                              - Max number counter promotions per loop to avoid increasing register pressure too much
  --mc-relax-all                                                        - When used with filetype=obj, relax all fixups in the emitted object file
  --mcabac                                                              - tbd
  --mcpu=<cpu-name>                                                     - Target a specific cpu type (-mcpu=help for details)
  --meabi=<value>                                                       - Set EABI type (default depends on triple):
    =default                                                            -   Triple default EABI version
    =4                                                                  -   EABI version 4
    =5                                                                  -   EABI version 5
    =gnu                                                                -   EABI GNU
  --merror-missing-parenthesis                                          - Error for missing parenthesis around predicate registers
  --merror-noncontigious-register                                       - Error for register names that aren't contigious
  --mhvx                                                                - Enable Hexagon Vector eXtensions
  --mhvx=<value>                                                        - Enable Hexagon Vector eXtensions
    =v60                                                                -   Build for HVX v60
    =v62                                                                -   Build for HVX v62
    =v65                                                                -   Build for HVX v65
    =v66                                                                -   Build for HVX v66
    =v67                                                                -   Build for HVX v67
    =v68                                                                -   Build for HVX v68
    =v69                                                                -   Build for HVX v69
    =v71                                                                -   Build for HVX v71
    =v73                                                                -   Build for HVX v73
  --mips-compact-branches=<value>                                       - MIPS Specific: Compact branch policy.
    =never                                                              -   Do not use compact branches if possible.
    =optimal                                                            -   Use compact branches where appropriate (default).
    =always                                                             -   Always use compact branches if possible.
  --mips16-constant-islands                                             - Enable mips16 constant islands.
  --mips16-hard-float                                                   - Enable mips16 hard float.
  --mir-strip-debugify-only                                             - Should mir-strip-debug only strip debug info from debugified modules by default
  --misexpect-tolerance=<uint>                                          - Prevents emiting diagnostics when profile counts are within N% of the threshold..
  --mno-compound                                                        - Disable looking for compound instructions for Hexagon
  --mno-fixup                                                           - Disable fixing up resolved relocations for Hexagon
  --mno-ldc1-sdc1                                                       - Expand double precision loads and stores to their single precision counterparts
  --mno-pairing                                                         - Disable looking for duplex instructions for Hexagon
  --module-hash                                                         - Emit module hash
  --module-summary                                                      - Emit module summary index
  --mtriple=<string>                                                    - Override target triple for module
  --mwarn-missing-parenthesis                                           - Warn for missing parenthesis around predicate registers
  --mwarn-noncontigious-register                                        - Warn for register names that arent contigious
  --mwarn-sign-mismatch                                                 - Warn for mismatching a signed and unsigned value
  --mxcoff-roptr                                                        - When set to true, const objects with relocatable address values are put into the RO data section.
  --no-deprecated-warn                                                  - Suppress all deprecated warnings
  --no-discriminators                                                   - Disable generation of discriminator information.
  --no-integrated-as                                                    - Disable integrated assembler
  --no-type-check                                                       - Suppress type errors (Wasm)
  --no-warn                                                             - Suppress all warnings
  --nozero-initialized-in-bss                                           - Don't place zero-initialized symbols into bss section
  --nvptx-sched4reg                                                     - NVPTX Specific: schedule for register pressue
  -o <filename>                                                         - Override output filename
  --pass-remarks-filter=<regex>                                         - Only record optimization remarks from passes whose names match the given regular expression
  --pass-remarks-format=<format>                                        - The format used for serializing remarks (default: YAML)
  --pass-remarks-output=<filename>                                      - Output filename for pass remarks
  --passes=<string>                                                     - A textual description of the pass pipeline. To have analysis passes available before a certain pass, add 'require<foo-analysis>'.
  --pgo-block-coverage                                                  - Use this option to enable basic block coverage instrumentation
  --pgo-temporal-instrumentation                                        - Use this option to enable temporal instrumentation
  --pgo-view-block-coverage-graph                                       - Create a dot file of CFGs with block coverage inference information
  --poison-checking-function-local                                      - Check that returns are non-poison (for testing)
  --print-passes                                                        - Print available passes that can be specified in -passes=foo and exit
  --print-pipeline-passes                                               - Print a '-passes' compatible string describing the pipeline (best-effort only).
  --r600-ir-structurize                                                 - Use StructurizeCFG IR pass
  --relax-elf-relocations                                               - Emit GOTPCRELX/REX_GOTPCRELX instead of GOTPCREL on x86-64 ELF
  --relocation-model=<value>                                            - Choose relocation model
    =static                                                             -   Non-relocatable code
    =pic                                                                -   Fully relocatable, position independent code
    =dynamic-no-pic                                                     -   Relocatable external references, non-relocatable code
    =ropi                                                               -   Code and read-only data relocatable, accessed PC-relative
    =rwpi                                                               -   Read-write data relocatable, accessed relative to static base
    =ropi-rwpi                                                          -   Combination of ropi and rwpi
  --riscv-add-build-attributes                                          - 
  --runtime-counter-relocation                                          - Enable relocating counters at runtime.
  --safepoint-ir-verifier-print-only                                    - 
  --sample-profile-check-record-coverage=<N>                            - Emit a warning if less than N% of records in the input profile are matched to the IR.
  --sample-profile-check-sample-coverage=<N>                            - Emit a warning if less than N% of samples in the input profile are matched to the IR.
  --sample-profile-max-propagate-iterations=<uint>                      - Maximum number of iterations to go through when propagating sample block/edge weights through the CFG.
  --skip-ret-exit-block                                                 - Suppress counter promotion if exit blocks contain ret.
  --speculative-counter-promotion-max-exiting=<uint>                    - The max number of exiting blocks of a loop to allow  speculative counter promotion
  --speculative-counter-promotion-to-loop                               - When the option is false, if the target block is in a loop, the promotion will be disallowed unless the promoted counter  update can be further/iteratively promoted into an acyclic  region.
  --split-machine-functions                                             - Split out cold basic blocks from machine functions based on profile information
  --stack-size-section                                                  - Emit a section containing stack size metadata
  --stack-symbol-ordering                                               - Order local stack symbols.
  --stackrealign                                                        - Force align the stack to the minimum alignment
  --strict-dwarf                                                        - use strict dwarf
  --strip-debug                                                         - Strip debugger symbol info from translation unit
  --strip-named-metadata                                                - Strip module-level named metadata
  --summary-file=<string>                                               - The summary file to use for function importing.
  --sve-tail-folding=<string>                                           - Control the use of vectorisation using tail-folding for SVE where the option is specified in the form (Initial)[+(Flag1|Flag2|...)]:
                                                                          disabled      (Initial) No loop types will vectorize using tail-folding
                                                                          default       (Initial) Uses the default tail-folding settings for the target CPU
                                                                          all           (Initial) All legal loop types will vectorize using tail-folding
                                                                          simple        (Initial) Use tail-folding for simple loops (not reductions or recurrences)
                                                                          reductions    Use tail-folding for loops containing reductions
                                                                          noreductions  Inverse of above
                                                                          recurrences   Use tail-folding for loops containing fixed order recurrences
                                                                          norecurrences Inverse of above
                                                                          reverse       Use tail-folding for loops requiring reversed predicates
                                                                          noreverse     Inverse of above
  --swift-async-fp=<value>                                              - Determine when the Swift async frame pointer should be set
    =auto                                                               -   Determine based on deployment target
    =always                                                             -   Always set the bit
    =never                                                              -   Never set the bit
  --tail-predication=<value>                                            - MVE tail-predication pass options
    =disabled                                                           -   Don't tail-predicate loops
    =enabled-no-reductions                                              -   Enable tail-predication, but not for reduction loops
    =enabled                                                            -   Enable tail-predication, including reduction loops
    =force-enabled-no-reductions                                        -   Enable tail-predication, but not for reduction loops, and force this which might be unsafe
    =force-enabled                                                      -   Enable tail-predication, including reduction loops, and force this which might be unsafe
  --tailcallopt                                                         - Turn fastcc calls into tail calls by (potentially) changing ABI.
  --thin-link-bitcode-file=<filename>                                   - A file in which to write minimized bitcode for the thin link only
  --thinlto-assume-merged                                               - Assume the input has already undergone ThinLTO function importing and the other pre-optimization pipeline changes.
  --thinlto-bc                                                          - Write output as ThinLTO-ready bitcode
  --thinlto-split-lto-unit                                              - Enable splitting of a ThinLTO LTOUnit
  --thread-model=<value>                                                - Choose threading model
    =posix                                                              -   POSIX thread model
    =single                                                             -   Single thread model
  --threads=<int>                                                       - 
  --time-trace                                                          - Record time trace
  --time-trace-file=<filename>                                          - Specify time trace file destination
  --tls-size=<uint>                                                     - Bit size of immediate TLS offsets
  --type-based-intrinsic-cost                                           - Calculate intrinsics cost based only on argument types
  --unique-basic-block-section-names                                    - Give unique names to every basic block section
  --unique-section-names                                                - Give unique names to every section
  --use-ctors                                                           - Use .ctors instead of .init_array.
  --vec-extabi                                                          - Enable the AIX Extended Altivec ABI.
  --verify-debuginfo-preserve                                           - Start the pipeline with collecting and end it with checking of debug info preservation.
  --verify-di-preserve-export=<filename>                                - Export debug info preservation failures into specified (JSON) file (should be abs path as we use append mode to insert new JSON objects)
  --verify-each                                                         - Verify after each transform
  --verify-each-debuginfo-preserve                                      - Start each pass with collecting and end it with checking of debug info preservation.
  --verify-region-info                                                  - Verify region info (time consuming)
  --vp-counters-per-site=<number>                                       - The average number of profile counters allocated per value profiling site.
  --vp-static-alloc                                                     - Do static counter allocation for value profiler
  --wasm-enable-eh                                                      - WebAssembly exception handling
  --wasm-enable-sjlj                                                    - WebAssembly setjmp/longjmp handling
  --x86-align-branch=<string>                                           - Specify types of branches to align (plus separated list of types):
                                                                          jcc      indicates conditional jumps
                                                                          fused    indicates fused conditional jumps
                                                                          jmp      indicates direct unconditional jumps
                                                                          call     indicates direct and indirect calls
                                                                          ret      indicates rets
                                                                          indirect indicates indirect unconditional jumps
  --x86-align-branch-boundary=<uint>                                    - Control how the assembler should align branches with NOP. If the boundary's size is not 0, it should be a power of 2 and no less than 32. Branches will be aligned to prevent from being across or against the boundary of specified size. The default value 0 does not align branches.
  --x86-branches-within-32B-boundaries                                  - Align selected instructions to mitigate negative performance impact of Intel's micro code update for errata skx102.  May break assumptions about labels corresponding to particular instructions, and should be used with caution.
  --x86-pad-max-prefix-size=<uint>                                      - Maximum number of prefixes to use for padding
  --xcoff-traceback-table                                               - Emit the XCOFF traceback table
  --xray-function-index                                                 - Emit xray_fn_idx section

Generic Options:

  --help                                                                - Display available options (--help-hidden for more)
  --help-list                                                           - Display list of available options (--help-list-hidden for more)
  --version                                                             - Display the version of this program

Polly Options:
Configure the polly loop optimizer

  --polly                                                               - Enable the polly optimizer (with -O1, -O2 or -O3)
  --polly-2nd-level-tiling                                              - Enable a 2nd level loop of loop tiling
  --polly-ast-print-accesses                                            - Print memory access functions
  --polly-context=<isl parameter set>                                   - Provide additional constraints on the context parameters
  --polly-dce-precise-steps=<int>                                       - The number of precise steps between two approximating iterations. (A value of -1 schedules another approximation stage before the actual dead code elimination.
  --polly-delicm-max-ops=<int>                                          - Maximum number of isl operations to invest for lifetime analysis; 0=no limit
  --polly-detect-full-functions                                         - Allow the detection of full functions
  --polly-dump-after                                                    - Dump module after Polly transformations into a file suffixed with "-after"
  --polly-dump-after-file=<string>                                      - Dump module after Polly transformations to the given file
  --polly-dump-before                                                   - Dump module before Polly transformations into a file suffixed with "-before"
  --polly-dump-before-file=<string>                                     - Dump module before Polly transformations to the given file
  --polly-enable-simplify                                               - Simplify SCoP after optimizations
  --polly-ignore-func=<string>                                          - Ignore functions that match a regex. Multiple regexes can be comma separated. Scop detection will ignore all functions that match ANY of the regexes provided.
  --polly-isl-arg=<argument>                                            - Option passed to ISL
  --polly-matmul-opt                                                    - Perform optimizations of matrix multiplications based on pattern matching
  --polly-on-isl-error-abort                                            - Abort if an isl error is encountered
  --polly-only-func=<string>                                            - Only run on functions that match a regex. Multiple regexes can be comma separated. Scop detection will run on all functions that match ANY of the regexes provided.
  --polly-only-region=<identifier>                                      - Only run on certain regions (The provided identifier must appear in the name of the region's entry block
  --polly-only-scop-detection                                           - Only run scop detection, but no other optimizations
  --polly-optimized-scops                                               - Polly - Dump polyhedral description of Scops optimized with the isl scheduling optimizer and the set of post-scheduling transformations is applied on the schedule tree
  --polly-parallel                                                      - Generate thread parallel code (isl codegen only)
  --polly-parallel-force                                                - Force generation of thread parallel code ignoring any cost model
  --polly-pattern-matching-based-opts                                   - Perform optimizations based on pattern matching
  --polly-postopts                                                      - Apply post-rescheduling optimizations such as tiling (requires -polly-reschedule)
  --polly-pragma-based-opts                                             - Apply user-directed transformation from metadata
  --polly-pragma-ignore-depcheck                                        - Skip the dependency check for pragma-based transformations
  --polly-process-unprofitable                                          - Process scops that are unlikely to benefit from Polly optimizations.
  --polly-register-tiling                                               - Enable register tiling
  --polly-report                                                        - Print information about the activities of Polly
  --polly-reschedule                                                    - Optimize SCoPs using ISL
  --polly-show                                                          - Highlight the code regions that will be optimized in a (CFG BBs and LLVM-IR instructions)
  --polly-show-only                                                     - Highlight the code regions that will be optimized in a (CFG only BBs)
  --polly-stmt-granularity=<value>                                      - Algorithm to use for splitting basic blocks into multiple statements
    =bb                                                                 -   One statement per basic block
    =scalar-indep                                                       -   Scalar independence heuristic
    =store                                                              -   Store-level granularity
  --polly-tc-opt                                                        - Perform optimizations of tensor contractions based on pattern matching
  --polly-tiling                                                        - Enable loop tiling
  --polly-vectorizer=<value>                                            - Select the vectorization strategy
    =none                                                               -   No Vectorization
    =stripmine                                                          -   Strip-mine outer loops for the loop-vectorizer to trigger