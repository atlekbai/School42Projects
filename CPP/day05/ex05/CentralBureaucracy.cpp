// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CentralBureaucracy.cpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 19:04:17 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 19:44:19 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{
	this->office = new OfficeBlock[20];
	for (int i = 0; i < 20; i++)
	{
		this->office[i] = OfficeBlock();
		this->office[i].setIntern(new Intern());
	}
}

CentralBureaucracy::~CentralBureaucracy(void)
{
	// delete (this->office);
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &src)
{
	for(int i = 0; i < 20; i++)
	{
		this->office[i].setIntern(src.getOffices()[i].getIntern());
		this->office[i].setSigner(src.getOffices()[i].getSigner());
		this->office[i].setExecutor(src.getOffices()[i].getExecutor());
	}
}

CentralBureaucracy  &CentralBureaucracy::operator=(CentralBureaucracy const &src)
{
	for(int i = 0; i < 20; i++)
	{
		this->office[i].setIntern(src.getOffices()[i].getIntern());
		this->office[i].setSigner(src.getOffices()[i].getSigner());
		this->office[i].setExecutor(src.getOffices()[i].getExecutor());
	}
	return (*this);
}

OfficeBlock			*CentralBureaucracy::getOffices(void) const
{
	return (this->office);
}

int					CentralBureaucracy::feedBureaucrat(Bureaucrat *bur)
{
	for (int i = 0; i < 20; i++)
		if (this->office[i].getSigner() == NULL)
		{
			this->office[i].setSigner(bur);
			break ;
		}
		else if (this->office[i].getExecutor() == NULL)
		{
			this->office[i].setExecutor(bur);
			break ;
		}
	return (1);
}
int					CentralBureaucracy::queueUp(std::string target)
{
	int i = -1;
	while (++i < 100)
		if (this->queue[i].empty())
			break;
	if (i == 100)
	{
		throw (TooLongQueueException());
		return (0);
	}
	this->queue[i] = target;
	return (1);
}

int					CentralBureaucracy::doBureaucracy(void)
{
	int j = 0;
	std::string forms[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation",
		"mutant pig termination",
		"salary improve request",
		"document giveaway",
		"passport producing"
	};
	for (int i = 0; i < 100; i++)
	{
		while (!this->office[(i + j) % 20].canWork())
			j++;
		try
		{
			this->office[(i + j) % 20].doBureaucracy(forms[rand() % 6], this->queue[i]);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		this->queue[i].clear();
		j = (j == 100) ? 0 : j;
		std::cout << "----------" << std::endl;
	}
	return (1);
}
