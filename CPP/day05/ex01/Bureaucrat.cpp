// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 14:17:32 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 15:57:39 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string name, unsigned grade) : name(name)
{
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}
Bureaucrat::~Bureaucrat(void){}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	if (this != &src)
		*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	this->grade = src.getGrade();
	return (*this);
}

std::string const	Bureaucrat::getName(void) const
{
	return (this->name);
}

unsigned			Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

int					Bureaucrat::decrementGrade(void)
{
	if (this->grade + 1 > 150) throw Bureaucrat::GradeTooLowException();
	this->grade++;
	return (1);
}
int					Bureaucrat::incrementGrade(void)
{
	if (this->grade - 1 < 1) throw Bureaucrat::GradeTooHighException();
	this->grade--;
	return (1);
}

int					Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
	return (1);
}

std::ostream		&operator<<(std::ostream &o, Bureaucrat const &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}
