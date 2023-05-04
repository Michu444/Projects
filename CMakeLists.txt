cmake_minimum_required(VERSION 3.24)
project(Projects)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library Book.cpp Book.h Reports.cpp Reports.h Library.cpp)

