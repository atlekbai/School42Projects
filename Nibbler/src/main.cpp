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
#include <dlfcn.h>

#define LIB1 "./LibraryDesert/libDesert.so"
#define LIB2 "./LibraryNature/libNature.so"
#define LIB3 "./LibraryAlcatraz/libAlcatraz.so"

Framework *getFramework(const char *path)
{
	void *handle = dlopen(path, RTLD_LAZY);
	if (!handle)
	{
		std::cout << "Error: \"" << path << "\" not found." << std::endl;
		exit(0); 
	}
	Framework* (*createFramework)(void);
	createFramework = (Framework* (*)(void))dlsym(handle, "createFramework");
	return ((Framework*)createFramework());
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Usage: " << av[0] << " <width> <height>" << std::endl;
		return (0);
	}
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

	Framework *desert = getFramework(LIB1);
	Framework *nature = getFramework(LIB2);
	Framework *alcatraz = getFramework(LIB3);
	game->addFramework(desert);
	game->addFramework(nature);
	game->addFramework(alcatraz);
	
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