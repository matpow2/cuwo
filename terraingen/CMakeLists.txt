cmake_minimum_required(VERSION 2.8.8)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# project

project(Terraingen)

set(ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(SRC_DIR "${ROOT_DIR}/src")
set(GEN_DIR "${ROOT_DIR}/gensrc")

# sources

include(gensrc/Routines.cmake)

set(SRCS
    ${SRC_DIR}/run.cpp
    ${SRC_DIR}/sqlite3.c
    ${GEN_DIR}/stubs.cpp
    ${GEN_SRCS}
)

set(TEST_SRCS
    ${SRC_DIR}/test.cpp
)

# dependencies

find_package(Boost REQUIRED) 
include_directories(${Boost_INCLUDE_DIR})

if(MSVC)
    # silence some stupid warnings
    add_definitions("/wd4102")
endif()

set(CMAKE_LIBRARY_PATH "${ROOT_DIR}/lib" ${CMAKE_LIBRARY_PATH})
set(CMAKE_INCLUDE_PATH ${SRC_DIR} "${ROOT_DIR}/include"
    ${CMAKE_INCLUDE_PATH})

if(MSVC)
    set(CMAKE_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include/win32"
        ${CMAKE_INCLUDE_PATH})
    add_definitions(/arch:SSE2)
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
add_executable(gen ${SRCS})
target_link_libraries(gen ${GEN_LIBS})

# if (CMAKE_COMPILER_IS_GNUCC OR MINGW)
#     # build test
#     add_executable(testx86 ${TEST_SRCS})
#     target_link_libraries(testx86 ${GEN_LIBS})
# endif()