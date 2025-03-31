# Notes from lecture 1: basic introduction to C++ development

- Check WeBeep and the course repo (forked from the original) for a heck of a lot of contents.

## Compilers

- Use gcc/g++ or clang/clang++.

## Some whys of C++

- Backward compatibility is almost always granted by new standards.

- Strongly typed language: safer code, less ambiguous semantic.

- Interfaces with python using pybind11 and cython. Use Python for prototyping, interfaces and visualization (especially when glueing different programming languages together); C++ for performance and compute-intensive tasks.

## Some useful libraries

Complete list here: <https://en.cppreference.com/w/cpp/links/libs>

- Eigen
- SuiteSparse
- Stat++ and Stan Math
- Boost libraries (it has pretty much everything!)
- mlpack, OpenNN for ML and NNs

## A note on _*Modules*_

Latest C++ standards introduce _modules_, a different way to organize C++ code, similar to the python's way. It replaces the typical header-source file organization with a single file. As of 2025, not widely used.

## Headers and declarations

A header file must contain all declarations, including function prototypes, class definitions, and constants that each translation unit where `#ìnclude` is used, needs to know about.

- Constant expressions (variables) must go in the header file.
- Function prototypes similarly. Note that this can use `auto` for the types, which will be decided at compile time according to the usage.
- Templates definitions can go in the header file.
- What a header file must not contain (unless `inline`):
  - Function definitions
  - Methods definitions
  - Variable definitions
  - Definition of static members
  - Definitions of variables
  - `using namespace` directive (very bad practice, it's like import * in python!)

- A translation unit is a source file and all the headers it includes. The compiler compiles each translation unit separately, and then links them together.
  - In practice, each TU corresponds to an object file (`file.o` extension) produced by the compiler from the assembly code.
  - Each is treated separately until linking occurs.
  - Note that in most cases code will use dynamics (shared) libraries. Therefore, the actual program build "completes" at runtime, when the dynamic linker loads the shared libraries into memory.
  - Overview of the compilation process and main flags:
![img[alt$=">"] {
  float: right;
}](building_process.png)

## Some development tips

- **NOTE**: A pragma is a preprocessor directive and is compiler specific. It is NOT part of the C++ standard.
- Always use `-Wall` to enable all warnings. Warning are often errors.
- To see what the preprocessor produces use the flag `-E` redirecting the output to a file. This is useful for debugging purposes.
- MACROs can be defined either as `#define` or from CLI using `-DMACRO_NAME`. The latter overrides any definition in the code.
- Special macros are defined by the compiler. For example, `__cplusplus` is defined to the version of the C++ standard used to compile the code.
  - Another example is `NDEBUG` flag that informs the compilation process to deactivate debug info and statements (e.g. asserts). Normally set to 1 if not in debug build. The default is 0.
- Add header guards (manually or with `pragma once`). This is because a header file _MUST_ be included _ONLY ONCE_.
