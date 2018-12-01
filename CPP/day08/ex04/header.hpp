// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   header.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/29 11:38:55 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/29 11:39:21 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <vector>
# include <iomanip>

int		brclose(char *str, char c, int i, int b);
int		brackets(char *str, char c);
bool	isoper(char c);
bool	check_expr(char *expr);
int		oper_prior(char c);
void	read_tokens(char *expr, int size);
void	read_tokens(std::vector<std::string> expr);
int		toInt(std::string str);
bool	check_postfix(std::vector<std::string> expr);

template<typename T>
void	print_vect(std::vector<T> v)
{
	std::cout << "[";
	for(size_t i = 0; i < v.size();i++)
	{
		std::cout << v.at(i);
		if (i + 1 != v.size())
			std::cout << " ";
	}
	std::cout << "]" << std::endl;
}

template<typename T>
T		pop(std::vector<T> &vec)
{
	T	tmp;

	tmp = vec.back();
	vec.pop_back();
	return (tmp);
}

#endif
