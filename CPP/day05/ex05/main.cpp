// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 14:17:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 18:02:08 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int	main(void)
{
	std::string names[] = {
		"Jacinda",
		"Sontag",
		"Randi",
		"Brandes",
		"Stephan",
		"Urbina",
		"Valarie",
		"Tom",
		"Nathanael"
		"Beeson",
		"Rueben",
		"Deforge",
		"Lala",
		"Hartnett",
		"Many",
		"Alejo",
		"Zella"
	};
	std::string last[] = 
	{
		"Liam",
		"Noah",
		"William",
		"James",
		"Logan",
		"Benjamin",
		"Mason",
		"Elijah",
		"Oliver",
		"Jacob",
		"Lucas",
		"Michael",
		"Alexander",
		"Ethan",
		"Daniel",
		"Matthew",
		"Aiden",
		"Henry",
		"Joseph"
	};
	CentralBureaucracy centre;
	Bureaucrat** burs = new Bureaucrat*[40];
	for (int i = 0; i < 40; i++)
	{
		try
		{
			burs[i] = new Bureaucrat(names[rand() % 16] + last[rand() % 18], rand() % 150);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	for (int i = 0; i < 40; i++)
		centre.feedBureaucrat(burs[i]);
	for (int i = 0; i < 100; i++)
	{
		try
		{
			centre.queueUp(names[rand() % 16] + last[rand() % 18]);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	try
	{
		centre.doBureaucracy();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
