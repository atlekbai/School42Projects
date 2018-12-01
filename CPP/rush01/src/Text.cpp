// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Text.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/01 15:01:30 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/01 15:01:30 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Text.hpp"

Text::Text(void):	texture(NULL),
					width(0),
					height(0){}

Text::~Text(void)
{
	free();
}

bool Text::ldFromTxt(std::string textureText,
					SDL_Color textColor,
					SDL_Renderer* renderer,
					TTF_Font* font)
{
	free();
	SDL_Surface* textSurface = TTF_RenderText_Solid(
									font,
									textureText.c_str(),
									textColor);
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	width = textSurface->w;
	height = textSurface->h;
	SDL_FreeSurface(textSurface);
	return (texture != NULL);
}

void Text::free(void)
{
	if(texture == NULL)
		return ;
	SDL_DestroyTexture(texture);
	texture = NULL;
	width = 0;
	height = 0;
}

void Text::render(	int x,
					int y,
					SDL_Renderer* renderer,
					SDL_Rect* clip,
					double angle,
					SDL_Point* center,
					SDL_RendererFlip flip)
{
	SDL_Rect rq = {x, y, width, height};
	if(clip != NULL)
	{
		rq.w = clip->w;
		rq.h = clip->h;
	}
	SDL_RenderCopyEx(renderer,
					 texture,
					 clip,
					 &rq,
					 angle,
					 center,
					 flip);
}
