// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   expr_valid.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/29 12:20:25 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/29 12:20:26 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sstream>

int		brclose(char *str, char c, int i, int b)
{
	while (b && *(++str) && (i++))
		if (*str == c || *str == c + c % 2 + 1)
			(*str == c) ? ++b : --b;
	return (i);
}

int		brackets(char *str, char c)
{
	if (*str == c)
		return (1);
	else if (!*str || *str == ')' || *str == '}' || *str == ']')
		return (0);
	else if (*str == '(' || *str == '{' || *str == '[')
		return (brackets(str + 1, *str + *str % 2 + 1) *
				brackets(str + brclose(str, *str, 1, 1), c));
	else
		return (brackets(str + 1, c));
}

bool	isoper(char c)
{
	char const ops[] = {'+', '-', '/', '*', '(', ')', '{', '}', '[', ']'};
	for (int j = 0; j < 9; j++)
		if (c == ops[j])
			return (true);
	return (false);
}

bool	check_expr(char *expr)
{
	if (!brackets(expr, 0))
		return (false);
	while (*expr)
	{
		if (!(isoper(*expr) || std::isdigit(*expr) || *expr == 32))
			return (false);
		expr++;
	}
	return (true);
}

int		oper_prior(char c)
{
	if (c == '*' || c == '/')
		return (2);
	else if (c == '+' || c == '-')
		return (1);
	return (0);
}

int		toInt(std::string str)
{
	int num;
	std::stringstream ss(str);
	ss >> num;
	return (num);
}