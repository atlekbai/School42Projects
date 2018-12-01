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
	if (ac == 1)
		return (0);
	const int	FPS = 60;
	const int	frame_delay = 1000 / FPS;
	unsigned	frame_start;
	unsigned	frame_time;
	Game		*game;
	int			width;
	int			height;

	width = atoi(av[1]);
	height = atoi(av[2]);
	if (width < 400 || height < 400)
		return (0);
	game = new Game();
	game->init("Nibbler", width, height);
	while (game->running())
	{
		frame_start = SDL_GetTicks();
		game->handle_events();
		game->update();
		game->render();
		frame_time = SDL_GetTicks() - frame_start;
		if (frame_delay > frame_time)
			SDL_Delay(frame_delay - frame_time);
	}
	game->clean();
	return (0);
}