#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 20:37:26 by atlekbai          #+#    #+#              #
#    Updated: 2018/11/17 20:37:26 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= 	Nibbler

DESERT	=	./LibraryDesert/
SRC_DIR	= 	./src/

INC_DIR	= 	./inc/
INC_ECS =	./inc/ECS
INC_MAN =	./inc/Managers
INC_COM =	./inc/Components

OBJ_DIR	= 	./obj/
OBJ_ECS	= 	./obj/ECS
OBJ_MAN	= 	./obj/Managers
OBJ_COM	= 	./obj/Components

FLAGS	= 	-std=c++14
SRC		=	main.cpp \
			Game.cpp \
			ECS/Entity.cpp \
			ECS/Manager.cpp \
			Components/Snake.cpp\
			Components/FoodSpawner.cpp\
			Components/SpriteComponent.cpp\
			GUI.cpp\
			Network.cpp
			
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INC		=	-I $(INC_DIR) \
			-I $(INC_ECS) \
			-I $(INC_MAN) \
			-I $(INC_COM) \
			-I $(DESERT)

INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-F./frameworks

FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework SDL2 -framework SDL2_image -framework SDL2_ttf

all:		$(NAME)

libs:
			@make -C LibraryDesert re
			@make -C LibraryNature re
			@make -C LibraryAlcatraz re

$(NAME):	$(OBJ)
			@make -C LibraryDesert
			@make -C LibraryNature
			@make -C LibraryAlcatraz
			@g++ $(FLAGS) $(OBJ) -o $(NAME) $(INC) $(FRAMEWORKS) $(INCLUDES)
			@echo " \033[1;92mDone!\033[0m"

$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):
			@echo "\033[0;92mCompiling sources\033[0m"
			@mkdir $(OBJ_DIR) $(OBJ_ECS) $(OBJ_MAN) $(OBJ_COM)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				@g++ -c $< -o $@ $(FLAGS) $(INC) $(INCLUDES)
				@echo "\033[42m  \033[0m\c"

clean:
			@make -C LibraryDesert clean
			@make -C LibraryNature clean
			@make -C LibraryAlcatraz clean
			@rm -rf $(OBJ_DIR)

fclean:		clean
			@make -C LibraryDesert fclean
			@make -C LibraryNature fclean
			@make -C LibraryAlcatraz fclean
			@rm -f $(NAME)
			@echo "\033[1;91mFCleaned\033[0m"

re:			fclean all
