cmake_minimum_required(VERSION 3.10)

project(tfSim C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES 
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/lib/*.cpp"
    "${PROJECT_SOURCE_DIR}/lib/*.c"
)

add_executable(${PROJECT_NAME} ${SOURCES})

message(STATUS "All output will be placed in: ${CMAKE_BINARY_DIR}/output")