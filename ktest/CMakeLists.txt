set(CMAKE_CXX_STANDARD           20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS        OFF)


find_package(X11) 

cmake_minimum_required(VERSION 3.22)   
project(vassist)

add_executable(${PROJECT_NAME} test.cpp)



target_link_libraries(${PROJECT_NAME} mylib )  
target_link_libraries(${PROJECT_NAME} X11 )  

add_subdirectory(lib)
