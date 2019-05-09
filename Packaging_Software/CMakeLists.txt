cmake_minimum_required(VERSION 3.13)
project(Shared_Lib)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shared_Lib
        main.cpp
        my_shared_lib.h my_shared_lib.cpp
        shared_exe.h shared_exe.cpp
        )