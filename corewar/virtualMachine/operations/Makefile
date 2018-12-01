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

NAME = operations.a

SRCS = 	add.c \
		aff.c \
		and.c \
		frk.c \
		ld.c \
		ldi.c \
		lfrk.c \
		live.c \
		lld.c \
		lldi.c \
		or.c \
		st.c \
		sti.c \
		sub.c \
		xor.c \
		zjmp.c \
		useful_ops.c \
		command_struct.c

OBJ = $(SRCS:.c=.o)

HEADERS = 	../header.h ../op.h commands.h

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