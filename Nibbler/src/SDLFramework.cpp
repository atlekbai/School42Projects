// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SDLFramework.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/01 16:48:42 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/01 16:48:42 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SDLFramework.hpp"
#include "Game.hpp"

SDL_Renderer	*SDLFramework::renderer = nullptr;
SDL_Event		SDLFramework::event;

void	SDLFramework::init(const char *title, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) return ;
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
									 SDL_WINDOWPOS_CENTERED,
									 width, height, 0);
	if (!window) return ;
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) return ;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	if (TTF_Init() == -1) return ;

	fonts.emplace("arial", TTF_OpenFont("assets/arial.TTF", 16));
	textures.emplace("snake_head", loadTexture("assets/snake_head.png"));
	textures.emplace("snake_edge", loadTexture("assets/snake_edge.png"));
	textures.emplace("snake_tail", loadTexture("assets/snake_tail.png"));
	textures.emplace("snake_body", loadTexture("assets/snake_direct.png"));
	textures.emplace("background", loadTexture("assets/dirt.png"));
	textures.emplace("collider", loadTexture("assets/stone.png"));
	textures.emplace("food", loadTexture("assets/food.png"));
	textures.emplace("crash", loadTexture("assets/crash.png"));
	textures.emplace("game_over", loadTexture("assets/game_over.png"));
	
	is_ready = true;
}

int		SDLFramework::handleEvents(void)
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		Game::is_running = false;
	else if (event.type == SDL_KEYDOWN)
	{
		SDL_Keycode code = event.key.keysym.sym;
		if (code == SDLK_RIGHT)
			return (1);
		else if (code == SDLK_LEFT)
			return (2);
		else if (code == SDLK_UP)		
			return (3);
		else if (code == SDLK_DOWN)		
			return (4);
		else if (code == SDLK_SPACE)
			return (-1);
	}
	else if (event.type == SDL_KEYUP)
	{
		SDL_Keycode code = event.key.keysym.sym;
		if (code == SDLK_ESCAPE)
			Game::is_running = false;
	}
	return (0);
}

void	SDLFramework::clear(void)
{
	SDL_RenderClear(renderer);
}

void	SDLFramework::draw(std::string id, Rect src, Rect dst, double angle)
{
	SDL_Rect s = {src.x, src.y, src.w, src.h};
	SDL_Rect d = {dst.x, dst.y, dst.w, dst.h};
	SDL_RenderCopyEx(renderer, textures[id], &s, &d, angle, NULL, SDL_FLIP_NONE);
}

void	SDLFramework::render(void)
{
	SDL_RenderPresent(renderer);
}

void	SDLFramework::close(void)
{
	for (auto &t: textures)
		SDL_DestroyTexture(t.second);

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

SDL_Texture	*SDLFramework::loadTexture(const char *fileName)
{
	SDL_Surface *tmp = IMG_Load(fileName);
	SDL_Texture	*texture = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_FreeSurface(tmp);
	return (texture);
}

void	SDLFramework::delay(int time)
{
	SDL_Delay(time);
}

unsigned SDLFramework::ticks(void)
{
	return (SDL_GetTicks());
}
