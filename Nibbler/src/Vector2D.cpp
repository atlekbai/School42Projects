// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vector2D.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 23:01:02 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 23:01:03 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Vector2D.hpp"

Vector2D::Vector2D(void) : x(0), y(0)
{}

Vector2D::Vector2D(float xpos, float ypos) : x(xpos), y(ypos)
{}

Vector2D::~Vector2D(void)
{}

Vector2D &Vector2D::add(Vector2D const &vec)
{
	x += vec.x;
	y += vec.y;
	return(*this);
}

Vector2D &Vector2D::sub(Vector2D const &vec)
{
	x -= vec.x;
	y -= vec.y;
	return(*this);
}

Vector2D &Vector2D::mul(Vector2D const &vec)
{
	x *= vec.x;
	y *= vec.y;
	return(*this);
}

Vector2D &Vector2D::div(Vector2D const &vec)
{
	x /= vec.x;
	y /= vec.y;
	return(*this);
}

Vector2D &Vector2D::zero(void)
{
	x = 0;
	y = 0;
	return (*this);
}

Vector2D Vector2D::diff(const Vector2D &v1, const Vector2D &v2)
{
	Vector2D res = Vector2D(v1.x - v2.x, v1.y - v2.y);
	return (res);
}

Vector2D &operator+(Vector2D &v1, Vector2D &v2)
{
	return (v1.add(v2));
}

Vector2D &operator-(Vector2D &v1, Vector2D &v2)
{
	return (v1.sub(v2));
}

Vector2D &operator/(Vector2D &v1, Vector2D &v2)
{
	return (v1.div(v2));
}

Vector2D &operator*(Vector2D &v1, Vector2D &v2)
{
	return (v1.mul(v2));
}

Vector2D &Vector2D::operator+=(const Vector2D &v1)
{
	return (this->add(v1));
}

Vector2D &Vector2D::operator-=(const Vector2D &v1)
{
	return (this->add(v1));
}

Vector2D &Vector2D::operator/=(const Vector2D &v1)
{
	return (this->div(v1));
}

Vector2D &Vector2D::operator*=(const Vector2D &v1)
{
	return (this->mul(v1));
}

std::ostream &operator<<(std::ostream &o, const Vector2D &v)
{
	o << "(" << v.x << ", " << v.y << ")";
	return (o);
}
