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

NAME = validation.a

SRCS = 	validation_addsub.c \
		validation_aff.c \
		validation_ld.c \
		validation_ldi.c \
		validation_st.c \
		validation_sti.c \
		validation_xorand.c

OBJ = $(SRCS:.c=.o)

HEADERS = 	../header.h ../op.h

FLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
		@gcc -c -I $(FLAGS) $(HEADERS) $(SRCS)
		@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re