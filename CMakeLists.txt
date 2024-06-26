cmake_minimum_required(VERSION 3.8)

PROJECT(pycrypto)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
INCLUDE(cmake/PythonModuleImport.cmake)

ModuleSetCompileOptions()

SET(DMCONFIG_VERSION_MAJOR "1")
SET(DMCONFIG_VERSION_MINOR "0")
SET(DMCONFIG_VERSION_PATCH "1")
SET(DMCONFIG_VERSION "${DMCONFIG_VERSION_MAJOR}.${DMCONFIG_VERSION_MINOR}.${DMCONFIG_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMCONFIG_VERSION}")

SET(PYTHON_VERSION 3.10)

find_package(PythonInterp ${PYTHON_VERSION} REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION} REQUIRED)
find_package(Python ${PYTHON_VERSION} REQUIRED OPTIONAL_COMPONENTS NumPy)

if (PYTHONLIBS_FOUND)
    include_directories(${PYTHON_INCLUDE_DIRS})
    LINK_DIRECTORIES(${PYTHON_INCLUDE_DIRS}/../libs)
endif ()
ModuleInclude("dmformat" "thirdparty/dmformat")

ModuleImport("dmpybind11" "thirdparty/dmpybind11")
ModuleImport("dmtest" "thirdparty/dmtest")

PyModuleImport("module" "pybind11::module;${PYTHON_LIBRARIES}")

ExeImport("test" "dmtest;pycrypto;pybind11::module")

ADD_CUSTOM_COMMAND(
    TARGET pycrypto
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/module/pycrypto/pycrypto.py
    $<TARGET_FILE_DIR:pycrypto>
)
