// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/28 15:29:22 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/28 15:29:22 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# define ABS(x) ((x) < 0 ? (-(x)) : (x))

class Span
{
private:
	std::vector<int>	vec;
	unsigned			n;
public:
	Span(void);
	Span(unsigned n);
	Span(Span const &src);
	Span				&operator=(Span const &src);
	~Span(void);
	void				addNumber(int num);
	void				addNumbers(int size, int num);
	int					shortestSpan(void);
	int					longestSpan(void);
	unsigned			getSize(void) const;
	std::vector<int>	getVector(void) const;
	class StorageFullException:public std::exception
	{
		const char *what() const throw()
		{
			return ("Storage is Full");
		}
	};
	class SpanNotFoundException: public std::exception
	{
		const char *what() const throw()
		{
			return ("Span cannot be found");
		}
	};
};

#endif