// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FoodSpawner.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/02 22:45:44 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/02 22:45:45 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FOOD_SPAWNER_HPP
# define FOOD_SPAWNER_HPP

# include "Game.hpp"
# include "Component.hpp"
# include "Components.hpp"


class FoodSpawner: public Component
{
private:
	std::deque<Vector2D> *body;

public:
	FoodSpawner(std::deque<Vector2D> *snake)
	{
		body = snake;
	}
	void init(void) override;
	void addFood(void);
	void destroyFood(Entity *e);
};

#endif