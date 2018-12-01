// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 16:47:05 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 16:55:05 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
	std::string	target;
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);

	std::string				getTarget(void) const;
	int						action(void) const;
};

#endif
