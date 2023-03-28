cmake_minimum_required(VERSION 3.20)
project(q2_my_coder C)

set(CMAKE_C_STANDARD 99)

add_executable(q2_my_coder tool/main.c RLEList.c RLEList.h tool/AsciiArtTool.c tool/AsciiArtTool.h)
