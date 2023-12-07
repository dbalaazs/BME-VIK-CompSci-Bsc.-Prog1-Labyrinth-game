cmake_minimum_required(VERSION 3.26)
project(labor1207 C)

set(CMAKE_C_STANDARD 11)

add_executable(labor1207 main.c src/debugmalloc.h
        src/map.c
        src/map.h
        src/movement.c
        src/movement.h)
