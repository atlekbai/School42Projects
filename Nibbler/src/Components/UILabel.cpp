// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UILabel.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/25 12:04:35 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/25 12:04:35 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UILabel.hpp"

UILabel::UILabel(int x, int y, std::string txt, std::string fnt, SDL_Color clr)
{
	text = txt;
	font = fnt;
	color = clr;
	position.x = x;
	position.y = y;
	set_text(text, font);
}

UILabel::~UILabel(void)
{}

void	UILabel::set_text(std::string txt, std::string fnt)
{
	SDL_Surface *tmp = TTF_RenderText_Blended(Game::assets->get_font(fnt),
											  txt.c_str(), color);
	texture = SDL_CreateTextureFromSurface(Game::renderer, tmp);
	SDL_FreeSurface(tmp);
	SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}

void	UILabel::draw(void)
{
	SDL_RenderCopy(Game::renderer, texture, nullptr, &position);
}
