# Name
NAME			=	libft.a
NAME_H			:=	$(NAME:.a=.h)
HEADERS			= $(NAME_H) ft_printf_utils.h

# External tools
SHELL			=	/bin/sh
CC				=	clang
AR				=	ar
RANLIB			=	ranlib

CFLAGS			= -Wall -Wextra -Werror -I. -I includes -fPIC #-g
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
SOURCES_C		:=	$(addsuffix .c, $(SOURCE_RAW))
SOURCES			:= $(addprefix $(SRCS_DIR)/, $(SOURCES_C))

OBJS_O			:=	$(addsuffix .o, $(SOURCES_RAW))
OBJS			:= $(addprefix $(OBJS_DIR)/, $(OBJS_O))




all: $(NAME)

allc: all clean

bonus: all

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