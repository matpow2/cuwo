cmake_minimum_required(VERSION 2.8.8)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# project

project(Terraingen)

set(ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(LIB_DIR "${ROOT_DIR}/../lib")
set(SRC_DIR "${ROOT_DIR}/src")
set(GEN_DIR "${ROOT_DIR}/gensrc")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})

# sources

include(gensrc/Routines.cmake)

set(SRCS
    ${SRC_DIR}/run.cpp
    ${SRC_DIR}/memory.cpp
    ${SRC_DIR}/cpu.cpp
    ${SRC_DIR}/sqlite3.c
    ${GEN_DIR}/stubs.cpp
    ${GEN_SRCS}
)

# dependencies

if(MSVC)
    # silence some stupid warnings
    add_definitions("/wd4102")
    set_source_files_properties(${GEN_BIG_SRCS} PROPERTIES COMPILE_FLAGS -Od)
else()
    # GCC-like
    set_source_files_properties(${GEN_BIG_SRCS} PROPERTIES COMPILE_FLAGS
                                "-O0 -g0")
endif()

set(CMAKE_LIBRARY_PATH "${ROOT_DIR}/lib" ${CMAKE_LIBRARY_PATH})
set(CMAKE_INCLUDE_PATH ${SRC_DIR} "${ROOT_DIR}/include"
    ${CMAKE_INCLUDE_PATH})

if(MSVC)
    set(CMAKE_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include/win32"
        ${CMAKE_INCLUDE_PATH})
    add_definitions(/arch:SSE2)
    add_definitions(/MP)
endif()

if(UNIX)
    find_package(Threads REQUIRED)
    set(GEN_LIBS ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
endif()

# build

include_directories(
    ${CMAKE_INCLUDE_PATH}
)

# build
add_library(tgen ${SRCS})
target_link_libraries(tgen ${GEN_LIBS})

add_executable(tgen_example ${SRC_DIR}/example.cpp)
target_link_libraries(tgen_example tgen)
