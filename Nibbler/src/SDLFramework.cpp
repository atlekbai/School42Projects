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
#include "Components.hpp"
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

	fonts.emplace("bit16", TTF_OpenFont("assets/8bit.ttf", 16));
	fonts.emplace("bit32", TTF_OpenFont("assets/8bit.ttf", 32));
	fonts.emplace("bit64", TTF_OpenFont("assets/8bit.ttf", 64));

	textures.emplace("snake_head", loadTexture("assets/snake_head.png"));
	textures.emplace("snake_edge", loadTexture("assets/snake_edge.png"));
	textures.emplace("snake_tail", loadTexture("assets/snake_tail.png"));
	textures.emplace("snake_body", loadTexture("assets/snake_direct.png"));

	textures.emplace("snake_head2", loadTexture("assets/snake2_head.png"));
	textures.emplace("snake_edge2", loadTexture("assets/snake2_edge.png"));
	textures.emplace("snake_tail2", loadTexture("assets/snake2_tail.png"));
	textures.emplace("snake_body2", loadTexture("assets/snake2_direct.png"));


	textures.emplace("background", loadTexture("assets/dirt.png"));
	textures.emplace("collider", loadTexture("assets/stone.png"));
	textures.emplace("food", loadTexture("assets/food.png"));
	textures.emplace("crash", loadTexture("assets/crash.png"));
	textures.emplace("game_over", loadTexture("assets/game_over.png"));
	
	textures.emplace("header", createLabel(Game::menu["header"], "bit64", "header"));
	textures.emplace("menu1", createLabel(Game::menu["menu1"], "bit32", "menu1"));
	textures.emplace("menu2", createLabel(Game::menu["menu2"], "bit32", "menu2"));
	textures.emplace("menu3", createLabel(Game::menu["menu3"], "bit32", "menu3"));
	textures.emplace("footer", createLabel(Game::menu["footer"], "bit16", "footer"));

	is_ready = true;
}

SDL_Texture *SDLFramework::createLabel(std::string text, std::string fontId, std::string id)
{
	Rect src = {0, 0, 0, 0};
	SDL_Color black = {0, 0, 0, 255};
	SDL_Surface	*tmp = TTF_RenderText_Blended(fonts[fontId], text.c_str(), black);
	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_FreeSurface(tmp);
	SDL_QueryTexture(textTexture, nullptr, nullptr, &src.w, &src.h);
	size.emplace(id, src);
	return (textTexture);
}

int		SDLFramework::handleEvents(void)
{
	SDL_PollEvent(&event);

	int x, y;
	SDL_GetMouseState(&x, &y);
	auto &ui(Game::manager.getGroup(group_ui));
	for (auto &u: ui)
	{
		std::string id = u->getComponent<SpriteComponent>().textureId;
		Vector2D 	pos = u->getComponent<TransformComponent>().position;
		pos.x -= size[id].w / 2;
		pos.y -= size[id].h / 2;
		if (x >= pos.x && x <= pos.x + size[id].w &&
			y >= pos.y && y <= pos.y + size[id].h)
			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			{
				if (id == "menu1")
					return (menu1);
				else if (id == "menu2")
					return (menu2);
				else if (id == "menu3")
					return (menu3);
			}
	}

	if (event.type == SDL_QUIT)
		Game::is_running = false;
	else if (event.type == SDL_KEYDOWN)
	{
		SDL_Keycode code = event.key.keysym.sym;
		if (code == SDLK_RIGHT)
			return (right1);
		else if (code == SDLK_LEFT)
			return (left1);
		else if (code == SDLK_UP)		
			return (up1);
		else if (code == SDLK_DOWN)		
			return (down1);

		if (code == SDLK_d)
			return (right2);
		else if (code == SDLK_a)
			return (left2);
		else if (code == SDLK_w)		
			return (up2);
		else if (code == SDLK_s)		
			return (down2);

		else if (code == SDLK_SPACE)
			return (space);
	}
	else if (event.type == SDL_KEYUP)
	{
		SDL_Keycode code = event.key.keysym.sym;
		if (code == SDLK_ESCAPE)
			return (escape);
	}
	return (empty);
}

void	SDLFramework::clear(void)
{
	SDL_RenderClear(renderer);
}

void	SDLFramework::drawScore(int score, int id, int x, int y)
{
	std::string scoreStr = "player" + std::to_string(id) + ": " + std::to_string(score);
	SDL_Texture *label = createLabel(scoreStr, "bit32", "score1");
	SDL_Rect s = {0, 0, size["score1"].w, size["score1"].h};
	SDL_Rect d = {x, y, size["score1"].w, size["score1"].h};
	d.x -= size["score1"].w / 2;
	d.y -= size["score1"].h / 2;
	SDL_RenderCopyEx(renderer, label, &s, &d, 0, NULL, SDL_FLIP_NONE);
	SDL_DestroyTexture(label);
}


void	SDLFramework::draw(std::string id, Rect src, Rect dst, double angle)
{
	SDL_Rect s = {src.x, src.y, src.w, src.h};
	SDL_Rect d = {dst.x, dst.y, dst.w, dst.h};
	if (size.count(id))
	{
		d.w = size[id].w;
		d.h = size[id].h;
		d.x -= d.w / 2;
		d.y -= d.h / 2;
		s.w = d.w;
		s.h = d.h;
	}
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
