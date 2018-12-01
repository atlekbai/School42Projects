// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssetManager.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:39:50 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:39:50 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASSET_MANAGER
# define ASSET_MANAGER

# include <iostream>
# include <map>
# include <string>
# include "SDL_ttf.h"
# include "Vector2D.hpp"
# include "TextureManager.hpp"

class Manager;

class AssetManager
{
private:
	std::map<std::string, SDL_Texture*>		textures;
	std::map<std::string, TTF_Font*>		fonts;
	Manager									*manager;
public:
	AssetManager(Manager *man);
	~AssetManager(void);

	void 		add_texture(std::string id, const char *file_name);
	void 		add_font(std::string id, const char *file_name, int font_size);
	SDL_Texture	*get_texture(std::string id);
	TTF_Font	*get_font(std::string id);
};

#endif