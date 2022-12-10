cmake_minimum_required(VERSION 3.23)
project(vectors)

set(CMAKE_CXX_STANDARD 17)

add_executable(vectors "main.cpp" "VectorsLib/VectorsLib.cpp" "VectorsLib/VectorsLib.hpp")
