cmake_minimum_required(VERSION 3.21)
project(spacemed)

set(CMAKE_CXX_STANDARD 20)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(PkgConfig REQUIRED)
# Find SDL2, SDL2_image and SDL2_gfx libraries
pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_image)

add_executable(spacemed main.cpp src/App.cpp src/App.hpp src/TextureManager.cpp src/TextureManager.hpp)
target_link_libraries(spacemed ${SDL2_LINK_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${SDL2_CFLAGS_OTHER})

# This takes care of copying the images so that I don't have to do that for each install target
FILE(COPY ./gfx DESTINATION ${CMAKE_BINARY_DIR})
