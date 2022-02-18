cmake_minimum_required(VERSION 3.21)
project(spacemed)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(spacemed main.cpp)
target_link_libraries(spacemed ${SDL2_LIBRARIES})
