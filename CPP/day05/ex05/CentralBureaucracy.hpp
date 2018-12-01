// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CentralBureaucracy.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/25 19:04:20 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/25 19:39:00 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CENTRAL_BUREAUCRACY
# define CENTRAL_BUREAUCRACY

# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "OfficeBlock.hpp"
# include "Form.hpp"

class CentralBureaucracy
{
private:
	std::string	queue[100];
	OfficeBlock *office;
public:
	CentralBureaucracy(void);
	~CentralBureaucracy(void);
	CentralBureaucracy(CentralBureaucracy const &src);
	CentralBureaucracy	&operator=(CentralBureaucracy const &src);
	OfficeBlock			*getOffices(void) const;
	int					feedBureaucrat(Bureaucrat *bur);
	int					queueUp(std::string target);
	int					doBureaucracy(void);
	class TooLongQueueException: public std::exception
	{
		const char *what() const throw()
			{
				return ("Please wait outside, queue is too long");
			}
	};
	class EmptyQueueException: public std::exception
	{
		const char *what() const throw()
			{
				return ("Empty Queue");
			}
	};
};

#endif
