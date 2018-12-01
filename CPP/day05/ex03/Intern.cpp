// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 17:46:17 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 17:59:55 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Intern.hpp"

Intern::Intern(void):form_name("Empty"), target("Empty"){}
Intern::~Intern(void){}
Intern::Intern(Intern const &src):form_name(src.getFormName()),
								  target(src.getTarget()){}

Intern		&Intern::operator=(Intern const &src)
{
	this->form_name = src.getFormName();
	this->target = src.getTarget();
	return (*this);
}

Form		*Intern::makeForm(std::string form_name, std::string target)
{
	if (form_name == "robotomy request" || form_name == "presidential pardon" || form_name == "shrubbery creation")
		std::cout << "Intern creates " << form_name << std::endl;
	if (form_name == "robotomy request")
		return (new RobotomyRequestForm(target));
	else if (form_name == "presidential pardon")
		return (new PresidentialPardonForm(target));
	else if (form_name == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	return (NULL);
}

std::string	Intern::getFormName(void) const
{
	return (this->form_name);
}

std::string	Intern::getTarget(void) const
{
	return (this->target);
}
