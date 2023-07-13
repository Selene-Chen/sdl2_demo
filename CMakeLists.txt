cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

project(sdl2_demo LANGUAGES CXX)

add_executable(main src/main.cpp)

include(./cmake/CopyFiles.cmake)
include(./cmake/FindSDL2.cmake)
target_link_libraries(main SDL2)

CopyDLL(main)
