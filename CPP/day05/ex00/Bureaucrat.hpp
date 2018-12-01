// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 14:17:36 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 14:43:30 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
	const std::string	name;
	unsigned			grade;

public:
	Bureaucrat(const std::string name, unsigned grade);
	~Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &src);

	std::string const	getName(void) const;
	unsigned			getGrade(void) const;
	int					decrementGrade(void);
	int					incrementGrade(void);

	class	GradeTooLowException: public std::exception
	{
		const char	*what() const throw()
			{
				return ("Grade too low.");
			}
	};

	class	GradeTooHighException: public std::exception
	{
		const char	*what() const throw()
			{
				return ("Grade too high.");
			}
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b);

#endif
