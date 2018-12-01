// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GraphicalMode.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/01 16:59:47 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/01 16:59:47 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GRAPHICALMODE_HPP
# define GRAPHICALMODE_HPP

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <iostream>
# include "Text.hpp"
# include <unistd.h>
# include "Hostname.hpp"
# include "IMonitorDisplay.hpp"

class GraphicalMode : public IMonitorDisplay
{
private:
	Hostname		item;
	const int 		SCREEN_WIDTH;
	const int 		SCREEN_HEIGHT;
	SDL_Window*		window;
	SDL_Renderer*	renderer;
	SDL_Texture*	texture;
	GraphicalMode(GraphicalMode & src);
	GraphicalMode const & operator=(GraphicalMode & rhs);
public:
	GraphicalMode(void);
	~GraphicalMode(void);

	bool			init(void);
	SDL_Texture*	GetI(void);
	bool			loadMedia(void);
	void			close(void);
	void			putText(Text &text, char const *txt);
	SDL_Texture*	loadTexture(std::string path);
	void			display(void);
	void			insertText(int x, int y, std::string str);
	void			createRect(int x, int y, int height);
};

#endif