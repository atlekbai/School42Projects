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

# include "Component.hpp"
# include "Framework.hpp"
# include <deque>

class FoodSpawner: public Component
{
private:
	int						count;
	std::deque<Vector2D> 	*body;
	int						spawn;

public:
	FoodSpawner(std::deque<Vector2D> *snake, int main_spawner);
	void init(void) override;
	void addFood(void);
	void addFood(int x, int y);
	void addFood(std::deque<Vector2D> body, int i);
	void destroyFood(Entity *e);
};

#endif