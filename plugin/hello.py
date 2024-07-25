import pybindopt
pybindopt.opt(["opt", "--load-dialect-plugin=/home/ubuntu/code/standalone-python-plugin-with-catalyst/plugin/build/lib/StandalonePlugin.so", "--load-pass-plugin=/home/ubuntu/code/standalone-python-plugin-with-catalyst/plugin/build/lib/StandalonePlugin.so", "--pass-pipeline=builtin.module(standalone-switch-bar-foo)", "../../catalyst/mlir/test.mlir"])
