cmake_minimum_required(VERSION 3.8)
project(ET-Sat)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Main/main.c Main/main.h mode_SCM/SCM.c mode_SCM/SCM.h)
add_executable(ET-Sat ${SOURCE_FILES})