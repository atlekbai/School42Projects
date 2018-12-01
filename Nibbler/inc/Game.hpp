// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:15:49 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:15:50 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include "SDL2/SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include <iostream>
# include <vector>

class AssetManager;

class Game
{
private:
	SDL_Window	*window;
public:
	Game(void);
	~Game(void);
	void	init(const char *title, int width, int height);
	void	handle_events(void);
	void	update(void);
	void	render(void);
	void	clean(void);
	bool	running(void) const;
	static SDL_Renderer	*renderer;
	static SDL_Event	event;
	static SDL_Rect		camera;
	static bool			is_running;
	static AssetManager	*assets;
	enum				name
	{
		group_map,
		group_player,
		group_colliders
	};
};

#endif