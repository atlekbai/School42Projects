// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.hpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 16:41:55 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 17:07:46 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

# include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	std::string	target;
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
	std::string			getTarget(void) const;
	int					action(void) const;
};

#endif
