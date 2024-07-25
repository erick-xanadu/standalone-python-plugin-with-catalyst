//===- standalone-opt.cpp ---------------------------------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"


int JustAFunction(std::vector<std::string> argv) {
  
  std::vector<char*> cstrings;
  cstrings.reserve(argv.size());

  for(size_t i = 0; i < argv.size(); ++i)
      cstrings.push_back(const_cast<char*>(argv[i].c_str()));

  mlir::registerAllPasses();
  // TODO: Register standalone passes here.

  mlir::DialectRegistry registry;
  registry.insert<mlir::arith::ArithDialect, mlir::func::FuncDialect>();
  // Add the following to include *all* MLIR Core dialects, or selectively
  // include what you need like above. You only need to register dialects that
  // will be *parsed* by the tool, not the one generated
  // registerAllDialects(registry);

  return mlir::asMainReturnCode(
      mlir::MlirOptMain(static_cast<int>(cstrings.size()), static_cast<char**>(&cstrings[0]), "Standalone optimizer driver\n", registry));
}
