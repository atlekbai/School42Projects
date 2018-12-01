// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 14:17:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 18:02:08 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int	main(void)
{
	std::string forms[] = {"robotomy request", "presidential pardon", "shrubbery creation", "cats", "WTF"};
	Intern      idiotOne;
    Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 26);
    Bureaucrat  bob = Bureaucrat("Bobby Bobson", 4);
    OfficeBlock ob;
    ob.setIntern(&idiotOne);
    ob.setSigner(&bob);
    ob.setExecutor(&hermes);
    for (int i = 0; i < 5; i++)
    {
		try
		{
			ob.doBureaucracy(forms[i], "Pigley");
		}
		catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		std::cout << "-------------" << std::endl;
	}
	return (0);
}
