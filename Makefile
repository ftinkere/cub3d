# Name
NAME			=	cub3d

# External tools
SHELL			=	/bin/sh
CC				=	clang

CFLAGS			= -Wall -Wextra -Werror \
	-I. -I includes \
	-I libft -L libft -l ft \
	-I minilibx -L minilibx -l mlx \
	-lXext -lpthread -lxcb -lXau -lX11 -lXdmcp -lbsd -lm -lz

# Sources
SOURCES	= srcs/main.c srcs/parsing/parse.c srcs/cvec_0.c srcs/sprite.c \
	srcs/parsing/validate.c srcs/parsing/utils_0.c srcs/parsing/adders_p_0.c \
	srcs/parsing/newers.c srcs/parsing/adders_p_1.c srcs/parsing/conf.c \
	srcs/img_0.c srcs/raycast.c srcs/keybuff.c srcs/bmp.c srcs/move.c \
	srcs/shadow.c srcs/texs.c srcs/render.c srcs/load.c srcs/raycast_1.c \
	srcs/straight.c srcs/tiles.c srcs/tiny_math.c srcs/z_buf.c srcs/cross.c \
	srcs/parsing/tester.c

all: $(NAME)

allc: all clean

bonus: all

fclean: clean
	@rm -f $(NAME)
	@echo -e "\x1b[38;5;3m""FCleaned""\x1b[0m"

clean:
	@-rm -f $(OBJS_DIR)/$(OBJS_O)
	@echo -e "\x1b[38;5;3m""Cleaned""\x1b[0m"

re: fclean all

beep:
	@echo -e "\07"

$(NAME): $(SOURCES) libft
	clang -Werror -Wall -Wextra $(SOURCES) -I. -I includes -I minilibx_mac \
		-I libft -L libft -L minilibx_mac -lmlx -lft -lm -framework AppKit \
		-framework OpenGL -o cub3D
	@echo -e "\x1b[38;5;6m""Maked $@""\x1b[0m"
