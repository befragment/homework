cmake_minimum_required(VERSION 3.23)
project(rationalnumbers)

set(CMAKE_CXX_STANDARD 17)

add_executable(rationalnumbers "main.cpp" "RationalLibrary/Rational.cpp" "RationalLibrary/Rational.hpp" )
