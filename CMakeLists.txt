cmake_minimum_required(VERSION 3.29)
project(ejemplo1)

set(CMAKE_CXX_STANDARD 17)

find_package(fmt)

find_package(glfw3)
add_executable(ejemplo1 main.cpp)
target_link_libraries(ejemplo1 fmt::fmt)
target_link_libraries(ejemplo1 glfw)
