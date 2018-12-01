// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 14:45:26 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 16:17:03 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	const unsigned		grade_sign;
	const unsigned		grade_exec;
	bool				sign;
public:
	Form(std::string name, unsigned grade_sign, unsigned grade_exec);
	Form(Form const &src);
	~Form(void);
	Form			&operator=(Form const &src);
	std::string const 	getName(void) const;
	unsigned		getGradeSign(void) const;
	unsigned		getGradeExec(void) const;
	bool			getSigned(void) const;
	int				beSigned(Bureaucrat bur);
	class GradeTooHighException: public std::exception
	{
		const char *what() const throw()
		{
			return ("Form grade too high.");
		}
	};
	class GradeTooLowException: public std::exception
	{
		const char *what() const throw()
		{
			return ("Form grade too low.");
		}
	};
};

std::ostream &operator<<(std::ostream &o, Form const &f);

#endif
