#cmake_minimum_required(VERSION 4.0)
#project(ft_lib C)
#
#set(CMAKE_C_STANDARD 11)
#
#include_directories(/usr/local/opt/cunit/include)
#link_directories(/usr/local/opt/cunit/lib)
#
#target_link_libraries(your_target_name CUnit)
#
#add_library(ft_lib STATIC "ft_atoi.c"
#        test_main.c)

cmake_minimum_required(VERSION 4.0)
project(ft_lib C)

set(CMAKE_C_STANDARD 11)

include_directories(/usr/local/opt/cunit/include)
link_directories(/usr/local/opt/cunit/lib)

add_library(ft_lib STATIC
        ft_atoi.c
        ft_memset.c)

#target_link_libraries(ft_lib CUnit)

add_executable(test_runner test_main.c)
target_link_libraries(test_runner ft_lib CUnit)
