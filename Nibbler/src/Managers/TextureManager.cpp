// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TextureManager.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:46:58 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:46:59 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TextureManager.hpp"

SDL_Texture	*TextureManager::load_texture(const char *file_name)
{
	SDL_Surface *tmp = IMG_Load(file_name);
	SDL_Texture	*texture = SDL_CreateTextureFromSurface(Game::renderer, tmp);
	SDL_FreeSurface(tmp);
	return (texture);
}

void		TextureManager::draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst,
								 SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(Game::renderer, texture, &src, &dst, 0.0, NULL, flip);
}
