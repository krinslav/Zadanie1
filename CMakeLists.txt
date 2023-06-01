cmake_minimum_required(VERSION 3.0.0)

project(Zadanie1 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(Zadanie1 src/main.cpp lib/src/SetGraph.cpp lib/src/ArcGraph.cpp lib/src/ListGraph.cpp lib/src/MatrixGraph.cpp lib/src/otherFunc.cpp)

target_include_directories(Zadanie1 PRIVATE lib/header)