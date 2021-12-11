cmake_minimum_required(VERSION 3.16.3)

project(CPP VERSION 0.0.0.1)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")

# Set executable file output path.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# Set library file output path.
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

####################################################################################################
add_executable(helloworld helloworld.cpp)
