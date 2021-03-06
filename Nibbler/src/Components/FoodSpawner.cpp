// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FoodSpawner.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/02 23:01:12 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/02 23:01:13 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FoodSpawner.hpp"
#include "Game.hpp"

FoodSpawner::FoodSpawner(std::deque<Vector2D> *snake, int main_spawner)
{
	body = snake;
	spawn = main_spawner;
}

void FoodSpawner::init(void)
{
	count = 0;
	if (spawn)
		addFood();
}

void FoodSpawner::addFood(int x, int y)
{
	auto &food(Game::manager.addEntity());
	food.addComponent<TransformComponent>(x, y, Game::cellSize, Game::cellSize);
	food.addComponent<SpriteComponent>("food");
	food.addGroup(group_food);
	count++;
}

void FoodSpawner::addFood(void)
{
	std::vector<Vector2D>	availSpace;
	bool				 	contains;

	if (count == 0)
	{
		for (int y = 1; y < Game::mapSize.y - 1; y++)
			for (int x = 1; x < Game::mapSize.x - 1; x++)
			{
				contains = false;
				for (int i = 0; i < body->size(); i++)
					if ((*body)[i].x / Game::cellSize == x && (*body)[i].y / Game::cellSize == y)
					{
						contains = true;
						break;
					}
				if (!contains)
					availSpace.push_back({x, y});
			}
		int randIdx = rand() % availSpace.size();
		int x = availSpace[randIdx].x * Game::cellSize;
		int y = availSpace[randIdx].y * Game::cellSize;
		auto &food(Game::manager.addEntity());
		food.addComponent<TransformComponent>(x, y, Game::cellSize, Game::cellSize);
		food.addComponent<SpriteComponent>("food");
		food.addGroup(group_food);

		if (Game::state == 5)
		{
			char buf[2];
			buf[0] = x / Game::cellSize;
			buf[1] = y / Game::cellSize;
			send(Game::cs, buf, 2, 0);
		}

		count++;
	}
}

void FoodSpawner::addFood(std::deque<Vector2D> body, int i)
{
	for (int j = i; j < body.size(); j++)
	{
		auto &food(Game::manager.addEntity());
		food.addComponent<TransformComponent>(body[j].x, body[j].y, Game::cellSize, Game::cellSize);
		food.addComponent<SpriteComponent>("food");
		food.addGroup(group_food);
		count++;
	}
}

void FoodSpawner::destroyFood(Entity *e)
{
	e->destroy();
	count--;
	if (spawn)
		addFood();
	if (Game::state == 6)
	{
		char buf[2];
		recv(Game::cs, buf, 2, 0);
		addFood(buf[0] * Game::cellSize, buf[1] * Game::cellSize);
	}
}
