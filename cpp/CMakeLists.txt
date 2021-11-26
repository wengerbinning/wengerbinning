###############################################################################
# CMakeLists.txt is a default configure file for cmake.
#
# @links:
# <https://blog.csdn.net/afei__/article/details/81201039>
###############################################################################
# Set some dependency conditions.
#=============================================================================#
# 
cmake_minimum_required(VERSION 3.16.3)

###############################################################################
# Set project name and version.
###############################################################################

project(C VERSION 0.0.0.1)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})

set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


###############################################################################
#================== Project Framework ========================================#

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib)

# set(CMAKE_STAGING_PREFIX ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")
# Set executable file output path.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# Set library file output path.
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


###############################################################################
#=============================== Project Build ===============================#
#============================== Sub Project ==================================#

add_subdirectory(pkgs/json-c)

add_subdirectory(pkgs/libubox)

add_dependencies(json_script-example )
#file(REMOVE_RECURSE pkgs/json-c/cmake-build-debug/json.h include/json.h)
# add libubox module.


#add_executable(test202107091052 test/test20210709105200.c)