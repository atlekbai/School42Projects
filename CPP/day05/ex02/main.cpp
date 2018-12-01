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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Ali", 60);
		ShrubberyCreationForm form("home");
		RobotomyRequestForm form1("work");
		PresidentialPardonForm form2("your family");
		a.signForm(form);
		a.signForm(form1);
		a.signForm(form2);
		a.executeForm(form);
		a.executeForm(form1);
		a.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat l("Lesha", 12);
		ShrubberyCreationForm form("home");
		RobotomyRequestForm form1("work");
		PresidentialPardonForm form2("your family");
		l.executeForm(form);
		l.executeForm(form1);
		l.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
