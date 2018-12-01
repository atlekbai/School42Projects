#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 13:45:11 by atlekbai          #+#    #+#              #
#    Updated: 2018/10/31 13:45:12 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= 	push_swap
NAME1	= 	checker
SRC_DIR	= 	./src/
INC_DIR	= 	./inc/
OBJ_DIR	= 	./obj/

FLAGS	= 	-Wall -Wextra -Werror
SRC		=	main.c \
			struct_node.c \
			struct_stack.c \
			struct_push_swap.c \
			operations_swap.c \
			operations_push.c \
			operations_rotate.c \
			operations_rrotate.c \
			array_qsort.c \
			sorting.c \
			checker.c \
			validation.c \
			sort_helpers.c \
			sort_2_3.c
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
INC		=	-I $(INC_DIR) -I libft

all:		$(NAME)

$(NAME):	$(OBJ) $(INC_DIR)
			@make -C libft
			@gcc $(FLAGS) $(filter-out $(OBJ_DIR)/checker.o, $(wildcard $(OBJ_DIR)/*.o)) -o $(NAME) libft/libft.a  $(INC)
			@gcc $(FLAGS) $(filter-out $(OBJ_DIR)/main.o, $(wildcard $(OBJ_DIR)/*.o)) -o $(NAME1) libft/libft.a  $(INC)
			@echo " \033[1;92mDone!\033[0m"

$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):	
			@echo "\033[0;92mCompiling sources\033[0m"
			@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@gcc -c $< -o $@ $(FLAGS) $(INC)
				@echo "\033[42m  \033[0m\c"

clean:
			@rm -rf $(OBJ_DIR)
			@make -C libft clean

fclean:		clean
			@rm -f $(NAME)
			@rm -f $(NAME1)
			@make -C libft fclean
			@echo "\033[1;91mFCleaned\033[0m"

re:			fclean all