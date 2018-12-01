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

class Map;

class Game
{
private:
	std::vector<Entity*>	*backgrounds;
	std::vector<Entity*>	*players;
	std::vector<Entity*>	*foods;
	std::vector<Entity*>	*colliders;
	Entity					*player;
	
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
	
	static bool			is_running;
	static Manager		manager;
	static Framework	*frameWork;
	static Map			*map;
	static int			cellSize;
	static Vector2D		mapSize;
	
};

#endif