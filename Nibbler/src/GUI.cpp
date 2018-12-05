// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUI.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/05 14:05:01 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/05 14:05:01 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GUI.hpp"
#include "Game.hpp"
#include "Framework.hpp"

std::map<std::string, std::string> GUI::menu = {
	{"header", "Nibbler"},
	{"menu1", "Play"},
	{"menu2", "Multiplayer (local)"},
	{"menu3", "Multiplayer (net) server"},
	{"menu4", "Multiplayer (net) client"},
	{"menu5", "Exit"},
	{"footer", "@atilegen\'s team"}
};

void	GUI::addLabel(int x, int y, std::string id)
{
	Entity	*e;

	e = &Game::manager.addEntity();
	e->addComponent<TransformComponent>(x, y, 0, 0);
	e->addComponent<SpriteComponent>(id);
	e->addGroup(group_ui);
}

void	GUI::loadMenu(void)
{
	addLabel(Game::mapSize.x * Game::cellSize / 2, 2 * Game::cellSize, "header");
	addLabel(Game::mapSize.x * Game::cellSize / 2, (Game::mapSize.y - 2) * Game::cellSize / 2, "menu1");
	addLabel(Game::mapSize.x * Game::cellSize / 2, (Game::mapSize.y - 0) * Game::cellSize / 2, "menu2");
	addLabel(Game::mapSize.x * Game::cellSize / 2, (Game::mapSize.y + 2) * Game::cellSize / 2, "menu3");
	addLabel(Game::mapSize.x * Game::cellSize / 2, (Game::mapSize.y + 4) * Game::cellSize / 2, "menu4");
	addLabel(Game::mapSize.x * Game::cellSize / 2, (Game::mapSize.y + 6) * Game::cellSize / 2, "menu5");
	addLabel(Game::mapSize.x * Game::cellSize / 2, (Game::mapSize.y - 2) * Game::cellSize, "footer");
}

void	GUI::gameOver(void)
{
	Rect src = {0, 0, 365, 65};
	int x = (Game::mapSize.x * Game::cellSize - src.w) / 2;
	int y = (Game::mapSize.y * Game::cellSize - src.h) / 2;
	Rect dst = {x, y, 365, 65};
	Game::frameWork->draw("game_over", src, dst, 0);
}

void	GUI::addScore(int score, int id)
{
	int y = ((Game::mapSize.y + 2 * (id - 1)) * Game::cellSize - 65) / 2;
	Game::frameWork->drawScore(score, id, Game::mapSize.x * Game::cellSize / 2, y + Game::cellSize * 3);
}
