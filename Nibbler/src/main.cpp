// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:15:41 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:15:41 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"

int	main(int ac, char **av)
{
	const int	FPS = 60;
	const int	frame_delay = 1000 / FPS;
	unsigned	frame_start;
	unsigned	frame_time;
	Game		*game;
	int			width;
	int			height;

	srand(time(NULL));
	width = 800;
	height = 640;
	game = new Game();
	game->init("Nibbler", width, height);
	while (game->running())
	{
		frame_start = game->ticks();
	
		game->handleEvents();
		game->update();
		game->render();

		frame_time = game->ticks() - frame_start;
		if (frame_delay > frame_time)
			game->delay(frame_delay - frame_time);
	}
	return (0);
}