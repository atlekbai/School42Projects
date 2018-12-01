// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/25 14:03:30 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/25 14:03:31 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "Vector2D.hpp"

class Map
{
private:
	int			tile_size;
	double		scale;
	std::string	space_id;
	std::string	block_id;
public:
	Vector2D	offset;
	Vector2D	dim;
	int			scaled_size;
	
	Map(double scl, int tl_size);
	~Map(void);

	void	load_map(int size_x, int size_y, int w_offset, int h_offset);
	void	add_tile(std::string id, int src_x, int src_y, int x, int y);
};

#endif