cmake_minimum_required(VERSION 3.15)
project(SOLID)

set(CMAKE_CXX_STANDARD 17)

file(COPY Roboto-Regular.ttf DESTINATION ${CMAKE_BINARY_DIR})


find_package(SFML 2.5 COMPONENTS system window graphics)
find_package(raylib 2.5 QUIET) # Let CMake search for a raylib-config.cmake

# bad SFML example
add_executable(SOLID_problem_sfml SRP/problem/main_sfml.cpp SRP/problem/ball_sfml.cpp)
target_link_libraries(SOLID_problem_sfml sfml-system sfml-window sfml-graphics)

# bad RayLib example
add_executable(SOLID_problem_raylib SRP/problem/main_raylib.cpp SRP/problem/ball_raylib.cpp)
target_link_libraries(SOLID_problem_raylib raylib)


# good SFML example
add_executable(SOLID_good_sfml SRP/solution/main_sfml.cpp SRP/solution/ball.cpp SRP/solution/render_manager.cpp)
target_link_libraries(SOLID_good_sfml sfml-system sfml-window sfml-graphics)

# good RayLib example
add_executable(SOLID_good_raylib SRP/solution/main_raylib.cpp SRP/solution/ball.cpp SRP/solution/render_manager_raylib.cpp)
target_link_libraries(SOLID_good_raylib raylib)