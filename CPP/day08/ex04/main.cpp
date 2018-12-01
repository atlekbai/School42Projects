// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/29 11:38:44 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/29 11:56:50 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "header.hpp"

std::vector<std::string>	to_postfix(char *expr)
{
	std::vector<std::string> 	stack;
	std::vector<std::string> 	temp;
	std::string					num;
	std::string					op;

	while(*expr)
	{
		if (isoper(*expr))
		{
			if (*expr == ')')
			{
				while ((op = pop(temp)) != "(")
					stack.push_back(op);
				op.clear();
			}
			else if (!temp.empty() && oper_prior(*expr) <= oper_prior(temp.back()[0]) && *expr != '(')
			{
				stack.push_back(pop(temp));
				op = *expr;
				temp.push_back(op);
			}
			else
			{
				op = *expr;
				temp.push_back(op);
			}
		}
		else if (std::isdigit(*expr))
		{
			while (std::isdigit(*expr))
				num += *expr++;
			stack.push_back(num);
			num.clear();
			continue ;
		}
		expr++;
	}
	while (!temp.empty())
		stack.push_back(pop(temp));
	return (stack);
}

void		rpn(char *expr)
{
	if (!check_expr(expr))
	{
		std::cout << "Invalid expression" << std::endl;
		return ;
	}
	std::vector<std::string> 	postfix = to_postfix(expr);
	if (!check_postfix(postfix))
	{
		std::cout << "Invalid expression" << std::endl;
		return ;
	}
	std::vector<int>		 	stack;
	int							a = 0;
	int							b = 0;

	read_tokens(expr, std::strlen(expr));
	read_tokens(postfix);
	for(size_t i = 0; i < postfix.size(); i++)
	{
		if (std::isdigit(postfix[i][0]))
		{
			stack.push_back(toInt(postfix[i]));
			std::cout << "I Num("<< postfix[i] << ") | OP Push\t| ST ";
			print_vect(stack);
		}
		else if (isoper(postfix[i][0]))
		{
			a = pop(stack);
			b = pop(stack);
			std::cout << "I OP(" << postfix[i] << ")  | OP ";
			if (postfix[i] == "+")
			{
				stack.push_back(a + b); 
				std::cout << "Add\t| ST ";
			}
			else if (postfix[i] == "*")
			{
				stack.push_back(b * a);
				std::cout << "Multiply\t| ST ";
			}
			else if (postfix[i] == "/")
			{
				stack.push_back(b / a);
				std::cout << "Divide\t| ST ";
			}
			else if (postfix[i] == "-")
			{
				stack.push_back(b - a);
				std::cout << "Substract\t| ST ";
			}
			print_vect(stack);
		}
	}
	std::cout << "Result : " << stack.back() << std::endl;
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rpn(av[1]);
	else
		std::cout << "Usage:./rpn <expression>" << std::endl;
	return (0);
}
