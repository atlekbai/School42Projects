// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 18:11:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 18:32:10 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) : intern(NULL), guy_to_sign(NULL), guy_to_exec(NULL){}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *guy_to_sign, Bureaucrat *guy_to_exec) : intern(intern), guy_to_sign(guy_to_sign), guy_to_exec(guy_to_exec)
{
	if (intern == NULL || guy_to_sign == NULL || guy_to_exec == NULL)
		throw EmployeeAbsent();
}

OfficeBlock::~OfficeBlock(void) {}

Intern		*OfficeBlock::getIntern(void) const
{
	return (this->intern);
}

Bureaucrat	*OfficeBlock::getSigner(void) const
{
	return (this->guy_to_sign);
}

Bureaucrat	*OfficeBlock::getExecutor(void) const
{
	return (this->guy_to_exec);
}

int			OfficeBlock::setIntern(Intern *intern)
{
	this->intern = intern;
	return (1);
}

int			OfficeBlock::setSigner(Bureaucrat *guy_to_sign)
{
	this->guy_to_sign = guy_to_sign;
	return (1);
}

int			OfficeBlock::setExecutor(Bureaucrat *guy_to_exec)
{
	this->guy_to_exec = guy_to_exec;
	return (1);
}

bool		OfficeBlock::canWork(void)
{
	if (this->intern == NULL || this->guy_to_sign == NULL || this->guy_to_exec == NULL)
		return (false);
	return (true);
}

int			OfficeBlock::doBureaucracy(std::string form_name, std::string target)
{
	if (!this->canWork())
	{
		throw OfficeBlockNotFilled();
		return (0);
	}
	Form *rf;
	rf = intern->makeForm(form_name, target);
	guy_to_sign->signForm(*rf);
	guy_to_exec->executeForm(*rf);
	delete (rf);
	return (1);
}

OfficeBlock::OfficeBlock(OfficeBlock const &src)
{
	*this = src;
}

OfficeBlock	&OfficeBlock::operator=(OfficeBlock const &src)
{
	this->intern = src.getIntern();
	this->guy_to_sign = src.getSigner();
	this->guy_to_exec = src.getExecutor();
	return (*this);
}
