cmake_minimum_required(VERSION 3.21)
project(basic_gtests)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(app src/main.cpp)

enable_testing()
add_subdirectory(test)