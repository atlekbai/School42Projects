#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 13:36:08 by atlekbai          #+#    #+#              #
#    Updated: 2018/05/29 13:36:08 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = units.a

SRCS = 	error.c \
		game.c \
		player.c \
		process.c \
		control.c \
		search.c \
		term.c \
		read_cor.c \
		move_pc.c

OBJ = $(SRCS:.c=.o)

HEADERS = 	../header.h ../op.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
		@gcc $(FLAGS) -c -I $(HEADERS) $(SRCS)
		@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re