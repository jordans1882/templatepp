# Adapted from Dionysus bindings
include_directories(
    ${DIONYSUS_INCLUDE_DIR}/bindings/python/pybind11/include
)

if(CMAKE_LIBRARY_OUTPUT_DIRECTORY)        # to work with pip
  set(MODULE_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
else()
  set(MODULE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif()

file(MAKE_DIRECTORY "${MODULE_OUTPUT_DIRECTORY}/linalg")
file(GLOB DIONYSUS_PYTHON "${CMAKE_CURRENT_SOURCE_DIR}/linalg/*.py")
add_custom_target(linalg ALL ${CMAKE_COMMAND} -E
    copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/linalg
    ${MODULE_OUTPUT_DIRECTORY}/linalg DEPENDS ${RECONSTRUCTION_PYTHON})

pybind11_add_module(
    _linalg
    linalg.cpp
    linalg_runner.cpp
)
set_target_properties(
    _linalg PROPERTIES OUTPUT_NAME linalg/_linalg
)
