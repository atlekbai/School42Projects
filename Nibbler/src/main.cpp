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
#include <thread>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	const int	FPS = 60;
	const int	frame_delay = 1000 / FPS;
	unsigned	frame_start;
	unsigned	frame_time;
	Game		*game;
	int			width;
	int			height;

	srand(time(NULL));
	width = std::atoi(av[1]);
	height = std::atoi(av[2]);
	
	if (width < 500 || height < 500)
	{
		std::cout << "Error: small width or height" << std::endl;
		return (0);
	}
	else if (width > 2560 || height > 1400)
	{
		std::cout << "Error: large width or height" << std::endl;
		return (0);
	}

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