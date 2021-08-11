cmake_minimum_required(VERSION 3.0.0)

project("Demo memory" VERSION 0.0.0)

set(CMAKE_PORJECT_NAME ${PROJECT_NAME})
set(CMAKE_PROJECT_VERSION ${PROJECT_VERSION})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_executable(demo-memory-allocation demo-memory-allocation.c)