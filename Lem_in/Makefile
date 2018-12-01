#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 21:01:46 by atlekbai          #+#    #+#              #
#    Updated: 2018/05/07 21:01:47 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
FLAGS = -Wall -Wextra -Werror
FILES = ants.c \
		getters.c \
		lemin.c \
		manage_ants.c \
		node_init.c \
		node_util.c \
		others.c \
		out.c \
		path_finding.c \
		queue.c
OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft
		@gcc $(FLAGS) -I header.h -c $(FILES)
		@gcc $(OBJ) -o $(NAME) libft/libft.a
		@echo "\033[0;92m-- lem-in compiled --"

clean:
		@make -C libft clean
		@rm -f $(OBJ)
		@echo "\033[0;93m-- lem-in *.o files cleaned --"

fclean:	clean
		@make -C libft fclean
		@rm -f $(NAME)
		@echo "\033[0;91m-- lem-in deleted --"

re: fclean all