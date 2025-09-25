cmake_minimum_required(VERSION 3.30.5)
project(libft C)

set(CMAKE_C_STANDARD 11)

include_directories(/usr/local/opt/cunit/include)
link_directories(/usr/local/opt/cunit/lib)

add_library(libft STATIC
		ft_atoi.c
		ft_memset.c
		ft_bzero.c
		ft_calloc.c
		ft_strdup.c
		ft_strlen.c
		ft_isalpha.c
		ft_isdigit.c
		ft_isascii.c
		ft_isprint.c
		ft_isalnum.c
		ft_memcpy.c)

add_executable(test_runner test_main.c)
target_link_libraries(test_runner libft CUnit)
