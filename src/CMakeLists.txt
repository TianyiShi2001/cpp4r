cmake_minimum_required(VERSION 3.5)

project(cpp4r LANGUAGES CXX)

set(CMAKE_CXX_COMPILER "clang++")


# set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(helloworld hello/helloworld.cpp)
# add_executable(fn hello/fn.cpp)
add_executable(types hello/types.cpp)
add_executable(pointers_and_references hello/pointers_and_references.cpp)
add_executable(controlflow hello/controlflow.cpp)
add_executable(enum enum.cpp)
add_executable(move move.cpp)


add_executable(class-complex-number class/complex-number.cpp)
add_subdirectory(Adder)

# target_link_libraries(helloworld adder)

# target_include_directories(helloworld PUBLIC Adder)
# target_link_directories(helloworld PRIVATE Adder)
