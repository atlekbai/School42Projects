// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TextureManager.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:46:51 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:46:52 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TEXTURE_MANAGER_HPP
# define TEXTURE_MANAGER_HPP

# include "Game.hpp"

class TextureManager
{
public:
	static SDL_Texture	*load_texture(const char *file_name);
	static void			draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst,
							 SDL_RendererFlip flip);
};

#endif