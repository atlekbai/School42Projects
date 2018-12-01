// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   header.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/18 17:24:25 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/18 17:24:26 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HEADER_HPP
# define HEADER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.class.hpp"

#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"
#define MAX_CONTACTS 8
#define TABLE_WIDTH 10

int	ft_exit(void);
int	ft_search(Contact contacts[], int i);
int	ft_add(Contact contacts[], int &i);

#endif