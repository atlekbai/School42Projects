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

NAME = atlekbai.filler
FLAGS = -Wall -Wextra -Werror
FILES = ai.c filler.c map.c util.c

all: 	$(NAME)

$(NAME): $(FILES)
		@make -C libft
		@gcc $(FLAGS) -I header.h $(FILES) libft/libft.a -o $(NAME)
		@echo "\033[0;92m-- atlekbai.filler ready to fight --"

clean:
		@make -C libft clean

fclean: clean
		@make -C libft fclean
		@rm -f $(NAME)
		@echo "\033[0;91m-- atlekbai.filler terminated --"

re:		fclean all
