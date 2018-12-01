// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   iter.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/27 12:53:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/27 13:09:31 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

template<typename T>
void	iter(T *arr, size_t len, void (*f)(T&))
{
	size_t i = -1;

	while (++i < len)
		(*f)(arr[i]);
}

template<typename T>
void	print(T &val)
{
	std::cout << val << std::endl;
}

template<typename T>
void	increment(T &val)
{
	val++;
}

int main(void)
{
	srand(time(NULL));
	int	len = 10;
	int *n = new int[len];
	for (int i = 0; i < len; i++)
		n[i] = rand() % 10;
	
	std::cout << "Iter call on int array" << std::endl;
	iter(n, len, print);
	std::cout << std::endl << "Increment function called" << std::endl;
	iter(n, len, increment);
	iter(n, len, print);

	int size = 5;
	char alphanum[] = {
		'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i',
		'J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r',
		'S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z','0','1',
		'2','3','4','5','6','7','8','9'
	};
	std::cout << std::endl;
	std::string *s = new std::string[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 8; j++)
			s[i] += alphanum[rand() % 61];
	std::cout << "Iter call on string array" << std::endl;
	iter(s, size, print);
	return (1);
}
