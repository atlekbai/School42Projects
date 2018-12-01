// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 14:19:21 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 14:19:22 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Pony.hpp"

int	showPony(Pony &p)
{
	std::cout << std::endl << "Pony information" << std::endl;
	std::cout << "Name: " << p.getName() << std::endl;
	std::cout << "Color: " << p.getColor() << std::endl;
	std::cout << "Age: " << p.getAge() << std::endl;
	std::cout << "Corn length: " << p.getCornLength() << std::endl;
	std::cout << "------------------" << std::endl;
	return (1);
}

void	ponyOnTheHeap(void)
{
	Pony*	heap_pony = new Pony();
	std::cout << "Pony on heap created" << std::endl;
	heap_pony->setName("Jambo Heap");
	heap_pony->setColor("Blue");
	heap_pony->setAge(2008);
	heap_pony->setCornLength(10);
	showPony(*heap_pony);
	delete heap_pony;
}

void	ponyOnTheStack(void)
{
	Pony stack_pony = Pony();
	std::cout << "Pony on stack created" << std::endl;
	stack_pony.setName("Jimbo Stack");
	stack_pony.setColor("Yellow");
	stack_pony.setAge(1991);
	stack_pony.setCornLength(21);
	showPony(stack_pony);
}

int	main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}