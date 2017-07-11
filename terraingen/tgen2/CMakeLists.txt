cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)
project(tgen)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(EXTERNAL_DIR ${PROJECT_SOURCE_DIR}/external)

set(SRC
    ${SRC_DIR}/convert.cpp
    ${SRC_DIR}/mem.cpp
    ${SRC_DIR}/sqlite3.c
    ${SRC_DIR}/tgen.cpp
    ${EXTERNAL_DIR}/undname/undname.c
    ${EXTERNAL_DIR}/pe-parse/parser-library/buffer.cpp
    ${EXTERNAL_DIR}/pe-parse/parser-library/parse.cpp
    ${SRC}
)

if (NOT MSVC)
    set(LIBS "pthread dl")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -std=c++11")
endif()

add_executable(tgen ${SRC})
target_include_directories(tgen PUBLIC
                           ${SRC_DIR}
                           ${EXTERNAL_DIR}
                           )
target_compile_definitions(tgen PUBLIC)


target_link_libraries(tgen LINK_PUBLIC ${LIBS})