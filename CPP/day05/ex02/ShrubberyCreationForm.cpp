// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 16:41:45 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 16:58:25 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):Form("ShrubberyCreationForm", 145, 137)
{
	if (this != &src)
		*this = src;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	this->target = src.getTarget();
	return (*this);
}

std::string             ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

int						ShrubberyCreationForm::action(void) const
{
	std::string		name = this->target + "_shrubbery";
	std::ofstream	ofs(name);
	ofs << "               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888|88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88|88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888|88888'\n\
   %&&%/ %&%%&&@@\'' V /@@' `88|8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	ofs.close(); 
	return (1);
}
