// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GraphicalMode.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/01 16:59:42 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/01 16:59:43 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GraphicalMode.hpp"
#include <sstream>

GraphicalMode::GraphicalMode(void) : 	SCREEN_WIDTH(320),
										SCREEN_HEIGHT(305)
{
	window = NULL;
	renderer = NULL;
	texture = NULL;
}

GraphicalMode::~GraphicalMode(void){}

void			GraphicalMode::insertText(int x, int y, std::string str)
{
	Text	text;
	putText(text, str.c_str());
	text.render(x, y, renderer);
}

void			GraphicalMode::createRect(int x, int y, int height)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = SCREEN_WIDTH;
	rect.h = height;
	SDL_RenderSetViewport(renderer, &rect);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void			GraphicalMode::display(void)
{
	bool		quit = false;
	SDL_Event	e;
	int			i;

	init();
	loadMedia();
	while(!quit)
	{
		while(SDL_PollEvent(&e) != 0)
			if(e.type == SDL_QUIT)
				quit = true;
		i = 0;
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		createRect(0, 0, 30);
		insertText(0, 0, item.getHostname());
		insertText(item.getHostname().size() * 9, 0, item.getUser());

		createRect(0, 31, 70);
		std::stringstream sys(item.getOs().c_str());
		std::string block;
		while (std::getline(sys, block, '\n'))
			insertText(0, 17 * i++, block);

		createRect(0, 102, 30);
		insertText(0, 0, item.getTime());

		createRect(0, 133, 70);
		insertText(0, 0, item.getCPU());
		insertText(0, 17, "CPU in %: ");
		std::stringstream ss;
		ss << item.getCPU_pro();
		insertText(9 * 9, 17, ss.str());

		createRect(0, 204, 30);
		insertText(0, 0, "RAM Usage: ");
		ss.str(std::string());
		ss << item.getRAM();
		insertText(9 * 11, 0, ss.str());

		SDL_Rect net;
		net.x = 0;
		net.y = 235;
		net.w = SCREEN_WIDTH;
		net.h = 70;
		SDL_RenderSetViewport(renderer, &net);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		insertText(0, 0, "Packages received: ");
		ss.str(std::string());
		ss << item.getNetIn();
		insertText(9 * 17, 0, ss.str());
		insertText(0, 17, "Packages sent    : ");
		ss.str(std::string());
		ss << item.getNetOut();
		insertText(9 * 17, 17, ss.str());

		SDL_RenderPresent(renderer);
		usleep(100000);
	}
	close();
}

bool GraphicalMode::init(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
			"ft_gkrellm",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
	);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	TTF_Init();
	return (true);
}

bool GraphicalMode::loadMedia(void)
{
	texture = loadTexture("texture/texture.jpg");
	return (true);
}

void GraphicalMode::putText(Text &text, char const *txt)
{
	TTF_Font* font = TTF_OpenFont("fonts/opensans.ttf", 16);
	SDL_Color textColor = {255, 255, 255, 255};
	text.ldFromTxt(txt, textColor, renderer, font);
}

void GraphicalMode::close(void)
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	texture = NULL;
	window = NULL;
	renderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* GraphicalMode::loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}

SDL_Texture*	GraphicalMode::GetI(void){ return (texture); }

GraphicalMode::GraphicalMode(GraphicalMode & src) : SCREEN_WIDTH(320),
										SCREEN_HEIGHT(305)
										{
	*this = src;
}

	GraphicalMode const & GraphicalMode::operator=(GraphicalMode & rhs){
	texture = rhs.GetI();
	return *this;
}
