// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ncurses_funcs.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 22:15:52 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 22:15:52 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "game.hpp"

int renderPlayer(int frame, WINDOW *win, Player &player)
{
	wattron(win, A_BOLD);
	mvwaddch(win, player.pos.y, player.pos.x, player.getDispChar());
	wattroff(win, A_BOLD);
	wattron(win, A_ALTCHARSET);
	mvwaddch(win, player.pos.y, player.pos.x - 1, ACS_ULCORNER);
	mvwaddch(win, player.pos.y, player.pos.x + 1, ACS_URCORNER);
	mvwaddch(win, player.pos.y + 1, player.pos.x - 1, ACS_LRCORNER);
	mvwaddch(win, player.pos.y + 1, player.pos.x + 1, ACS_LLCORNER);
	if ((frame % 10) / 3)
	{
		wattron(win, COLOR_PAIR(frame % 2 ? 1 : 2));
		mvwaddch(win, player.pos.y + 1, player.pos.x, ACS_UARROW);
		wattroff(win, COLOR_PAIR(frame % 2 ? 1 : 2));
	}
	wattroff(win, A_ALTCHARSET);
	return (1);
}

int  display(SpaceThing **obj, int n, WINDOW *win, char c)
{
	for (int i = 0; i < n; i++)
		if (obj[i])	
			mvwaddch(win, obj[i]->pos.y, obj[i]->pos.x, c);
	return (1);
}

int  display(Bullet **obj, int n, WINDOW *win, char c)
{
	for (int i = 0; i < n; i++)
		if (obj[i])
		{
			wattron(win, COLOR_PAIR(3));
			mvwaddch(win, obj[i]->pos.y, obj[i]->pos.x, c);
			wattroff(win, COLOR_PAIR(3));
		}
	return (1);
}

int  actionObject(ThingGroup &field, int n, char c, int frame, WINDOW *win)
{
	if (frame % n == 0)
		field.update();
	display(field.getData(), field.getN(), win, c);
	return (1);
}

int init(WINDOW **main_window, WINDOW **game_window, Rect &screen_s, Rect &game_s)
{
	srand(time(NULL));
	*main_window = initscr();
	screen_s = Rect(0, 0, getmaxx(*main_window), getmaxy(*main_window));
	cbreak();
	noecho();
	clear();
	refresh();
	curs_set(0);
	start_color();
	*game_window = newwin(screen_s.height() - 2,
						screen_s.width() - 40,
						screen_s.top() + 1,
						screen_s.left() + 1);
	*main_window = newwin(screen_s.height(), screen_s.width(), 0, 0);
	game_s = Rect(0, 0, screen_s.width() - 40, screen_s.height() - 2);

	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	keypad(*main_window, true);
	keypad(*game_window, true);
	nodelay(*main_window, true);
	nodelay(*game_window, true);
	return (0);
}

int stopGame(char const *text, WINDOW *win)
{
	system("afplay death.wav&");
	while(1)
	{
		int x;
		int y;
		getmaxyx(win, y, x);
		mvwprintw(win, y / 2, (x - strlen(text)) / 2, "%s", text);
		mvwprintw(win, y / 2 + 1, (x - strlen(text)) / 2, "Press \"r\" for restart");
		mvwprintw(win, y / 2 + 2, (x - strlen(text)) / 2, "Press \"e\" for exit");
		char input_ch = wgetch(win);
		input_ch = tolower(input_ch);
		if (input_ch == 'r')
		{
			system("./ft_retro");
			exit(0);
		}
		if (input_ch == 'e')
		{
			endwin();
			exit(0);
		}
	}
}

int renderEnemy(int frame, WINDOW *win, Enemy &enemy)
{
	wattron(win, COLOR_PAIR(4));
	mvwaddch(win, enemy.pos.y, enemy.pos.x, enemy.getDispChar());
	wattroff(win, COLOR_PAIR(4));
	wattron(win, COLOR_PAIR(3));
	mvwaddch(win, enemy.pos.y, enemy.pos.x - 2, ACS_LARROW);
	mvwaddch(win, enemy.pos.y, enemy.pos.x - 1, ACS_LARROW);
	mvwaddch(win, enemy.pos.y, enemy.pos.x + 1, ACS_RARROW);
	mvwaddch(win, enemy.pos.y, enemy.pos.x + 2, ACS_RARROW);
	if ((frame % 10) / 3)
	{
		wattron(win, COLOR_PAIR(frame % 2 ? 3 : 4));
		mvwaddch(win, enemy.pos.y - 1, enemy.pos.x, ACS_DARROW);
		wattroff(win, COLOR_PAIR(frame % 2 ? 3 : 4));
	}
	wattroff(win, COLOR_PAIR(3));
	return (1);
}

int renderBoss(int frame, WINDOW *win, Boss &boss)
{
	mvwprintw(win, boss.pos.y - 3, boss.pos.x - 3, "%d HP", boss.getHP());
	wattron(win, COLOR_PAIR(4));
	mvwaddch(win, boss.pos.y, boss.pos.x, boss.getDispChar());
	wattroff(win, COLOR_PAIR(4));
	wattron(win, COLOR_PAIR(3));
	mvwaddch(win, boss.pos.y - 1, boss.pos.x + 1, 'U');
	mvwaddch(win, boss.pos.y - 1, boss.pos.x - 1, 'U');
	mvwaddch(win, boss.pos.y + 1, boss.pos.x, 'Y');
	for (int i = 0; i < 9; i++)
		mvwaddch(win, boss.pos.y - 1, boss.pos.x - i - 2, '<');
	for (int i = 0; i < 9; i++)
		mvwaddch(win, boss.pos.y - 1, boss.pos.x + i + 2, '>');

	for (int i = 0; i < 6; i++)
		if (i % 2 == 0)
			mvwaddch(win, boss.pos.y, boss.pos.x - (6 - i), '[');
		else
			mvwaddch(win, boss.pos.y, boss.pos.x - (6 - i), ']');
	for (int i = 1; i <= 6; i++)
		if (i % 2 == 1)
			mvwaddch(win, boss.pos.y, boss.pos.x + i, '[');
		else
			mvwaddch(win, boss.pos.y, boss.pos.x + i, ']');
	if ((frame % 10) / 3)
	{
		wattron(win, COLOR_PAIR(frame % 2 ? 3 : 4));
		mvwaddch(win, boss.pos.y - 2, boss.pos.x + 1, ACS_DARROW);
		mvwaddch(win, boss.pos.y - 2, boss.pos.x - 1, ACS_DARROW);
		mvwaddch(win, boss.pos.y - 2, boss.pos.x, ACS_DARROW);
		mvwaddch(win, boss.pos.y - 1, boss.pos.x, ACS_DARROW);
		wattroff(win, COLOR_PAIR(frame % 2 ? 3 : 4));
	}
	wattroff(win, COLOR_PAIR(3));
	return (1);
}
