#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 17:04:30 by atlekbai          #+#    #+#              #
#    Updated: 2018/06/20 17:06:47 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = eval_expr
FLAGS = -Wall -Wextra -Werror
SRC = 	Fixed.class.cpp \
		main.cpp
OBJ = $(SRC:.cpp=.o)
HDR = Fixed.class.hpp

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) -c $(SRC)
	clang++ $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all