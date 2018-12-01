# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 11:02:10 by dvdovenk          #+#    #+#              #
#    Updated: 2016/12/26 21:20:31 by dvdovenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

NOC=\033[0m
OKC=\033[94;1m
ERC=\033[31m
WAC=\033[33m

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SRC = $(addprefix $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME += libft.h ft_structs.h

SRC_NAME += ft_atoi.c \
        ft_bzero.c \
        ft_itoa.c \
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
        get_next_line.c \
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
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_lstnew.c \
        ft_lstdelone.c \
        ft_lstdel.c \
        ft_lstadd.c \
        ft_lstiter.c \
        ft_lstmap.c \
		ft_strrev.c \
		ft_strupcase.c \
		ft_strlowcase.c \
		ft_sorttab.c \
		ft_sortrevtab.c \
		ft_fprintf.c \
		ft_base16.c \
		ft_string.c \
		ft_char.c  \
		ft_checkers.c \
		ft_counters.c \
		ft_num8.c \
		ft_num10.c \
		ft_num16.c \
		ft_unsigned.c \
		ft_tools.c \
		ft_printf_strdel.c \
		ft_create_new_list.c \
		ft_printf_atoi.c \
		ft_pointer.c \
		ft_output.c \
		ft_wchar.c \
		ft_toolkit.c \
		ft_color.c \
		ft_binary.c 

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(OKC)libft: Creating $(NAME): \c\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(OKC)OK.\nlibft: Compilation success!$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@echo "$(WAC)libft: Removing libft ./obj/$(NOC)"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "$(WAC)libft: Removing $(NAME)$(NOC)"
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re: fclean all

