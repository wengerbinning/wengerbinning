###############################################################################
# <https://blog.csdn.net/afei__/article/details/81201039>
###############################################################################

cmake_minimum_required(VERSION 3.16.3)

###############################################################################
#+++++++++++++++++++++++ Project General +++++++++++++++++++++++++++++++++++++#
# Set project name and version.
###############################################################################

project(jianghu VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})

set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


###############################################################################
#====================== Compile Tool =========================================#

# Target platfrom  
# list(APPEND TARGET_PLATFROMS x64_64 aarch64)

# list(APPEND TOOLCHAINS ${COMMON_LANGUAGE_RUNTIME})

# Default target platfrom is local platfrom.
# exec_program(uname ${HOME} ARGS -m OUTPUT_VARIABLE DEFAULT_TARGET_PLATFROM)

# set(CMAKE_SYSTEM_NAME Linux)

# set(CMAKE_SYSTEM_PROCESSOR aarch64)

# set(TOOLCHAIN "/home/wbzheng/toolchain/aarch64_cortex-a53_gcc_v8.4.0")

# set(CROSS "aarch64-openwrt-linux-musl-")

# set(CMAKE_C_COMPILER "${TOOLCHAIN}/bin/${CROSS}gcc")

# set(CMAKE_CXX_COMPILER "${TOOLCHAIN}/bin/${CROSS}g++")

# set(CMAKE_FIND_ROOT_PATH "${TOOLCHAIN}")

# set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

# set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

#================== Project Framework ========================================#

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib)

# set(CMAKE_STAGING_PREFIX ${PROJECT_SOURCE_DIR}/bin)

# Set executable file output path.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# Set library file output path.
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


###############################################################################
#=============================== Project Build ===============================#

# file(GLOB SRC "src/*.c")

#+++++++++++++++++++ Library

#------------------- Static Library

#------------------- Dynamic Library

#++++++++++++++++++++++++ exectable ++++++++++++++++++++++++++++++++++++++++++#

# add_executable(helloworld test/helloworld.c)

# add_executable(notice-sg "test/uds-gwn7062.c")

# add_executable(testbytes "test/data-type/testbyte.c")

# add_executable(teststring test/data-type/teststring.c test/data-type/byte.c test/data-type/char.c)

# add_executable(teststring demo/type/string-jsg.c demo/type/char-jsg.c demo/type/byte-jsg.c)

# target_link_libraries(teststring string)

###############################################################################
#============================== Sub Project ========================#
# include subdirectory cmakelists.txt.
# add_subdirectory(demo/socket/uds)

add_executable(test202107091052 test/test202107091052.c)