cmake_minimum_required(VERSION 3.10)
project(learn)

set(CMAKE_CXX_STANDARD 17) # 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(learn-callonce ${CMAKE_CURRENT_SOURCE_DIR}/src/call_once.cpp)

# 链接 pthread 库
find_package(Threads REQUIRED)
target_link_libraries(learn-callonce ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS learn-callonce DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/install)