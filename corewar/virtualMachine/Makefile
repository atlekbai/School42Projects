# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:45:37 by ovirchen          #+#    #+#              #
#    Updated: 2018/06/01 15:17:42 by hdanylev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = 	main.c \
		map.c \
		visual_1.c \
		visual_2.c \
		fresh_color.c \

CC = gcc

OBJ = 	$(SRCS:.c=.o)

HEADERS =	header.h \
			libft/printf.h \
			op.h

LIBS = 	libft/libft.a \
		validation/validation.a \
		operations/operations.a \
		units/units.a

FLAGS = -Wall -Werror -Wextra -lncurses

all: $(NAME)

$(NAME): libs $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBS) $(FLAGS)

$(OBJ): $(HEADERS) $(SRCS)
	$(CC) -c $(SRCS) -I $(HEADERS)
	@echo "\033[31mCorewar \033[33mMAKED\033[0m"

clean:
	rm -f $(OBJ)
	@make clean -C libft
	@make clean -C operations
	@make clean -C validation
	@make clean -C units
	@echo "\033[33mCLEANED\033[0m"

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C operations
	@make fclean -C validation
	@make fclean -C units
	@echo "\033[33mCLEANED ALL\033[0m"

re: fclean all

libs:
	@make -C operations
	@make -C libft
	@make -C validation
	@make -C units

.PHONY: all clean fclean re
