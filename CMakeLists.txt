cmake_minimum_required(VERSION 3.10)
project(hexwatershed CXX)

find_package(GDAL REQUIRED)
find_package(OpenMP)

message("GDAL_LIBRARY = ${GDAL_LIBRARY}")

# Add the cmake folder so the FindSphinx module is found
message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
message("CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")

set(hexwatershed_srcs
    src/conversion.cpp
    src/conversion.h
    src/data.cpp
    src/data.h
    src/depression.cpp
    src/depression.h
    src/domain.cpp
    src/domain.h
    src/global.cpp
    src/global.h
    src/hexagon.cpp
    src/hexagon.h
    src/main.cpp
    src/segment.cpp
    src/segment.h
    src/system.cpp
    src/system.h
    # src/vertex.cpp
    # src/vertex.h
    src/watershed.cpp
    src/watershed.h
)

add_executable(hexwatershed ${hexwatershed_srcs})
target_compile_features(hexwatershed PUBLIC cxx_std_11)

list(APPEND hexwatershed_libraries ${GDAL_LIBRARY})
if(OpenMP_FOUND)
    list(APPEND hexwatershed_libraries OpenMP::OpenMP_CXX)
endif()
target_link_libraries(hexwatershed PUBLIC ${hexwatershed_libraries})
target_include_directories(hexwatershed PUBLIC ${GDAL_INCLUDE_DIR})

set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
install(TARGETS hexwatershed RUNTIME DESTINATION ${INSTALL_DIR})



add_subdirectory("docs")
