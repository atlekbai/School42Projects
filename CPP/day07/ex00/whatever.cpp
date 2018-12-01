// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   whatever.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/27 12:39:03 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/27 12:47:49 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const	&min(T const &a, T const &b)
{
	if (a == b)
		return (b);
	return ((a < b) ? a : b);
}

template<typename T>
T const	&max(T const &a, T const &b)
{
	if (a == b)
		return (b);
	return ((a > b) ? a : b);
}

int		main(void)
{
	int a = 2;
	int b = 3;
	std::cout << "Int values: a = " << a << "| b = " << b << std::endl;
	::swap(a, b);
	std::cout << "* SWAP *" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << std::endl << "String values: c = " << c << "| d = " << d << std::endl;
	::swap(c, d);
	std::cout << "* SWAP *" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	double e = 5.43;
	double f = 42.412;
	std::cout << std::endl << "Double values: e = " << e << "| f = " << f << std::endl;
	::swap(e, f);
	std::cout << "* SWAP *" << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
	return (0);
}
