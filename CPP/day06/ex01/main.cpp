// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/26 17:44:07 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/26 17:53:55 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "main.hpp"

void	*serialize(void)
{
	srand(time(NULL));
	char alphanum[] = {
		'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i',
		'J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r',
		'S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z','0','1',
		'2','3','4','5','6','7','8','9'
	};
	std::string serial;
	std::string serial1;
	std::string serial2;
	for (int i = 0; i < 8; i++)
	{
		serial += alphanum[rand() % 61];
		serial1 += alphanum[rand() % 61];
		serial2 += alphanum[rand() % 61];
	}
	Data *data = new Data(serial1 + serial2, serial, rand());
	void *ptr = reinterpret_cast<void *>(data);
	return (ptr);
}

Data	*deserialize(void *raw)
{
	Data *data = reinterpret_cast<Data *>(raw);
	if (data == NULL)
		return (NULL);
	else
		return (data);
}

int	main(void)
{
	void *addr = serialize();
	Data *data = reinterpret_cast<Data *>(addr);
	std::cout << "Data:" << std::endl;
	std::cout << "First  array: " << data->s1 << std::endl;
	std::cout << "Random integ: " << data->n << std::endl;
	std::cout << "Second array: " << data->s2 << std::endl;
	return (0);
}
