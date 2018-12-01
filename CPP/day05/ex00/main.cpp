// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 14:17:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 14:44:13 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Ali", 3);
		Bureaucrat b("Lesha", 0);
		Bureaucrat c("Hnat", 150);
		a.incrementGrade();
		a.incrementGrade();
		//c.decrementGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
