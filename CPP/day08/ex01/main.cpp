// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/28 15:29:27 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/28 15:29:27 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"

void showSpans(Span &sp, int i)
{
	std::cout << "Span #" << i << std::endl;
	try
	{
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  span: " << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	showSpans(sp, 0);
// ******************Exception check 0 nums************************************* //
	Span sp1 = Span(10);
	showSpans(sp1, 1);
// ******************Exception check full*************************************** //
	Span sp2 = Span(3);
	sp2.addNumber(1);
	sp2.addNumber(2);
	sp2.addNumber(3);
	try
	{
		sp2.addNumber(4);		
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	showSpans(sp2, 3);
// ******************Add Numbers function *************************************** //
	Span sp3 = Span(10000);
	sp3.addNumbers(3000, 3);
	sp3.addNumbers(3000, 7);
	sp3.addNumbers(3000, 10);
	sp3.addNumbers(1000, 19);
	showSpans(sp3, 4);
	return (1);
}
