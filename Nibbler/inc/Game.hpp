// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:15:49 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:15:50 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include "Framework.hpp"
# include "Manager.hpp"
# include "GUI.hpp"
# include "Network.hpp"
# include <map>
# include <vector>

/*
** state 1 - game is runnig
** state 2 - game is over
** state 3 - main menu
** state 4 - local multiplayer
** state 5 - multiplayer server
** state 6 - multiplayer client
*/

class Map;

class Game
{
private:
	std::vector<Entity*>	*backgrounds;
	std::vector<Entity*>	*players;
	std::vector<Entity*>	*foods;
	std::vector<Entity*>	*colliders;
	std::vector<Entity*>	*ui;
	Entity					*player;
	Entity					*player2;
	Entity					*foodSpawner;
	std::vector<Framework*>	frameWorks;

	void					addSnake(Entity **p, int x, int y, int len, int id);
	void					checkSnake(Entity *snake);
	void					checkSnakes(Entity **s1, Entity **s2);
	void					addCrash(int x, int y);
	void					netGame(void);
	void					clientGame(void);
	void					sendNet(int command);
	int						recvNet(void);
	void					setFrame(int frameIndex);
	
public:
	Game(void);
	~Game(void);
	void	init(const char *title, int width, int height);
	void	handleEvents(void);
	void	update(void);
	void	render(void);
	bool	running(void) const;
	void	delay(int time);
	unsigned ticks(void);
	void	start(int newState);
	void	clear(void);
	void	mainMenu(void);
	void	addFramework(Framework*);
	
	char				buf[2];
	static int			cs;
	static bool			is_running;
	static int			state;
	static int			cellSize;
	static Manager		manager;
	static Vector2D		mapSize;
	static Framework	*frameWork;
	static Map			*map;
	static GUI			*gui;
	static Network		net;
};

#endif