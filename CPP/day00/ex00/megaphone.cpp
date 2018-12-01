// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/18 12:56:29 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/18 13:09:38 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

void	to_upper(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			std::cout << (char)(str[i] - 32);
		else
			std::cout << str[i];
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		while (*(++av))
			to_upper(*av);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"  << std::endl;
	return (0);
}
