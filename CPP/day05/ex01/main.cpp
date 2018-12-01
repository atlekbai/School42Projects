// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 14:17:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 16:13:31 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Ali", 4);
		Form form("Resignation", 4, 6);
		Form form1("Happiness Contract", 20, 6);
		a.signForm(form);
		a.signForm(form1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Lesha", 14);
		Form form3("Independence declaration", 4, 6);
		Form form4("UNIT Contract", 20, 6);
		b.signForm(form3);
		b.signForm(form4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form form5("Resignation", 0, 6);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form form6("Resignation", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return (0);
}
