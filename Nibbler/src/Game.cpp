// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:26:57 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:26:58 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"
#include "Map.hpp"
#include "Components.hpp"
#include <sstream>

Manager			manager;
SDL_Renderer	*Game::renderer = nullptr;
AssetManager	*Game::assets = new AssetManager(&manager);
SDL_Event		Game::event;
SDL_Rect		Game::camera = {0, 0, 800, 640};
bool			Game::is_running = false;

auto 			&text_label(manager.add_entity());
auto 			&snake(manager.add_entity());
auto 			&food(manager.add_entity());
Map				*map;

Game::Game(void){}
Game::~Game(void){}

void	Game::init(const char *title, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) return ;
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
									 SDL_WINDOWPOS_CENTERED,
									 width, height, 0);
	if (!window) return ;
	Game::renderer = SDL_CreateRenderer(window, -1, 0);
	if (!Game::renderer) return ;
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	if (TTF_Init() == -1) return ;
	Game::is_running = true;

	assets->add_font("arial", "assets/arial.TTF", 16);
	assets->add_texture("body", "assets/body.png");
	assets->add_texture("dirt", "assets/dirt.png");
	assets->add_texture("stone", "assets/stone.png");
	assets->add_texture("crate", "assets/Crate.png");

	/*
	**	Retrieving width and hight of map
	*/
	int map_width;
	int map_height;
	SDL_GetWindowSize(window, &map_width, &map_height);

	/*
	**	UITextLabel
	*/
	SDL_Color black = {0, 0, 0, 255};
	text_label.add_component<UILabel>(10, map_height - 25, "Score: 0", "arial", black);
	text_label.add_group(Game::group_colliders);

	/*
	**	Map loading
	*/
	double scale = 0.5;
	int tile_size = 100;
	map_width /= tile_size * scale;
	map_height /= tile_size * scale;
	int side = (map_width < map_height) ? map_width : map_height;
	int h_offset = map_height / 2 - side / 2;
	int w_offset = map_width / 2 - side / 2;
	map = new Map(scale, tile_size);
	map->load_map(side, side, w_offset, h_offset);

	/*
	**	Snake Component
	*/
	snake.add_component<SnakeBodyComponent>("body", 2, scale,
											tile_size, side / 2,
											side / 2);
	snake.add_group(Game::group_player);

	/*
	**	Food Component
	*/
	food.add_component<FoodComponent>(map, "crate");
	food.add_group(Game::group_colliders);
}

void	Game::handle_events(void)
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		is_running = false;
	else if (event.type == SDL_KEYDOWN)
	{
		SDL_Keycode code = event.key.keysym.sym;
		if (code == SDLK_RIGHT)
			snake.get_component<SnakeBodyComponent>().dir = 1;
		else if (code == SDLK_LEFT)
			snake.get_component<SnakeBodyComponent>().dir = 2;
		else if (code == SDLK_UP)		
			snake.get_component<SnakeBodyComponent>().dir = 3;
		else if (code == SDLK_DOWN)		
			snake.get_component<SnakeBodyComponent>().dir = 4;
	}

}

auto	&tiles(manager.get_group(Game::group_map));
auto	&players(manager.get_group(Game::group_player));
auto	&colliders(manager.get_group(Game::group_colliders));

void	Game::update(void)
{
	manager.refresh();
    manager.update();

    std::stringstream ss;
    ss << "Score: " << snake.get_component<SnakeBodyComponent>().score;
    text_label.get_component<UILabel>().set_text(ss.str(), "arial");

    /*
    **	Snake Collision check
    */
    std::list<Vector2D> snake_body = snake.get_component<SnakeBodyComponent>().body;
    Vector2D snake_head = snake_body.front();
    Vector2D food_pos = food.get_component<FoodComponent>().position;

    if (snake_head.x == food_pos.x && snake_head.y == food_pos.y)
    {
    	snake.get_component<SnakeBodyComponent>().add_tail();
		food.get_component<FoodComponent>().new_position(snake_body);
    }
}

void	Game::render(void)
{
	SDL_RenderClear(Game::renderer);

	for (auto &t: tiles)
		t->draw();
	for (auto &p: players)
		p->draw();
	for (auto &c: colliders)
		c->draw();

	SDL_RenderPresent(Game::renderer);
}

void	Game::clean(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_Quit();
}

bool	Game::running(void) const
{
	return (is_running);
}