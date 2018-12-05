// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Network.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/05 16:47:54 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/05 16:47:54 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NETWORK_HPP
# define NETWORK_HPP

#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

class Network
{
private:
	struct sockaddr_in	local;
	char				buf[1];
public:
	Network(void){}
	~Network(void){}
	int		serverLoad(void);
	int		clientConnect(void);
	void	sendNet(int command, int s);
	int		recvNet(int s);
};

#endif
