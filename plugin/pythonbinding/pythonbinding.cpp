#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <cstdio>
#include <string>

extern int JustAFunction(std::vector<std::string> argv);

PYBIND11_MODULE(pybindopt, m)
{
  m.def("helloworld", []() -> void {
    printf("helloworld");
  });
  m.def("opt", [](std::vector<std::string> argv) -> void {
    JustAFunction(argv);
  });
}
