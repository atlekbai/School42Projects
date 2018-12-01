/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 19:20:38 by atlekbai          #+#    #+#             */
//   Updated: 2018/06/19 20:01:41 by atlekbai         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	replace(std::string &content, std::string s1, std::string s2)
{
	size_t	i = 0;

	i = content.find(s1, 0);
	while (i != std::string::npos)
	{
		content.replace(i, s1.length(), s2);
		i = content.find(s1, i + 1);
	}
	return (1);
}

int	main(int ac, char **av)
{
	std::string		content;
	std::string		line;

	if (ac == 4)
	{
		std::ifstream	ifs(av[1]);

		if (!ifs)
		{
			std::cout << "File error" << std::endl;
			exit(0);
		}
		std::ofstream	ofs(std::string(av[1]) + ".replace");		
		while (std::getline(ifs, line))
			content.append(line + "\n");
		ifs.close();
		replace(content, std::string(av[2]), std::string(av[3]));
		ofs << content;
		ofs.close();
	}
	else
		std::cout << "Usage: ./replace <filename> <string to replace> <string to add>" << std::endl;
	return (0);
}
