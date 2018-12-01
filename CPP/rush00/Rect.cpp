/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rect.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:00:49 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:46:34 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rect.hpp"

Rect::Rect(void)
{
    this->start = Position(0, 0);
    this->end = Position(0, 0);
}

Rect::Rect(const Rect & toCopy) {
    this->start = toCopy.start;
    this->end = toCopy.end;
}

Rect::Rect(int x, int y, int x1, int y1) :  start(Position(x, y)),
                                            end(Position(x1, y1))
{}

Rect::~Rect(void){}

Rect & Rect::operator=(Rect const & rhs) {
    this->start = rhs.start;
    this->end = rhs.end;

    return *this;
}

int     Rect::top(void)
{
    return (start.y);
}

int     Rect::bottom(void)
{
    return (start.y + end.y);
}

int     Rect::left(void)
{
    return (start.x);
}

int     Rect::right(void)
{
    return (start.x + end.x);
}

int     Rect::width(void)
{
    return (end.x);
}

int     Rect::height(void)
{
    return (end.y);
}

bool    Rect::contains(Position c)
{
    return ((c.x >= start.x && c.x < right()) && (c.y >= start.y && c.y < bottom()));
}

bool    Rect::intersects(Rect c)
{
    if (contains(c.start) || contains(Position(c.right(), c.bottom()))
        || contains(Position(c.right(), c.top())) || contains(Position(c.left(), c.bottom())))
        return (true);
    return (false);
}
