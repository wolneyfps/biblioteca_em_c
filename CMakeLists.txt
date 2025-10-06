cmake_minimum_required(VERSION 4.0)
project(biblioteca_em_c C)

set(CMAKE_C_STANDARD 11)

add_executable(biblioteca_em_c
        main.c
        livro.c
        database.c)
