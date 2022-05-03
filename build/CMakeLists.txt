cmake_minimum_required(VERSION 3.10)
project(hexwatershed CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_COMPILER g++-10)
set(CMAKE_CPP_COMPILER g++-10)

Include_directories(../src)

add_executable(hexwatershed ${hexwatershed_srcs})

set(default_build_type Release)
if(EXISTS "${CMAKE_SOURCE_DIR}/../.git")
    set(default_build_type Debug)
endif()

message("build type = ${default_build_type}")

target_compile_options(hexwatershed PUBLIC -std=c++11)

set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
install(TARGETS hexwatershed RUNTIME DESTINATION ${INSTALL_DIR})

find_package(OpenMP)

if (OPENMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(RAPIDJSON_NCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../external/rapidjson")

include_directories(${RAPIDJSON_NCLUDE_DIR})

target_link_libraries(hexwatershed  -std=c++11)
