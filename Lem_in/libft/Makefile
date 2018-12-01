#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 17:06:46 by atlekbai          #+#    #+#              #
#    Updated: 2018/04/19 16:04:32 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FILES = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstnew.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_atoi_base.c \
		ft_list_remove_if.c \
		ft_min.c \
		ft_max.c \
		ft_lst_strsplit.c \
		ft_lst_push_back.c \
		ft_strndup.c \
		ft_strnchr.c \
		ft_stacknew.c \
		ft_stackdelone.c \
		ft_stackadd.c \
		get_next_line.c \
		ft_itoa_base.c \
		ft_stradd.c \
		get_bytes.c \
		ft_strjoin_free.c \
		additional_printf.c \
		csp.c \
		digit.c \
		hex.c \
		printf.c \
		math.c \
		octal.c \
		wc_string.c \
		printf_helper.c \
		color.c \
		ft_strcount.c \
		ft_strtil.c

OBJ = $(FILES:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJ)
		@gcc $(FLAGS) -c -I libft.h $(FILES)
		@ar rc $(NAME) $(OBJ)
		@echo "\033[0;92m-- Libft compilation complete --"

clean:
		@rm -f $(OBJ)
		@echo "\033[0;93m-- Libft *.o files cleaned --"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[0;91m-- Libft completely cleaned --"

re:		fclean all
