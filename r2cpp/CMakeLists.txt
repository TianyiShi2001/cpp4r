cmake_minimum_required(VERSION 3.5)
project(cpp4r LANGUAGES CXX)

set(CMAKE_CXX_COMPILER "clang++")

add_executable(pet pet/pet.cpp)
add_executable(template-1 template-1/main.cpp)