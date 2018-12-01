#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 10:43:55 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/01 13:03:32 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CW = corewar

all:
	@make -C virtualMachine
	@cp virtualMachine/$(CW) $(CW)

clean:
	@make -C virtualMachine clean

fclean:
	@make -C virtualMachine fclean
	@rm -f $(CW)

re: 	fclean all