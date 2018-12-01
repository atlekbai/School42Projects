// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UILabel.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/25 12:04:28 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/25 12:04:28 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef UILABEL_HPP
# define UILABEL_HPP

# include <iostream>
# include "TextureManager.hpp"
# include "AssetManager.hpp"
# include "Components.hpp"
# include "Game.hpp"

class UILabel: public Component
{
private:
	std::string text;
	std::string font;
	SDL_Color	color;
	SDL_Texture	*texture;
	SDL_Rect	position;
public:
	UILabel(int x, int y, std::string txt, std::string fnt, SDL_Color clr);
	~UILabel(void);
	void set_text(std::string txt, std::string fnt);
	void draw(void) override;
};

#endif