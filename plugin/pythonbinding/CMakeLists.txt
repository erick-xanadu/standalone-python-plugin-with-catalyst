add_library(pybindopt MODULE pythonbinding.cpp)
set_target_properties(pybindopt PROPERTIES PREFIX "")
target_link_libraries(pybindopt PRIVATE pybind11::module StandaloneLib)
