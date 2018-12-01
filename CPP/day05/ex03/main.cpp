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

int	main(void)
{
	try
	{
		Bureaucrat	lesha("Lesha", 56);
		Intern		ali;
		Form		*rrf;

		rrf = ali.makeForm("robotomy request", "Bender");
		lesha.signForm(*rrf);
		lesha.executeForm(*rrf);
		rrf = ali.makeForm("presidential pardon", "John Snow");
		lesha.signForm(*rrf);
		lesha.executeForm(*rrf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
