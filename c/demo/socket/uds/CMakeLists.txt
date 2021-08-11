cmake_minimum_required(VERSION 3.16.3)

project("Unix domain socket demo" VERSION 0.0.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_executable(uds-server "uds-server.c")
add_executable(uds-client "uds-client.c")

message("${PROJECT_SOURCE_DIR}")