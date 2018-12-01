// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/20 17:06:54 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/20 17:13:01 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.class.hpp"

int	eval_expr(const std::string& expr, std::string::const_iterator i, std::string::const_iterator j)
{
	int op = 0;
	std::string::const_iterator end_i;
	std::string::const_iterator begin_j;
	char operation;
	int	first;
	int	second;

	while (*i == 32)
		++i;
	while (*j == 32)
		--j;
	if (i == j)
		return (*i - 48);
	end_i = i;
	while (op > 0 || (*end_i != '+' && *end_i != '-' && *end_i != '*' && *end_i != '/'))
	{
		if (*end_i == '(')
			++op;
		else if (*end_i == ')')
			--op;
		++end_i;
	}
	operation = *end_i;
	begin_j = end_i;
	++begin_j;
	--end_i;
	first = eval_expr(expr, i, end_i);
	if (operation == '*' || operation == '/')
	{
		if (first == 0)
			return (0);
		else
		{
			second = eval_expr(expr, begin_j, j);
			if (operation == '*')
				return (first * second);
			else if (operation == '/')
				return (first / second);
		}
	}
	else
	{
		second = eval_expr(expr, begin_j, j);
		if (operation == '+')
			return (first + second);
		else if (operation == '-')
			return (first - second);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string expr(av[1]);
		std::string::const_iterator i;
		std::string::const_iterator j;

		i = expr.begin();
		j = expr.end() - 1;
		std::cout << eval_expr(expr, i, j) << std::endl;
	}
	else
		std::cout << "Usage:./eval_expr <mathematical expression>" << std::endl;
	return (1);
}
