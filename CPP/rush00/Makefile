#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 11:53:36 by atlekbai          #+#    #+#              #
#    Updated: 2018/06/23 16:49:15 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro
SRC =	Bullet.cpp \
		game.cpp \
		GameEntity.class.cpp \
		ThingGroup.cpp \
		Player.class.cpp \
		Position.class.cpp \
		SpaceThing.cpp \
		visual.cpp \
		Rect.cpp \
		Enemy.cpp \
		EnemySwarm.cpp \
		Boss.cpp \
		ncurses_funcs.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) -c $(SRC)
	clang++ $(OBJ) -o $(NAME) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all