// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Network.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/05 16:48:01 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/05 16:48:01 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Network.hpp"
#include "Game.hpp"

int		Network::serverLoad(void)
{
	struct addrinfo hints, *servinfo, *p;
	int	yes = 1;
	int	sockFd;
	int	cs;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	getaddrinfo(NULL, "4000", &hints, &servinfo);
	for (p = servinfo; p != NULL; p = p->ai_next)
	{
		if ((sockFd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
			continue ;
		if (setsockopt(sockFd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
			exit(1);
		if (bind(sockFd, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(sockFd);
			continue ;
		}
		break ;
	}

	if (p == NULL)
	{
		std::cout << "server fail" << std::endl;
		exit(1);
	}
	freeaddrinfo(servinfo);
	inet_aton("10.111.7.10", &local.sin_addr);
	local.sin_family = AF_INET;
	local.sin_port = htons(4000);

	bind(sockFd, (struct sockaddr*)&local, sizeof(local));
	listen(sockFd, 5);

	std::cout << "-- server --" << std::endl;
	std::cout << "waiting for connection..." << std::endl;
	cs = accept(sockFd, NULL, NULL);
	std::cout << "connected" << std::endl;
	std::cout << "------------" << std::endl;
	return (cs);
}

int		Network::clientConnect(std::string ip)
{
	int	res;
	int	cs;

	cs = socket(AF_INET, SOCK_STREAM, 0);
	inet_aton(ip.c_str(), &local.sin_addr);
	local.sin_port = htons(4000);
	local.sin_family = AF_INET;
	res = connect(cs, (struct sockaddr*)&local, sizeof(local));
	if (res == -1)
	{
		std::cout << "connection failed" << std::endl;
		Game::state = 3;
	}
	return (cs);
}
