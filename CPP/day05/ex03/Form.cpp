// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 14:45:23 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 16:16:55 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Form.hpp"

Form::Form(std::string name, unsigned grade_sign, unsigned grade_exec) : name(name),
																		 grade_sign(grade_sign),
																		 grade_exec(grade_exec),
																		 sign(false)
{
	if (grade_sign > 150 || grade_exec > 150) throw Form::GradeTooLowException();
	if (grade_sign < 1 || grade_exec < 1) throw Form::GradeTooHighException();
	
}
Form::Form(Form const &src) : grade_sign(src.getGradeSign()),
							  grade_exec(src.getGradeExec())
{
	if (this != &src)
		*this = src;
}

Form::~Form(void){}

Form            &Form::operator=(Form const &src)
{
	this->sign = src.getSigned();
	return (*this);
}

std::string const	Form::getName(void) const
{
	return (this->name);
}

unsigned        Form::getGradeSign(void) const
{
	return (this->grade_sign);
}

unsigned        Form::getGradeExec(void) const
{
	return (this->grade_exec);
}

bool            Form::getSigned(void) const
{
	return (this->sign);
}

int             Form::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() > this->grade_sign)
		throw Form::GradeTooHighException();
	this->sign = true;
	return (1);
}

int				Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->grade_sign)
		throw Form::GradeTooHighException();
	action();
	return (1);
}

std::ostream &operator<<(std::ostream &o, Form const &f)
{
	o << "Form " << f.getName() << ": grade to sign [" << f.getGradeSign() << "], grade to execute [" << f.getGradeExec() << "], signed: " << (f.getSigned() ? "yes" : "no");
	return (o);
}
