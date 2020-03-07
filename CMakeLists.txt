cmake_minimum_required(VERSION 3.15)
project(SOLID)

set(CMAKE_CXX_STANDARD 17)

file(COPY Roboto-Regular.ttf DESTINATION ${CMAKE_BINARY_DIR})


find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(SOLID_sfml main_sfml.cpp ball.cpp)
target_link_libraries(SOLID_sfml sfml-system sfml-window sfml-graphics)



find_package(raylib 2.5 QUIET) # Let CMake search for a raylib-config.cmake

add_executable(SOLID_raylib main_raylib.cpp ball_raylib.cpp)
target_link_libraries(SOLID_raylib raylib)