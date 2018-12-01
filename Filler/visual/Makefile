# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 09:26:14 by dvdovenk          #+#    #+#              #
#    Updated: 2017/02/07 09:29:29 by dvdovenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual

N_INC = ft_lib.h

N_SRCS +=	main.c 

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -g

P_SRCS = ./srcs/
P_OBJ = ./obj/
P_LFT = libft/

I_INC = ./includes
I_LFT = ./libft/includes
I_ADD = -ltermcap
L_LFT = -L./libft/ -lft

NOC=\033[0m
OKC=\033[32;05m
ERC=\033[31m
WAC=\033[33m

SRC = $(addprefix $(P_SRCS),$(N_SRCS))
OBJ = $(addprefix $(P_OBJ),$(OBJ_NAME))
INC = $(addprefix -I,$(I_INC) $(I_LFT))

OBJ_NAME = $(N_SRCS:.c=.o)

all: $(NAME)

project: clean proj

proj: $(OBJ)
	@echo "$(OKC)$(NAME): Compiling objectives $(NAME)$(NOC)"
	@$(CC) $(CC_FLAGS) $(I_ADD) -o $(NAME) $(OBJ) $(INC) $(L_LFT)
	@echo "$(OKC)$(NAME): Compilation success!$(NOC)"

$(NAME): $(OBJ)
	@echo "$(OKC)$(NAME): Compiling libft.a$(NOC)"
	@make -C $(P_LFT)
	@echo "$(OKC)$(NAME): Compiling $(NAME)$(NOC)"
	@$(CC) $(CC_FLAGS) $(I_ADD) -o $(NAME) $(OBJ) $(INC) $(L_LFT)
	@echo "$(OKC)$(NAME): Compilation success!$(NOC)"

$(P_OBJ)%.o: $(P_SRCS)%.c	
	@mkdir -p $(P_OBJ) $(ADD)
	@$(CC) $(CC_FLAGS) -o $@ -c $^ $(INC)

clean:
	@make -C $(P_LFT) clean
	@rm -rf $(P_OBJ)
	@echo "$(WAC)$(NAME): Removing $(NAME) ./obj/$(NOC)"

fclean: clean
	@make -C $(P_LFT) fclean
	@rm -f $(NAME)
	@echo "$(WAC)$(NAME): Removing executable$(NOC)"

re: fclean all
