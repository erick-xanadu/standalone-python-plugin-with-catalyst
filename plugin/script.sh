#!/usr/bin/env bash

mkdir -p build && pushd build
cmake -G Ninja .. -DMLIR_DIR=/home/ubuntu/code/catalyst/mlir/llvm-project/build/lib/cmake/mlir -DLLVM_EXTERNAL_LIT=/home/ubuntu/code/catalyst/mlir/llvm-project/build/bin/llvm-lit
cmake --build . --target StandaloneLib pybindopt StandalonePlugin
popd
cp ./build/pythonbinding/pybindopt.so .
patchelf --set-rpath '$ORIGIN/../lib:/home/ubuntu/code/catalyst/mlir/llvm-project/build/./lib:$ORIGIN/../..' ./build/lib/StandalonePlugin.so
patchelf --replace-needed pythonbinding/pybindopt.so pybindopt.so ./build/lib/StandalonePlugin.so 
