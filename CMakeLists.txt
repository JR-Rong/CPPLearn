cmake_minimum_required(VERSION 3.10)
project(learn)

set(CMAKE_CXX_STANDARD 17) # 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(protobuf_MODULE_COMPATIBLE TRUE)

find_package(Protobuf REQUIRED CONFIG)

include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
# 添加可执行文件
add_executable(learn-callonce ${CMAKE_CURRENT_SOURCE_DIR}/src/call_once.cpp)

# 链接 pthread 库
find_package(Threads REQUIRED)
target_link_libraries(learn-callonce PRIVATE ${CMAKE_THREAD_LIBS_INIT})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS proto/pro.proto)

add_executable(learn-proto ${CMAKE_CURRENT_SOURCE_DIR}/src/proto_learn.cpp 
    ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(learn-proto PRIVATE ${PROTOBUF_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS 
    learn-callonce
    learn-proto 
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/install)