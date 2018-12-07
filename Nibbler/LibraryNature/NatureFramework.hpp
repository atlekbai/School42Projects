// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NatureFramework.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/01 16:48:37 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/01 16:48:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NatureFramework_HPP
# define NatureFramework_HPP

# include "Framework.hpp"
# include "SDL2/SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include <iostream>
# include <map>

class NatureFramework: public Framework
{
private:
	std::map<std::string, SDL_Texture*>		textures;
	std::map<std::string, TTF_Font*>		fonts;
	std::map<std::string, Rect>				size;
	SDL_Window								*window;
	SDL_Texture 		*createLabel(std::string text, std::string fontId, std::string id);

public:
	virtual void		init(const char *title, int width, int height, std::map<std::string, std::string> menu);
	virtual void		clear(void);
	virtual void		draw(std::string textureId, Rect src, Rect dst, double angle);
	virtual void		render(void);
	virtual void		close(void);
	virtual int			handleEvents(std::vector<Entity*> ui);
	virtual SDL_Texture	*loadTexture(const char *fileName);
	virtual void		delay(int time);
	virtual unsigned	ticks(void);
	virtual void		drawScore(int score, int id, int x, int y);
	virtual void		loadAssets(std::map<std::string, std::string> menu);


	static SDL_Renderer	*renderer;
	static SDL_Event	event;
};

#endif