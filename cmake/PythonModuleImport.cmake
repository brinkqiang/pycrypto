
macro(SUBDIRLIST result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
endmacro()

macro(PyModuleImport ModulePath DependsLib)
    MESSAGE(STATUS "PyModuleImport ${ModulePath} ${DependsLib}")

    IF (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath})
        SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath})
        FOREACH(subdir ${SUBDIRS})
            MESSAGE(STATUS "INCLUDE -> ${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath}/${subdir}")
            INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath}/${subdir})
            FILE(GLOB_RECURSE BIN_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath}/${subdir}/*.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath}/${subdir}/*.cc
            ${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath}/${subdir}/*.c
            ${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath}/${subdir}/*.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath}/${subdir}/*.h)

            LIST(FILTER BIN_SOURCES EXCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/${ModulePath}/${subdir}/tpl/*")

            MESSAGE(STATUS "BIN_SOURCES ${LIB_SOURCES}")

            SET(LIB_SUFFIX "${CMAKE_SHARED_LIBRARY_SUFFIX}")
            SET(CMAKE_SHARED_LIBRARY_SUFFIX ".pyd")

            MESSAGE(STATUS "change suffix : ${LIB_SUFFIX} --> ${CMAKE_SHARED_LIBRARY_SUFFIX}")

            ADD_LIBRARY(${subdir} SHARED ${BIN_SOURCES})
            TARGET_LINK_LIBRARIES(${subdir} ${DependsLib})

            MESSAGE(STATUS "change suffix : ${CMAKE_SHARED_LIBRARY_SUFFIX} --> ${LIB_SUFFIX}")
            SET(CMAKE_SHARED_LIBRARY_SUFFIX "${LIB_SUFFIX}")

            MESSAGE(STATUS "$<TARGET_FILE_DIR:${subdir}>")
            MESSAGE(STATUS $<TARGET_FILE:${subdir}>)
            ADD_CUSTOM_COMMAND(
            TARGET ${subdir} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:${subdir}>
            $<TARGET_FILE_DIR:${subdir}>/${subdir}.pyd
            )

        ENDFOREACH()
    ENDIF()

endmacro(PyModuleImport)
