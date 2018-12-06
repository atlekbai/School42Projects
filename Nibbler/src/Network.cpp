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
	int	s;
	int	cs;

	s = socket(AF_INET, SOCK_STREAM, 0);
	inet_aton("127.0.0.1", &local.sin_addr);
	local.sin_family = AF_INET;
	local.sin_port = htons(4000);

	bind(s, (struct sockaddr*)&local, sizeof(local));
	listen(s, 5);

	std::cout << "-- server --" << std::endl;
	std::cout << "waiting for connection..." << std::endl;
	cs = accept(s, NULL, NULL);
	std::cout << "connected" << std::endl;
	std::cout << "------------" << std::endl;
	return (cs);
}

int		Network::clientConnect(void)
{
	int	res;
	int	cs;

	cs = socket(AF_INET, SOCK_STREAM, 0);
	inet_aton("127.0.0.1", &local.sin_addr);
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
