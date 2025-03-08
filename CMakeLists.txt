cmake_minimum_required(VERSION 3.21)

project(pycrypto)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(cmake/ModuleImport.cmake)
include(cmake/ModuleCompileOptions.cmake)
include(cmake/PythonModuleImport.cmake)

ModuleSetCompileOptions()

set(DMCONFIG_VERSION_MAJOR "1")
set(DMCONFIG_VERSION_MINOR "0")
set(DMCONFIG_VERSION_PATCH "1")
set(DMCONFIG_VERSION "${DMCONFIG_VERSION_MAJOR}.${DMCONFIG_VERSION_MINOR}.${DMCONFIG_VERSION_PATCH}")

message(STATUS "VERSION: ${DMCONFIG_VERSION}")

# python bitset.h dmflex.common bitset.h
set(PYTHON_VERSION 3.10)
# On Windows, find_package is searched in sequence according to the PATH path. You can prefix 3.10
# pybind11 2.9.1 requires Python 3.10
find_package(Python ${PYTHON_VERSION} EXACT REQUIRED COMPONENTS Interpreter Development)

if (NOT Python_FOUND)
    message(FATAL_ERROR "Python ${PYTHON_VERSION} not found! Please make sure Python is installed and available.")
else()
    message(STATUS "Python ${PYTHON_VERSION} found!")
    message(STATUS "Python executable: ${Python_EXECUTABLE}")
    message(STATUS "Python include directories: ${PYTHON_INCLUDE_DIRS}")
    message(STATUS "Python library directories: ${Python_LIBRARY_DIRS}")
    message(STATUS "Python version set to: ${PYBIND11_PYTHON_VERSION}")

    include_directories(${PYTHON_INCLUDE_DIRS})
    link_directories(${Python_LIBRARY_DIRS})
    set(PYBIND11_PYTHON_VERSION ${PYTHON_VERSION})
    mark_as_advanced(PYBIND11_PYTHON_VERSION)
    # static lib
    #add_compile_definitions(Py_NO_ENABLE_SHARED Py_STATIC)

endif ()

ModuleInclude("dmformat" "thirdparty/dmformat")

ModuleImport("dmpybind11" "thirdparty/dmpybind11")
ModuleImport("dmtest" "thirdparty/dmtest")

PyModuleImport("module" "pybind11::module;${PYTHON_LIBRARIES}")

ExeImport("test" "dmtest;pycrypto;pybind11::embed;${PYTHON_LIBRARIES}")

add_custom_command(
    TARGET pycrypto
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/module/pycrypto/pycrypto.py
    $<TARGET_FILE_DIR:pycrypto>
)
