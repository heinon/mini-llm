cmake_minimum_required(VERSION 3.20)

project(MiniLLM)

set(CMAKE_CXX_STANDARD 20)

add_executable(
    MiniLLM
    src/main.cpp
    src/tensor.cpp
)

target_include_directories(
    MiniLLM PRIVATE include
)