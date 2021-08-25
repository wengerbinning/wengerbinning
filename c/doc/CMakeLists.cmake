# CMakeLists.cmake

# CMakeList.txt 是cmake的默认配置文件

# 基础设置项：

cmake_minimum_required(VERSION 3.4.1)


# 工程设置项：

project(<project name>)

# 搜索所有源文件
aux_source_directory()


## 构建执行项：

# 构建二进制目标文件。
add_executable(<target name> <source list>)

# 构建静态库
add_library(common STATIC <source list>)

# 构建动态库
add_library(<target name>common SHARED <source list>)
