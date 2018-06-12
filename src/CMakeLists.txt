cmake_minimum_required(VERSION 2.8)

file(GLOB HEXAGONHYDRO_SRCS *.cpp)
project(HEXAGONHYDRO CXX)
add_executable(HEXAGONHYDRO ${HEXAGONHYDRO_SRCS})
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)
target_compile_options(HEXAGONHYDRO PUBLIC -std=c++11)

target_link_libraries(HEXAGONHYDRO ${GDAL_LIBRARY} -std=c++11)

set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
install(TARGETS HEXAGONHYDRO RUNTIME DESTINATION ${INSTALL_DIR})

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

find_package( GDAL )
include_directories( ${GDAL_INCLUDE_DIRS} )




