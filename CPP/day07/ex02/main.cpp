// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/27 15:19:38 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/27 15:20:41 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Array.hpp"

template<typename T>
void	print_all(Array<T> &arr, size_t size)
{
	std::cout << "[";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "\'" << arr[i] << "\'";
		if (i + 1 != size)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int	main(void)
{
	srand(time(NULL));
	Array<int> i(10);
	for(int j = 0; j < 10; j++)
		i[j] = rand() % 10;
	
	Array<char> c(10);
	for(int j = 0; j < 10; j++)
		c[j] = 33 + rand() % 93;

	std::string v[] = {
		"add",
		"allow",
		"bake",
		"bang",
		"call",
		"chase",
		"damage",
		"drop",
		"end",
		"escape",
		"fasten"
	};
	std::string f[] = {
		"potato",
		"chips",
		"hash",
		"browns",
		"haddock",
		"balsamic",
		"vinegar",
		"salt",
		"custard",
		"hoisin",
		"sauce"
	};
	Array<std::string> s(10);
	for(int j = 0; j < 10; j++)
		s[j] = v[rand() % 10] + " " + f[rand() % 10];

	std::cout << "Int array: ";
	print_all(i, i.size());
	std::cout << "Char array: ";
	print_all(c, c.size());
	std::cout << "String array: ";
	print_all(s, s.size());
	try
	{
		std::cout << s[-1];
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() <<std::endl;
	}

	try
	{
		std::cout << s[8] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() <<std::endl;
	}

	try
	{
		std::cout << s[100500];
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() <<std::endl;
	}
	return (0);
}
