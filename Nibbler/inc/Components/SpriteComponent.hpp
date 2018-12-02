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
# include "Game.hpp"

class SpriteComponent: public Component
{
private:
	TransformComponent	*transform;
	Rect				src;
	Rect				dst;

public:
	std::string			textureId;
	SpriteComponent(void) = default;
	SpriteComponent(std::string id) : textureId(id){}

	void	setTexture(std::string newTexture)
	{
		textureId = newTexture;
	}

	void	init(void) override
	{
		transform = &entity->getComponent<TransformComponent>();
		src = {0, 0, transform->w * 2, transform->h * 2};
		dst = {transform->position.x, transform->position.y, transform->w, transform->h};
	}

	void	update(void) override
	{
		dst = {transform->position.x, transform->position.y, transform->w, transform->h};
	}

	void	draw(void) override
	{
		Game::frameWork->draw(textureId, src, dst, transform->a);
	}
};

#endif