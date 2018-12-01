#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/27 19:00:44 by atlekbai          #+#    #+#              #
#    Updated: 2018/06/27 19:12:13 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_gkrellm
OBJ_DIR = ./obj/
SRC_DIR = ./src/
INC_DIR = ./inc/

FLAGS = -Wall -Wextra -Werror
SRC = 	GraphicalMode.cpp \
		Hostname.cpp\
		Text.cpp\
		TextMode.cpp\
		main.cpp
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
HDRS = -I $(INC_DIR)

INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-F./frameworks

FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \

all: $(NAME)

$(NAME): $(OBJ)
		@clang++ $(FLAGS) $(OBJ) -o $(NAME) $(HDRS) $(FRAMEWORKS) $(INCLUDES) -lncurses
		@echo " \033[1;92m100%\033[0m"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@echo "\033[0;92mCompiling sources\033[0m"
		@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				@clang++ -c $< -o $@ $(FLAGS) $(HDRS) $(INCLUDES)
				@echo "\033[42m  \033[0m\c"

clean:
	@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@echo "\033[1;91mFCleaned\033[0m"

re: fclean all
