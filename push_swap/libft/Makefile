NAME = libft.a

SRCS = field_width.c flags.c ft_atoi.c ft_atoi_base.c ft_bzero.c ft_check.c ft_check_pers.c ft_itoa.c \
    ft_itoa_base.c ft_itoa_base_l.c ft_lcs_unicode.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c \
    ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
    ft_output.c ft_printf.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
    ft_putstr.c ft_putstr_fd.c ft_strchr.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c \
    ft_strnew.c ft_strrchr.c ft_strstr.c ft_strsub.c ft_toupper.c function_pointers.c get_next_line.c \
    modifiers.c nbr_hex.c precision.c specifiers.c specifiers2.c ft_strequ.c ft_strsplit.c ft_strdigit.c

OBJ = $(SRCS:.c=.o)

HEADERS = 	../header.h

FLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(ANC) $(OBJ)
		@gcc $(FLAGS) -c -I $(HEADERS) $(SRCS)
		@ar rc $(NAME) $(OBJ)


%.o: %.c
	@gcc -c $< -o $@ $(FLAGS) $(INC)
	@echo "\033[42m  \033[0m\c"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
