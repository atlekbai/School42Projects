// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/28 15:29:19 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/28 15:29:19 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"

Span::Span(void) : n(0){}

Span::Span(unsigned n) : n(n)
{
	vec.reserve(n);
}

Span::Span(Span const &src) : n(src.getSize())
{
	if (this != &src)
	{
		this->vec = src.getVector();
		*this = src;
	}
}
Span	&Span::operator=(Span const &src)
{
	this->vec = src.getVector();
	this->n = src.getSize();
	return (*this);
}

Span::~Span(void){}

void				Span::addNumber(int num)
{
	if (vec.size() < n)
		vec.push_back(num);
	else
		throw (StorageFullException());
}

void				Span::addNumbers(int size, int num)
{
	for (int i = 0; i < size; i++)
		try
		{
			addNumber(num);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			break ;
		}
}

unsigned			Span::getSize(void) const
{
	return (n);
}

std::vector<int>	Span::getVector(void) const
{
	return (vec);
}

int		Span::shortestSpan(void)
{
	if (vec.size() == 0 || vec.size() == 1)
		throw (SpanNotFoundException());
	int min = 2147483647;
	for (size_t i = 0; i < vec.size(); i++)
		for(size_t j = 0; j < vec.size(); j++)
			if (i != j && ABS(vec.at(i) - vec.at(j)) < min)
				min = ABS(vec.at(i) - vec.at(j));
	return (min);
}

int		Span::longestSpan(void)
{
	if (vec.size() == 0 || vec.size() == 1)
		throw (SpanNotFoundException());
	int max = 0;
	for (size_t i = 1; i < vec.size(); i++)
		for(size_t j = 0; j < vec.size(); j++)
			if (i != j && ABS(vec.at(i) - vec.at(j)) > max)
				max = ABS(vec.at(i) - vec.at(j));
	return (max);
}
