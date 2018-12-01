// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/26 18:17:06 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/26 18:17:06 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Base.hpp"
#include "ABC.hpp"

Base	*generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	std::cout << "Pointer to ";
	if (i == 0)
	{
		std::cout << "A generated" << std::endl;
		return (new A());
	}
	else if (i == 1)
	{
		std::cout << "B generated" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "C generated" << std::endl;
		return (new C());
	}
}

void	identify_from_pointer(Base *p)
{
	A *a;
	B *b;
	C *c;

	std::cout << "Identified as pointer: ";
	a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "A" << std::endl;
	b = dynamic_cast<B*>(p);
	if (b)
		std::cout << "B" << std::endl;
	c = dynamic_cast<C*>(p);
	if (c)
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base &p)
{
	std::cout << "Identified as reference: ";
	try{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch(std::exception &e)
	{}
	try{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch(std::exception &e)
	{}
	try{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(std::exception &e)
	{}
}

int		main(void)
{
	B a;
	std::cout << "Reference to B" << std::endl;
	Base *b = generate();
	identify_from_reference(a);
	identify_from_pointer(b);
	return (0);
}