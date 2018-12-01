// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/20 12:26:58 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/20 13:27:30 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <fstream>

int	read_file(char *av)
{
	std::string		line;
	std::ifstream	ifs(av);

	if (!ifs || !ifs.good())
		std::cout << "cato0tails: " << av<<": " << strerror(errno) << std::endl;
	else
		while (std::getline(ifs, line))
			std::cout << line << std::endl;
	ifs.close();
	return (1);
}

int	main(int ac, char **av)
{
	std::string line;
	int			i = 0;

	if (ac == 1)
		while (1)
		{
			std::getline(std::cin, line);
			(!std::cin) ? exit(0) : (void)NULL;
			std::cout << line << std::endl;
		}
	else
		while (++i < ac)
			read_file(av[i]);
	return (1);
}
