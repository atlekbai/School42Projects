// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/26 17:44:43 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/26 17:45:43 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>

struct Data
{
	Data(std::string s1, std::string s2, int n):s1(s1), s2(s2), n(n){}
	std::string	s1;
	std::string	s2;
	int			n;
};

#endif
