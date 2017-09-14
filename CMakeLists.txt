cmake_minimum_required(VERSION 3.8)
project(ET-Sat)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Health_And_Safety.c Health_And_Safety.h typedef.h)
add_executable(ET-Sat ${SOURCE_FILES})