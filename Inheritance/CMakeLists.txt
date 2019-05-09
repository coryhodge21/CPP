cmake_minimum_required(VERSION 3.12)
project(Templates)

set(CMAKE_CXX_STANDARD 11)

add_executable(Templates main.cpp ArrayBase.h Array.h Stack.h Fixed_Array.h Queue.h)