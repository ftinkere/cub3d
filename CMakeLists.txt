cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 99)
SET (CMAKE_C_COMPILER "/usr/bin/clang")

link_directories(/usr/local/lib ${CMAKE_CURRENT_SOURCE_DIR}/libft)
include_directories(/usr/local/include ${CMAKE_CURRENT_SOURCE_DIR}/libft ${CMAKE_CURRENT_SOURCE_DIR}/includes)

add_custom_target(libft
        COMMAND make all
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libft
        )

add_executable(cub3d srcs/main.c srcs/parsing/parse.c includes/parse.h srcs/cvec/cvec_0.c includes/cvec.h srcs/parsing/validate.c srcs/parsing/utils_0.c includes/cub3d_utils.h srcs/parsing/adders_p_0.c includes/adders_p.h srcs/parsing/newers.c srcs/parsing/adders_p_1.c includes/map_validates.h srcs/parsing/conf.c includes/conf.h srcs/cvec/cvec_1.c srcs/cub3d_debug.c includes/intmlx.h srcs/img/img_0.c includes/debug.h)
#add_executable(testsplit libft/srcs/main.c libft/srcs/ft_split.c libft/srcs/ft_strchr.c libft/srcs/ft_strlen.c libft/srcs/ft_substr.c libft/srcs/ft_memchr.c
#        libft/srcs/ft_memcpy.c libft/srcs/ft_memccpy.c)
target_link_libraries(cub3d mlx Xext pthread xcb Xau X11 Xdmcp bsd m z ft)