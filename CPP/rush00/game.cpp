// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 21:04:29 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 21:04:29 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "game.hpp"

WINDOW* main_window;
WINDOW* game_window;

Rect game_s;
Rect screen_s;
Player player = Player('o', Position(40, 25), Rect(0, 0, 3, 1), 100, 10000);
Boss boss = Boss('W', Position(40, 0), Rect(0, 0, 3, 1), 300, 10000);
Boss boss2 = Boss('0', Position(40, 0), Rect(0, 0, 3, 1), 200, 10000);
EnemySwarm enemies;
ThingGroup stars;
ThingGroup asteroids;

bool checkCollision(bool game_exit)
{
	player.setRect(Rect(player.pos.x - 1, player.pos.y, 3, 1));
	for (int i = 0; i < asteroids.getN(); i++)
		if (asteroids.getData()[i] && player.getRect().contains(asteroids.getData()[i]->pos))
		{
			player.takeDamage(10);
			break ;
		}
	if (player.getHP() <= 0)
		stopGame("GAME OVER", game_window);
	return (game_exit);
}

int checkBulletCollision(ThingGroup &field)
{
	for (int i = 0; i < 100; i++)
	if (field.getData()[i])	
	for (int j = 0; j < 100; j++)
	if (player.bullets[j])
	if (player.bullets[j]->pos.x == field.getData()[i]->pos.x
		&& player.bullets[j]->pos.y == field.getData()[i]->pos.y)
		{
			system("afplay stone.flac&");
			field.erase(i);
			player.addDestroyed();
			delete (player.bullets[j]);
			player.bullets[j] = NULL;
			break ;
		}
	return (0);
}

int PlayerEnemy(void)
{
	player.setRect(Rect(player.pos.x - 1, player.pos.y, 3, 1));
	for (int i = 0; i < 100; i++)
		if (enemies.getData()[i])
		{
			enemies.getData()[i]->setRect(Rect(enemies.getData()[i]->pos.x - 1, enemies.getData()[i]->pos.y, 3, 1));
			if (player.getRect().intersects(enemies.getData()[i]->getRect()))
				stopGame("GAME OVER", game_window);
			for (int j = 0; j < 100; j++)
			if (player.bullets[j])
			if (enemies.getData()[i]->getRect().contains(player.bullets[j]->pos))
				{
					system("afplay die.aiff&");
					enemies.erase(i);
					player.addKilled();
					delete (player.bullets[j]);
					player.bullets[j] = NULL;
					break ;
				}
		}

	for (int i = 0; i < 100; i++)
		if (enemies.getData()[i])
			for (int j = 0; j < 100; j++)
				if (enemies.getData()[i]->bullets[j])
					if (player.getRect().contains(enemies.getData()[i]->bullets[j]->pos))
						stopGame("GAME OVER", game_window);
	return (0);
}

int PlayerBoss(Boss &boss_en)
{
	player.setRect(Rect(player.pos.x - 1, player.pos.y, 3, 1));
	boss_en.setRect(Rect(boss_en.pos.x - 9, boss_en.pos.y - 2, 19, 4));
	if (player.getRect().intersects(boss_en.getRect()))
		stopGame("GAME OVER", game_window);
	for (int j = 0; j < 100; j++)
		if (player.bullets[j])
		if (boss_en.getRect().contains(player.bullets[j]->pos))
			{
				boss_en.takeDamage(2);
				delete (player.bullets[j]);
				player.bullets[j] = NULL;
				break ;
			}

	if (!boss_en.getHP())
	{
		player.addKilled();
		stopGame("YOU WIN", game_window);
	}

	for (int j = 0; j < 100; j++)
		if (boss_en.bullets[j])
			if (player.getRect().contains(boss_en.bullets[j]->pos))
				stopGame("GAME OVER", game_window);
	return (0);
}

bool updateObjects(int frame, bool game_exit)
{
	player.checkBullets(game_s);
	display(player.bullets, 100, game_window, '|');
	
	game_exit = (frame % 5 == 0) ? checkCollision(game_exit) : game_exit;
	actionObject(stars, 5, '.', frame, game_window);
	actionObject(asteroids, 20, 'O', frame, game_window);
	checkBulletCollision(asteroids);
	if (frame > 1000)
	{
		boss.update(game_s, frame, player.pos);
		renderBoss(frame, game_window, boss);
		display(boss.bullets, 100, game_window, 'T');
		PlayerBoss(boss);
	}

	if (frame > 1500)
	{
		boss2.update(game_s, frame, player.pos);
		renderBoss(frame, game_window, boss2);
		display(boss2.bullets, 100, game_window, 'U');
		PlayerBoss(boss2);
	}

	enemies.update(frame);
	for (int i = 0; i < 100; i++)
		if (enemies.getData()[i])	
			{
				renderEnemy(frame, game_window, *enemies.getData()[i]);
				display(enemies.getData()[i]->bullets, 100, game_window, ':');
			}
	PlayerEnemy();
	return (game_exit);
}

void	run(void)
{
	init(&main_window, &game_window, screen_s, game_s);
	int input_ch;
	int frame;
	bool game_exit = false;

	enemies.setend(game_s);
	stars.setend(game_s);
	asteroids.setend(game_s);
	wattron(main_window, A_BOLD);
	box(main_window, 0, 0);
	wattroff(main_window, A_BOLD);

	wmove(main_window, 1, screen_s.width() - 35);
	wvline(main_window, '|', screen_s.height() - 1);

	wrefresh(main_window);
	wrefresh(game_window);
	frame = 0;
	while (1)
	{
		werase(game_window);
		mvwprintw(main_window, 1, screen_s.width() - 33, "SCORE:");
		mvwprintw(main_window, 3, screen_s.width() - 33, "TIME: %d     ", frame);
		mvwprintw(main_window, 4, screen_s.width() - 33, "HP: %d     ", player.getHP());
		mvwprintw(main_window, 5, screen_s.width() - 33, "DESTROYED: %d", player.getDestroyed());
		mvwprintw(main_window, 6, screen_s.width() - 33, "KILLED: %d", player.getKilled());
		input_ch = wgetch(main_window);
		input_ch = tolower(input_ch);
		if (input_ch == ' ')
			player.fire();
		if (input_ch == 'q')
			game_exit = true;
		if (input_ch == 'p')
			while(1)
			{
				const char *text = "GAME PAUSED";
				int x;
				int y;
				getmaxyx(main_window, y, x);
				mvwprintw(main_window, y / 2, (x - strlen(text) - 35) / 2, "%s", text);
				input_ch = wgetch(main_window);
				input_ch = tolower(input_ch);
				if (input_ch == 'p')
					break ;
			}
		if (input_ch == 'w' || input_ch == KEY_UP)
			if (player.pos.y > game_s.top())
				player.pos.y -= 1;
		if (input_ch == 's' || input_ch == KEY_DOWN)
			if (player.pos.y < game_s.bottom() - 1)
				player.pos.y += 1;
		if (input_ch == 'a' || input_ch == KEY_LEFT)
			if (player.pos.x > game_s.left() + 2)
				player.pos.x -= 1;
		if (input_ch == 'd' || input_ch == KEY_RIGHT)
			if (player.pos.x < game_s.right() - 2)
				player.pos.x += 1;
		game_exit = updateObjects(frame, game_exit);
		renderPlayer(frame, game_window, player);
		wrefresh(main_window);
		wrefresh(game_window);
		if (game_exit) break;
		frame++;
		usleep(10000);
	}
}

void	close(void)
{
	endwin();
}
