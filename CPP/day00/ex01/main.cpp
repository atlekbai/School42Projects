// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/18 14:02:32 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/18 14:02:33 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "header.hpp"

int	main(void)
{
	Contact		contacts[MAX_CONTACTS];
	std::string	cmd;
	int			i = 0;

	std::cout << "Commands: " << ADD << ", " << SEARCH << ", " << EXIT << std::endl;
	while (1)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, cmd);
		(!std::cin) ? exit(0) : (void)NULL;
		if (cmd.compare(ADD) == 0)
			ft_add(contacts, i);
		else if (cmd.compare(SEARCH) == 0)
			ft_search(contacts, i);
		else if (cmd.compare(EXIT) == 0)
			ft_exit();
		else if (!cmd.empty())
			std::cout << "Invalid command entered" << std::endl;
	}
	return (0);
}
