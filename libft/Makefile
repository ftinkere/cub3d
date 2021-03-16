# Name
NAME			=	libft.a
NAME_H			=	$(NAME:.a=.h)
HEADERS			= $(NAME_H) ft_printf_utils.h

# External tools
SHELL			=	/bin/sh
CC				=	clang
AR				=	ar
RANLIB			=	ranlib

CFLAGS			= -Wall -Wextra -Werror -I. -I includes #-g
ARFLAGS			= -rc

# Dirs
SRCS_DIR	= srcs
OBJS_DIR	= objs

# Sources
SOURCES_RAW		= \
	ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove \
	ft_memchr ft_memcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr \
	ft_strnstr ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii \
	ft_isprint ft_toupper ft_tolower ft_calloc ft_strdup ft_substr ft_strjoin \
	ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd \
	ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
	ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap \
	get_next_line get_next_line_utils ft_split_str\
	ft_math_1 ft_math_2 ft_printf ft_printf_base_writers ft_printf_cnts \
	ft_printf_isers ft_printf_printers_1 ft_printf_printers_2 \
	ft_printf_printers_3 ft_printf_readers ft_printf_spec ft_printf_utils
SOURCES_C		=	$(addsuffix .c, $(SOURCE_RAW))
SOURCES			= $(addprefix $(SRCS_DIR)/, $(SOURCES_C))

OBJS_O			=	$(addsuffix .o, $(SOURCES_RAW))
OBJS			= $(addprefix $(OBJS_DIR)/, $(OBJS_O))




all: $(NAME)

allc: all clean

bonus: all

test: $(NAME) test_main.c
#clang -Wall -Wextra -Werror -I. -I includes  -o test -g test_main.c srcs/ft_atoi.c srcs/ft_bzero.c srcs/ft_calloc.c srcs/ft_isalnum.c srcs/ft_isalpha.c srcs/ft_isascii.c srcs/ft_isdigit.c srcs/ft_isprint.c srcs/ft_itoa.c srcs/ft_lstadd_back.c srcs/ft_lstadd_front.c srcs/ft_lstclear.c srcs/ft_lstdelone.c srcs/ft_lstiter.c srcs/ft_lstlast.c srcs/ft_lstmap.c srcs/ft_lstnew.c srcs/ft_lstsize.c srcs/ft_math_1.c srcs/ft_math_2.c srcs/ft_memccpy.c srcs/ft_memchr.c srcs/ft_memcmp.c srcs/ft_memcpy.c srcs/ft_memmove.c srcs/ft_memset.c srcs/ft_printf_base_writers.c srcs/ft_printf.c srcs/ft_printf_cnts.c srcs/ft_printf_isers.c srcs/ft_printf_printers_1.c srcs/ft_printf_printers_2.c srcs/ft_printf_printers_3.c srcs/ft_printf_readers.c srcs/ft_printf_spec.c srcs/ft_printf_utils.c srcs/ft_putchar_fd.c srcs/ft_putendl_fd.c srcs/ft_putnbr_fd.c srcs/ft_putstr_fd.c srcs/ft_split.c srcs/ft_split_str.c srcs/ft_strchr.c srcs/ft_strdup.c srcs/ft_strjoin.c srcs/ft_strlcat.c srcs/ft_strlcpy.c srcs/ft_strlen.c srcs/ft_strmapi.c srcs/ft_strncmp.c srcs/ft_strnstr.c srcs/ft_strrchr.c srcs/ft_strtrim.c srcs/ft_substr.c srcs/ft_tolower.c srcs/ft_toupper.c srcs/get_next_line.c srcs/get_next_line_utils.c
	clang test_main.c -I. -I includes/ -lft -L. -o test

so: $(OBJS)
	clang -shared -o libft.so $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo -e "\x1b[38;5;3m""FCleaned""\x1b[0m"

clean:
	@-rm -f $(OBJS_DIR)/$(OBJS_O)
	@echo -e "\x1b[38;5;3m""Cleaned""\x1b[0m"

re: fclean all

beep:
	@echo -e "\07"

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)
	@echo -e "\x1b[38;5;6m""Maked $@""\x1b[0m"

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(NAME_H) | $(OBJS_DIR)
	@$(CC) -c $(CFLAGS) $(SRCS_DIR)/$*.c -o $(OBJS_DIR)/$*.o
	@echo -e "\x1b[38;5;2m""Compiled $*"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
