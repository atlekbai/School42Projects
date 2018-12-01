// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SDLFramework.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/01 16:48:37 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/01 16:48:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SDLFRAMEWORK_HPP
# define SDLFRAMEWORK_HPP

# include "Framework.hpp"
# include "SDL2/SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include <iostream>
# include <map>

class SDLFramework: public Framework
{
private:
	std::map<std::string, SDL_Texture*>		textures;
	std::map<std::string, TTF_Font*>		fonts;
	SDL_Window								*window;

public:
	virtual void		init(const char *title, int width, int height);
	virtual void		clear(void);
	virtual void		draw(std::string textureId, Rect src, Rect dst, double angle);
	virtual void		render(void);
	virtual void		close(void);
	virtual int			handleEvents(void);
	virtual SDL_Texture	*loadTexture(const char *fileName);
	virtual void		delay(int time);
	virtual unsigned	ticks(void);

	static SDL_Renderer	*renderer;
	static SDL_Event	event;
};

#endif