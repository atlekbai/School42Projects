// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpriteComponent.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/01 17:58:57 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/01 17:58:58 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPRITE_COMPONENT_HPP
# define SPRITE_COMPONENT_HPP

# include "Component.hpp"
# include "Components.hpp"

class SpriteComponent: public Component
{
private:
	TransformComponent	*transform;
	Rect				src;
	Rect				dst;

public:
	std::string			textureId;
	SpriteComponent(void) = default;
	SpriteComponent(std::string id);
	void	setTexture(std::string newTexture);
	void	init(void) override;
	void	update(void) override;
	void	draw(void) override;
};

#endif