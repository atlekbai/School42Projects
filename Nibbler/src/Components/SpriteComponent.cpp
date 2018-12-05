// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpriteComponent.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/05 14:00:24 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/05 14:00:24 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SpriteComponent.hpp"
#include "Game.hpp"

SpriteComponent::SpriteComponent(std::string id) : textureId(id){}

void	SpriteComponent::setTexture(std::string newTexture)
{
	textureId = newTexture;
}

void	SpriteComponent::init(void)
{
	transform = &entity->getComponent<TransformComponent>();
	src = {0, 0, transform->w * 2, transform->h * 2};
	dst = {transform->position.x, transform->position.y, transform->w, transform->h};
}

void	SpriteComponent::update(void)
{
	dst = {transform->position.x, transform->position.y, transform->w, transform->h};
}

void	SpriteComponent::draw(void)
{
	Game::frameWork->draw(textureId, src, dst, transform->a);
}
