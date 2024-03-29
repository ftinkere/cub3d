cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 99)
SET (CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_C_FLAGS "-o3 -Wall -Wextra -Werror")

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libft ${CMAKE_CURRENT_SOURCE_DIR}/minilibx_mac)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libft ${CMAKE_CURRENT_SOURCE_DIR}/minilibx_mac ${CMAKE_CURRENT_SOURCE_DIR}/includes)

add_custom_target(libft
        COMMAND make all
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libft
        )

add_custom_target(minilibx_mac
        COMMAND make all
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/minilibx_mac
        )

add_executable(cub3d_mac srcs/main.c srcs/parsing/parse.c includes/parse.h srcs/cvec_0.c includes/cvec.h srcs/parsing/validate.c srcs/parsing/utils_0.c includes/cub3d_utils.h srcs/parsing/adders_p_0.c includes/adders_p.h srcs/parsing/newers.c srcs/parsing/adders_p_1.c includes/map_validates.h srcs/parsing/conf.c cub3d_debug.c includes/intmlx.h srcs/img_0.c includes/debug.h includes/types.h srcs/raycast.c includes/raycast.h srcs/keybuff.c srcs/bmp.c srcs/move.c srcs/shadow.c srcs/texs.c srcs/render.c srcs/load.c srcs/raycast_1.c srcs/straight.c srcs/tiles.c srcs/tiny_math.c srcs/sprite.c srcs/cross.c srcs/z_buf.c srcs/parsing/tester.c)
# srcs/win.c
target_link_libraries(cub3d_mac mlx m ft "-framework OpenGL" "-framework AppKit")
add_dependencies(cub3d_mac libft minilibx_mac)