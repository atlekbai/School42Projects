// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssetManager.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:39:57 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:39:57 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AssetManager.hpp"

AssetManager::AssetManager(Manager *man) : manager(man)
{}

AssetManager::~AssetManager(void)
{
	for (auto &t: textures)
		SDL_DestroyTexture(t.second);
}

void 		AssetManager::add_texture(std::string id, const char *file_name)
{
	textures.emplace(id, TextureManager::load_texture(file_name));
}

void 		AssetManager::add_font(std::string id, const char *file_name, int font_size)
{
	fonts.emplace(id, TTF_OpenFont(file_name, font_size));
}

SDL_Texture	*AssetManager::get_texture(std::string id)
{
	return (textures[id]);
}

TTF_Font	*AssetManager::get_font(std::string id)
{
	return (fonts[id]);
}