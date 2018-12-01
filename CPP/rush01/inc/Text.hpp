// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Text.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/01 15:01:34 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/01 15:01:34 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TEXT_HPP
# define TEXT_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>

class Text
{
public:
	Text(void);
	~Text(void);
	bool ldFromTxt(	std::string textureText,
					SDL_Color textColor,
					SDL_Renderer* renderer,
					TTF_Font* gFont);
	void free(void);
	void render(int x,
				int y,
				SDL_Renderer* renderer,
				SDL_Rect* clip = NULL,
				double angle = 0.0,
				SDL_Point* center = NULL,
				SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	SDL_Texture* 	texture;
	int 			width;
	int 			height;
};

#endif