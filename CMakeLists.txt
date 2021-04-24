cmake_minimum_required(VERSION 3.8)

set(This Game)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
enable_testing()

add_subdirectory(googletest)

set(Header
    game.hpp
    )
set(Sources
    game.cpp
    )

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test) 
# goes to this directory and check for CMakeList.txt








