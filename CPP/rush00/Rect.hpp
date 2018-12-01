/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rect.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:00:46 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:44:47 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_HPP
# define RECT_HPP

#include "Position.class.hpp"

class Rect
{
public:

    Rect & operator=(Rect const & rhs);

    Rect(void);
    Rect(const Rect & toCopy);
    Rect(int x, int y, int x1, int y1);
    ~Rect(void);
	Position start;
	Position end;

    int     top(void);
    int     bottom(void);
    int     left(void);
    int     right(void);
    int     width(void);
    int     height(void);
    bool    contains(Position c);
    bool    intersects(Rect c);
	
};

#endif