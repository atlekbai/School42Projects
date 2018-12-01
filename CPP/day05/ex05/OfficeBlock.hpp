// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 18:11:42 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 18:32:11 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OFFICE_BLOCK_HPP
# define OFFICE_BLOCK_HPP

# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock
{
private:
	Intern		*intern;
	Bureaucrat	*guy_to_sign;
	Bureaucrat	*guy_to_exec;
public:
	OfficeBlock(void);
	OfficeBlock(Intern *intern, Bureaucrat *guy_to_sign, Bureaucrat *guy_to_exec);
	~OfficeBlock(void);
	OfficeBlock(OfficeBlock const &src);
	OfficeBlock	&operator=(OfficeBlock const &src);
	Intern		*getIntern(void) const;
	Bureaucrat	*getSigner(void) const;
	Bureaucrat	*getExecutor(void) const;
	int			setIntern(Intern *intern);
	int			setSigner(Bureaucrat *guy_to_sign);
	int			setExecutor(Bureaucrat *guy_to_exec);
	bool		canWork(void);
	int			doBureaucracy(std::string form_name, std::string target);
	class OfficeBlockNotFilled: public std::exception
	{
		const char *what() const throw()
		{
			return ("Office block isn't filled");
		}
	};
	class EmployeeAbsent: public std::exception
	{
		const char *what() const throw()
		{
			return ("One of employee is absent");
		}
	};
};

#endif
