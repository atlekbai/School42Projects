// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.cpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 16:41:53 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 17:08:25 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):Form("RobotomyRequestForm", 72, 45)
{
	if (this != &src)
		*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	this->target = src.getTarget();
	return (*this);
}

std::string         RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

int					RobotomyRequestForm::action(void) const
{
	std::cout << "* makes some drilling noises *" << std::endl;
	if ((rand() % 1) % 2 == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " has failed on robotimizing" << std::endl;
	return (1);
}
