cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)

project(jucui_in_world)

set(SOURCE_EXE main.cpp)


add_executable(jucui ${SOURCE_EXE})

add_subdirectory(tests)