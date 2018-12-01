// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   vector_ops.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/29 16:15:13 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/29 16:15:14 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "header.hpp"

void		read_tokens(char *expr, int size)
{
	int			i = 0;
	std::string	num;

	std::cout << "Tokens: ";
	while (i < size)
	{
		if (isoper(expr[i]))
		{
			if (expr[i] == '(')
				std::cout << "ParOpen";
			else if (expr[i] == ')')
				std::cout << "ParClose";
			else
				std::cout << "Op(" << expr[i] << ")";
			std::cout << " ";
		}
		else if (std::isdigit(expr[i]))
		{
			while (std::isdigit(expr[i]))
				num += expr[i++];
			std::cout << "Num(" << num << ") ";
			num.clear();
			continue ;
		}
		i++;
	}
	std::cout << std::endl;
}

void		read_tokens(std::vector<std::string> expr)
{
	int			i = -1;
	std::string	num;

	std::cout << "Tokens: ";
	while (++i < static_cast<int>(expr.size()))
		if (isoper(expr[i][0]))
		{
			if (expr[i] == "(")
				std::cout << "ParOpen";
			else if (expr[i] == ")")
				std::cout << "ParClose";
			else
				std::cout << "Op(" << expr[i] << ")";
			std::cout << " ";
		}
		else if (std::isdigit(expr[i][0]))
		{
			std::cout << "Num(" << expr[i] << ") ";
		}
	std::cout << std::endl;
}

bool		check_postfix(std::vector<std::string> expr)
{
	int nums = 0;
	int ops = 0;
	int	i = -1;

	while (++i < static_cast<int>(expr.size()))
		if (isoper(expr[i][0]))
			ops++;
		else if (std::isdigit(expr[i][0]))
			nums++;
	if (nums - 1 == ops)
		return (true);
	return (false);
}
