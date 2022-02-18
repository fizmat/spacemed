cmake_minimum_required(VERSION 3.21)
project(spacemed)

set(CMAKE_CXX_STANDARD 20)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Find SDL2, SDL2_image and SDL2_gfx libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(spacemed main.cpp src/App.cpp src/App.hpp)
target_link_libraries(spacemed SDL2::Main SDL2::Image)
