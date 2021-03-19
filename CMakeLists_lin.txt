cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/clang")
#set(CMAKE_C_FLAGS "-fsanitize=address")
#set(CMAKE_C_FLAGS "-o3")

link_directories(/usr/local/lib ${CMAKE_CURRENT_SOURCE_DIR}/libft ${CMAKE_CURRENT_SOURCE_DIR}/minilibx)
include_directories(/usr/local/include ${CMAKE_CURRENT_SOURCE_DIR}/libft ${CMAKE_CURRENT_SOURCE_DIR}/minilibx ${CMAKE_CURRENT_SOURCE_DIR}/includes  ${CMAKE_CURRENT_SOURCE_DIR}/libft/includes/})

add_custom_target(libft
        COMMAND make all
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libft
        )

add_custom_target(minilibx
        COMMAND make all
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/minilibx
        )

add_executable(cub3d srcs/main.c srcs/parsing/parse.c includes/parse.h srcs/cvec_0.c includes/cvec.h srcs/parsing/validate.c srcs/parsing/utils_0.c includes/cub3d_utils.h srcs/parsing/adders_p_0.c includes/adders_p.h srcs/parsing/newers.c srcs/parsing/adders_p_1.c includes/map_validates.h srcs/parsing/conf.c includes/conf.h srcs/cub3d_debug.c includes/intmlx.h srcs/img_0.c includes/debug.h includes/types.h srcs/raycast.c includes/raycast.h srcs/keybuff.c srcs/bmp.c srcs/move.c srcs/shadow.c srcs/texs.c srcs/render.c srcs/load.c srcs/raycast_1.c srcs/straight.c srcs/tiles.c srcs/tiny_math.c srcs/sprite.c)
add_dependencies(cub3d libft minilibx)
target_link_libraries(cub3d mlx Xext pthread xcb Xau X11 Xdmcp bsd m z ft)