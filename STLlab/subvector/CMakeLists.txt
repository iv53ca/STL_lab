cmake_minimum_required(VERSION 3.20)
project(subvector)

set(CMAKE_CXX_STANDARD 17)

add_executable(subvector main.cpp subvector_class.h subforwardlist_class.h)
