// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/28 14:34:01 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/28 15:24:18 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "easyfind.hpp"

template<typename T>
typename T::const_iterator	easyfind(T const &cont, int i)
{
	typename T::const_iterator  it;
	typename T::const_iterator  ite = cont.end();

	for (it = cont.begin(); it != ite; it++)
		if (*it == i)
			return (it);
	return (ite);
}

template<typename T>
void	print_found(T const &cont, typename T::const_iterator const &f)
{
	if (f == cont.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << "Found: " << *f << " at [" << f - cont.begin() << "]"  << std::endl;	
}

int	main(void)
{
	std::vector<int>	vec;

	vec.push_back(12);
	vec.push_back(42);
	vec.push_back(2);
	vec.push_back(15);
	vec.push_back(75);
	vec.push_back(5);
	std::vector<int>::const_iterator f = easyfind(vec, 75);
	print_found(vec, f);

	std::list<int>		lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	std::list<int>::const_iterator k = easyfind(lst, 0);
	if (k == lst.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << "Found: " << *k << std::endl;
	return (0);
}
