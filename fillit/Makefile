#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 16:48:08 by atlekbai          #+#    #+#              #
#    Updated: 2018/03/30 16:48:09 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILES = algo.c reader.c reader_helper.c shape.c map.c
LIB = ./libft/libft.a

all:$(NAME)

$(NAME): $(FILES)
		make -C libft
		gcc $(FLAGS) -o $(NAME) $(FILES) $(LIB)

clean:
		make -C libft clean

fclean: clean
		make -C libft fclean
		/bin/rm -f $(NAME)

re:		fclean all