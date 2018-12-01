// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TextMode.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/01 15:54:39 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/01 15:54:39 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TextMode.hpp"

TextMode::TextMode(void)
{
	startx = 0;
	starty = 0;
	height = 3;
	k = 0;
}
TextMode::~TextMode(void){}

WINDOW *TextMode::create_newwin(int height, int width, int starty, int startx, const char *str)
{
	WINDOW* tmp;
	tmp = newwin(height, width, starty, startx);
	mvwprintw(tmp, 1, 1, "%s", str);
	box(tmp, 0, 0);
	wrefresh(tmp);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(4, COLOR_RED, COLOR_RED);
	init_pair(5, COLOR_BLUE, COLOR_BLUE);
	init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(7, COLOR_CYAN, COLOR_CYAN);
	return (tmp);
}

void	TextMode::refresh_time(WINDOW *win)
{
	std::string time = item.getTime();
	mvwprintw(win, 1, 1, "%s", time.c_str());
	box(win, 0, 0);
	wrefresh(win);
}

void	TextMode::refresh_net(WINDOW *win)
{
	int in = item.getNetIn();
	int out = item.getNetOut();
	mvwprintw(win, 1, 1, "Packages received: %d\n Packages sent:     %d", in, out);
	box(win, 0, 0);
	wrefresh(win);
}

void	TextMode::refresh_name(WINDOW *win)
{
	char const *hostname = item.getHostname().c_str();
	char const *name = item.getUser().c_str();
	mvwprintw(win, 1, 1, "%s", hostname);
	mvwprintw(win, 1, strlen(hostname), " / %s", name);
	box(win, 0, 0);
	wrefresh(win);
}

void	TextMode::update_cpu(WINDOW *win, int height, int width)
{
	int cpu = item.getCPU_pro();
	cpu_vec.push_back(cpu);
	int a = 0;
	int size = cpu_vec.size();

	werase(win);
	mvwprintw(win, height - 2, 1, "%s", item.getCPU().c_str());
	mvwprintw(win, height - 2, width - 9, "CPU %d%%", cpu);
	box(win, 0, 0);
	for (int i = (size < width ? 0 : size - width);
			i < (size >= width ? size - 2 : size); i++)
	{
		for (int j = 0; j < (height * cpu_vec[i]) / 100; j++)
		{
			if (height - j - 3 <= ((height * cpu_vec[i]) / 100) / 4 + 3)
			{
				wattron(win, COLOR_PAIR(4));
					mvwaddch(win, height - j - 3, a + 1, '#');
				wattroff(win, COLOR_PAIR(4));
			}
			else if (height - j - 3 <= ((height * cpu_vec[i]) / 100) / 2 + 6)
			{
				wattron(win, COLOR_PAIR(3));
					mvwaddch(win, height - j - 3, a + 1, '#');
				wattroff(win, COLOR_PAIR(3));
			}
			else
			{
				wattron(win, COLOR_PAIR(2));
					mvwaddch(win, height - j - 3, a + 1, '#');
				wattroff(win, COLOR_PAIR(2));
			}
		}
		a++;
	}
	wrefresh(win);
}

void	TextMode::update_ram(WINDOW *win, int height, int width)
{
	ram_vec.push_back(item.getRAM());
	int a = 0;
	int size = ram_vec.size();

	werase(win);
	mvwprintw(win, height - 2, width - 10, "RAM %d", item.getRAM());
	box(win, 0, 0);
	for (int i = (size < width ? 0 : size - width);
			i < (size >= width ? size - 2 : size); i++)
	{
		for (int j = 0; j < (ram_vec[i] % (height - 2)); j++)
		{
			if (height - j - 3 <= ram_vec[i] % height / 4 + 3)
			{
				wattron(win, COLOR_PAIR(5));
					mvwaddch(win, height - j - 3, a + 1, '#');
				wattroff(win, COLOR_PAIR(5));
			}
			else if (height - j - 3 <= ram_vec[i] % height / 2 + 3)
			{
				wattron(win, COLOR_PAIR(6));
					mvwaddch(win, height - j - 3, a + 1, '#');
				wattroff(win, COLOR_PAIR(6));
			}
			else
			{
				wattron(win, COLOR_PAIR(7));
					mvwaddch(win, height - j - 3, a + 1, '#');
				wattroff(win, COLOR_PAIR(7));
			}
		}
		a++;
	}
	wrefresh(win);
}

void	TextMode::display(void)
{
	initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	name = this->create_newwin(height, COLS, starty, startx, "NAME");

	std::string system_info = item.getOs();
	system_info.replace(system_info.find("\n"), 1, "\n ");
	system_info.replace(system_info.find("\nB"), 1, "\n ");
	system = this->create_newwin(height + 2, COLS, starty += 3, startx, system_info.c_str());
	
	time = this->create_newwin(height, COLS, starty += 5, startx, "TIME");
	cpu = this->create_newwin(height * 4, COLS, starty += 3, startx, "CPU");
	ram = this->create_newwin(height * 4, COLS, starty += 12, startx, "PROC");
	net = this->create_newwin(height + 1, COLS, starty += 12, startx, "NET");

	while (1)
	{
		this->refresh_time(time);
		this->refresh_net(net);
		this->refresh_name(name);
		this->update_cpu(cpu, height * 4, COLS);
		this->update_ram(ram, height * 4, COLS);
		usleep(10000);
		k++;
	}

	endwin();
}

WINDOW*	TextMode::GetI(void){
	return (name);
}

TextMode::TextMode		(TextMode & src){
	*this = src;
}
	TextMode const & TextMode::operator=(TextMode & rhs){
		name = rhs.GetI();
		return (*this);
}
