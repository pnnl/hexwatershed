cmake_minimum_required(VERSION 3.10)
project(hexwatershed CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

Include_directories(../src)

file(GLOB hexwatershed_srcs 
        ../src/compset/compset_depression.cpp
        ../src/compset/compset_direction.cpp
        ../src/compset/compset_initialize.cpp
        ../src/compset/compset_run.cpp
        ../src/compset/compset_save.cpp
        ../src/compset/compset_stream.cpp
        ../src/compset/compset.cpp
        ../src/compset/compset.h
        ../src/domain/domain_read.cpp
        ../src/domain/domain.cpp
        ../src/domain/domain.h
        ../src/json/cell.cpp
        ../src/json/cell.h
        ../src/json/mesh.cpp
        ../src/json/mesh.h        
        ../src/json/basin.cpp
        ../src/json/basin.h
        ../src/json/multibasin.cpp
        ../src/json/multibasin.h   
        ../src/json/JSONBase.cpp
        ../src/json/JSONBase.h     
        ../src/conversion.cpp
        ../src/conversion.h
        ../src/data.cpp
        ../src/data.h         
        ../src/edge.cpp
        ../src/edge.h   
        ../src/flowline.cpp
        ../src/flowline.h   
        ../src/geology.cpp
        ../src/geology.h
        ../src/global.cpp
        ../src/global.h
        ../src/hexagon.cpp
        ../src/hexagon.h
        ../src/main.cpp
        ../src/parameter.cpp
        ../src/parameter.h
        ../src/segment.cpp        
        ../src/segment.h
        ../src/subbasin.cpp
        ../src/subbasin.h
        ../src/system.cpp        
        ../src/system.h
        ../src/json/vertex.cpp        
        ../src/json/vertex.h
        ../src/watershed.cpp
        ../src/watershed.h
        ../src/domain.cpp
        ../src/domain.h
        )

add_executable(hexwatershed ${hexwatershed_srcs})

set(default_build_type Debug)
if(EXISTS "${CMAKE_SOURCE_DIR}/../.git")
    set(default_build_type Debug)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
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

set(RAPIDJSON_NCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}external/rapidjson)

include_directories(${RAPIDJSON_NCLUDE_DIR})

target_link_libraries(hexwatershed  -std=c++11)
