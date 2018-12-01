// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.hpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 16:42:05 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 16:42:05 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP

# include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	std::string	target;
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);

	std::string				getTarget(void) const;
	int						action(void) const;
};

#endif
