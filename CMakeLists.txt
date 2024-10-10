cmake_minimum_required(VERSION 3.10)
project(learn)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(protobuf_MODULE_COMPATIBLE TRUE)

find_package(Protobuf REQUIRED)

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

add_executable(learn-socket-send ${CMAKE_CURRENT_SOURCE_DIR}/src/socket/sender.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(learn-socket-send PRIVATE ${PROTOBUF_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

add_executable(learn-socket-receive ${CMAKE_CURRENT_SOURCE_DIR}/src/socket/receiver.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(learn-socket-receive PRIVATE ${PROTOBUF_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

add_executable(learn-crtp ${CMAKE_CURRENT_SOURCE_DIR}/src/crtp.cpp)

add_executable(template_type_deduction ${CMAKE_CURRENT_SOURCE_DIR}/src/effective-cpp/item01_template_type_deduction.cpp)
add_executable(auto_type_deduction ${CMAKE_CURRENT_SOURCE_DIR}/src/effective-cpp/item02_auto_type_deduction.cpp)
add_executable(decltype_type_deduction ${CMAKE_CURRENT_SOURCE_DIR}/src/effective-cpp/item03_decltype_type_deduction.cpp)
add_executable(learn_view_type_deduction ${CMAKE_CURRENT_SOURCE_DIR}/src/effective-cpp/item04_learn_view_deduction_types.cpp)

add_executable(log_marco ${CMAKE_CURRENT_SOURCE_DIR}/src/log-marco/a.cpp
                         ${CMAKE_CURRENT_SOURCE_DIR}/src/log-marco/b.cpp
                         ${CMAKE_CURRENT_SOURCE_DIR}/src/log-marco/main.cpp
)
target_link_libraries(log_marco PRIVATE ${CMAKE_THREAD_LIBS_INIT})

add_executable(condition ${CMAKE_CURRENT_SOURCE_DIR}/src/condition/condition.cpp)
target_link_libraries(condition PRIVATE ${CMAKE_THREAD_LIBS_INIT})

add_executable(socket-sender ${CMAKE_CURRENT_SOURCE_DIR}/src/socket_multi/sender.cpp)

add_executable(socket-receiver ${CMAKE_CURRENT_SOURCE_DIR}/src/socket_multi/reciever.cpp)

# install(TARGETS 
#     learn-callonce
#     learn-proto 
#     DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/install)