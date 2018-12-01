// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/08 16:55:16 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/08 16:55:16 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Operand.class.hpp"
#include "Factory.class.hpp"
#include "AbstractVM.class.hpp"
#include <fstream>
#include <vector>

void	valid(AbstractVM &vm, std::string const &line)
{
	try
	{
		vm.validate(line);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	proc(AbstractVM &vm, std::string const &line)
{
	try
	{
		vm.process(line);
	}
	catch (std::exception &e)
	{
		vm.toggleExit();
		std::cout << e.what() << std::endl;
	}
}

int	main(int ac, char **av)
{
	AbstractVM		vm;
	std::string		line;
	
	if (ac == 2)
	{
		std::ifstream	ifs(av[1]);

		if (!ifs)
			std::cout << "File Error" << std::endl;
		else
		{
			while (std::getline(ifs, line))
				valid(vm, line);
			try
			{
				if (!vm.getHasError())
				{
					ifs.clear(), ifs.seekg(0, ifs.beg);
					vm.defaultIter();
					while (std::getline(ifs, line) && !vm.getExit())
						proc(vm, line);
				}
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			ifs.close();
		}
	}
	else if (ac == 1)
	{
		std::vector<std::string>	v;
		int							i = 1;

		while (1)
		{
			std::cout << i++ << ". ";
			std::getline(std::cin, line);
			(!std::cin) ? exit(0) : (void)NULL;
			if (line == ";;")
				break;
			v.push_back(line);
		}
		for(size_t i = 0; i < v.size(); i++)
			valid(vm, v[i]);
		try
		{
			if (!vm.getHasError())
			{
				vm.defaultIter();
				for(size_t i = 0; i < v.size() && !vm.getExit(); i++)
					proc(vm, v[i]);
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Usage: ./avm [<no parameters>|<filename>]" << std::endl;
		std::cout << "No parameters:" << std::endl << "\texecute from stdin" << std::endl;
		std::cout << "File given:" << std::endl << "\texecute from a file" << std::endl;
	}
	return (0);
}