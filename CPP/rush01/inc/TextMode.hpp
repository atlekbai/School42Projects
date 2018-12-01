// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TextMode.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/01 15:54:35 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/01 15:54:35 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TEXTMODE_HPP
# define TEXTMODE_HPP

# include <iostream>
# include <ncurses.h>
# include <unistd.h>
# include <vector>
# include "Hostname.hpp"
# include "IMonitorDisplay.hpp"

class TextMode : public IMonitorDisplay
{
private:
	Hostname			item;
	WINDOW				*name;
	WINDOW				*system;
	WINDOW				*time;
	WINDOW				*cpu;
	WINDOW				*ram;
	WINDOW				*net;
	int					startx;
	int					starty;
	int					height;
	int					k;
	std::vector<int>	cpu_vec;
	std::vector<int> 	ram_vec;
	TextMode		(TextMode & src);
	TextMode const & operator=(TextMode & rhs);

public:
	TextMode(void);
	~TextMode(void);
	WINDOW *create_newwin(int height, int width, int starty, int startx, const char *str);
	void	refresh_time(WINDOW *win);
	void	refresh_net(WINDOW *win);
	void	refresh_name(WINDOW *win);
	void	update_cpu(WINDOW *win, int height, int width);
	void	update_ram(WINDOW *win, int height, int width);
	void	display(void);
	WINDOW*	GetI(void);
};

#endif