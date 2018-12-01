// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.cpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 16:42:01 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 16:42:02 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):Form("PresidentialPardonForm", 25, 5),
																	target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):Form("PresidentialPardonForm", 25, 5)
{
	if (this != &src)
		*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	this->target = src.getTarget();
	return (*this);
}

std::string         PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

int					PresidentialPardonForm::action(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (1);
}
