# Name
NAME			=	cub3D

# External tools
SHELL			=	/bin/sh
CC				=	clang

CFLAGS			= -Werror -Wall -Wextra -I. -I includes \
					-I minilibx_mac -I libft -L libft -L minilibx_mac \
					-lmlx -lft -lm -framework AppKit -framework OpenGL

# Sources
SOURCES	= srcs/main.c srcs/parsing/parse.c srcs/cvec_0.c srcs/sprite.c \
	srcs/parsing/validate.c srcs/parsing/utils_0.c srcs/parsing/adders_p_0.c \
	srcs/parsing/newers.c srcs/parsing/adders_p_1.c srcs/parsing/conf.c \
	srcs/img_0.c srcs/raycast.c srcs/keybuff.c srcs/bmp.c srcs/move.c \
	srcs/shadow.c srcs/texs.c srcs/render.c srcs/load.c srcs/raycast_1.c \
	srcs/straight.c srcs/tiles.c srcs/tiny_math.c srcs/z_buf.c srcs/cross.c \
	srcs/parsing/tester.c

INCLUDES = includes/adders_p.h includes/cub3d_utils.h includes/cvec.h \
	includes/debug.h includes/intmlx.h includes/map_validates.h \
	includes/parse.h includes/raycast.h includes/types.h

all: $(NAME)

allc: all clean

bonus: all

fclean: clean
	$(MAKE) -C libft fclean
	@rm -f $(NAME)
	@echo -e "\x1b[38;5;3m""FCleaned""\x1b[0m"

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx_mac clean
	@echo -e "\x1b[38;5;3m""Cleaned""\x1b[0m"

re: fclean all

beep:
	@echo -e "\07"

$(NAME): $(SOURCES) $(INCLUDES)
	$(MAKE) -C libft all
	$(MAKE) -C minilibx_mac all
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCES)
	@echo -e "\x1b[38;5;6m""Maked $@""\x1b[0m"
