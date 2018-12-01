// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/28 19:59:04 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/28 20:13:59 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Instruction.hpp"
#include <fstream>

void	readFile(char *str, std::vector<char> &v)
{
	std::fstream	ifs(str);
	char			c;

	while(ifs)
	{
		ifs.get(c);
		v.push_back(c);
	}
	ifs.close();
}

int	main(int ac, char **av)
{
	Instruction 		inst;
	std::vector<char>	queue;
	int 				brackets = 0;

	if (ac == 2)
	{
		readFile(av[1], queue);
		for (size_t i = 0; i < queue.size();i++)
		{
			inst.execute(queue[i]);
			if (queue[i] == '[')
			{
				if (!inst[inst.getCurrent()])
				{
					brackets++;
					while (brackets)
					{
						i++;
						brackets += (queue[i] == '[') ? 1 : 0;
						brackets -= (queue[i] == ']') ? 1 : 0;
					}
				}
				else
					continue;
			}
			else if (queue[i] == ']')
			{
				if (!inst[inst.getCurrent()])
					continue;
				else
				{
					brackets++;
					while (brackets)
					{
						i--;
						brackets -= (queue[i] == '[') ? 1 : 0;
						brackets += (queue[i] == ']') ? 1 : 0;
					}
				}
			}
		}

	}
	else
		std::cout << "Usage:./mindopen <file>" << std::endl;
	return (0);
}
