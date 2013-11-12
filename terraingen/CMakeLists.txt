cmake_minimum_required(VERSION 2.8.8)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# project

project(Terraingen)

set(ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(SRC_DIR "${ROOT_DIR}/src")
set(GEN_DIR "${ROOT_DIR}/gensrc")

# sources

set(SRCS
    ${SRC_DIR}/run.cpp
    ${SRC_DIR}/sqlite3.c
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

if(WIN32)
    set(CMAKE_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include/win32"
        ${CMAKE_INCLUDE_PATH})
endif()

# build

include_directories(
    ${CMAKE_INCLUDE_PATH}
)

# editor build
add_executable(gen ${SRCS})
target_link_libraries(gen ${GEN_LIBS})
