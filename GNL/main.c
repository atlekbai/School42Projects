// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/13 12:25:35 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/13 12:27:40 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char *line;
	int fd = open(av[1], O_RDONLY);

	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
