cmake_minimum_required(VERSION 3.23)
project(method_gauss)

set(CMAKE_CXX_STANDARD 14)

add_executable(method_gauss main.cpp gauss.hpp matrix.hpp)
