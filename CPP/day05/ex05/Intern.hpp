// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 17:46:25 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 17:58:59 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	std::string	form_name;
	std::string target;
public:
	Intern(void);
	~Intern(void);
	Intern(Intern const &src);
	Intern		&operator=(Intern const &src);
	Form		*makeForm(std::string form_name, std::string target);
	std::string	getFormName(void) const;
	std::string	getTarget(void) const;
	class UnknownFormName: public std::exception
	{
		const char *what() const throw()
		{
			return ("Unknown Form Name from Intern");
		}
	};
};

#endif
