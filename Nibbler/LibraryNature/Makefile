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

NAME	= 	libNature.so
SRC_DIR	= 	./

INC_DIR	= 	../inc/

OBJ_DIR	= 	./obj/

FLAGS	= 	-std=c++14
SRC		=	NatureFramework.cpp
			
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INC		=	-I $(INC_DIR) -I ../inc/Components -I ../inc/ECS -I ./

INCLUDES	=	-I ../frameworks/SDL2.framework/Versions/A/Headers \
				-I ../frameworks/SDL2_image.framework/Versions/A/Headers \
				-I ../frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-F ../frameworks

FRAMEWORKS	=	-F ../frameworks \
				-rpath ../frameworks \
				-framework SDL2 -framework SDL2_image -framework SDL2_ttf

all:		$(NAME)

$(NAME):	$(OBJ)
			@clang++ $(FLAGS) $(OBJ) $(INC) $(FRAMEWORKS) $(INCLUDES) -dynamiclib -o $(NAME)
			@echo " \033[1;92mDone!\033[0m"

$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):
			@echo "\033[0;92mCompiling sources\033[0m"
			@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				@clang++ -c $< -o $@ $(FLAGS) $(INC) $(INCLUDES)
				@echo "\033[42m  \033[0m\c"

clean:
			@rm -rf $(OBJ_DIR)

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[1;91mFCleaned\033[0m"

re:			fclean all
