cmake_minimum_required(VERSION 3.22)
project(test)
add_executable(${PROJECT_NAME} test.cpp)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)