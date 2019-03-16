cmake_minimum_required(VERSION 3.13)
project(42_Fillit C)

set(CMAKE_C_STANDARD 99)
include_directories(libft)
link_directories(libft)

add_executable(42_Fillit main.c read.c fillit.h alg.c)

target_link_libraries(42_Fillit -lft)
