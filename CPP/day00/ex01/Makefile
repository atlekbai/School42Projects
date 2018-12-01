#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 13:10:20 by atlekbai          #+#    #+#              #
#    Updated: 2018/06/18 15:23:50 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = phonebook
FLAGS = -Wall -Wextra -Werror
SRC =	Contact.class.cpp \
		main.cpp \
		ft_add.cpp \
		ft_search.cpp \
		ft_exit.cpp
HDR = Contact.class.hpp header.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	clang++ $(FLAGS) -c $(SRC)
	clang++ $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all