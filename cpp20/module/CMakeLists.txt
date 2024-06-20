cmake_minimum_required(VERSION 3.20)
project(cpp20-modules)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts -xc++-system-header iostream string")


add_executable(${PROJECT_NAME} butter.cpp jams.cpp spreadables.cpp main.cpp)
set_source_files_properties(butter.cpp jams.cpp spreadables.cpp PROPERTIES LANGUAGE CXX)
target_compile_options(${PROJECT_NAME} PRIVATE -fmodules)