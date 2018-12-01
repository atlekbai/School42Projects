// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vector2D.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 23:01:09 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 23:01:09 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VECTOR_2D_HPP
# define VECTOR_2D_HPP

# include <iostream>

class Vector2D
{
public:
	float x;
	float y;

	Vector2D(void);
	Vector2D(float xpos, float ypos);
	~Vector2D(void);

	Vector2D &add(Vector2D const &vec);
	Vector2D &sub(Vector2D const &vec);
	Vector2D &mul(Vector2D const &vec);
	Vector2D &div(Vector2D const &vec);
	Vector2D &zero(void);

	Vector2D &operator+=(const Vector2D &v1);
	Vector2D &operator-=(const Vector2D &v1);
	Vector2D &operator/=(const Vector2D &v1);
	Vector2D &operator*=(const Vector2D &v1);
	static Vector2D diff(const Vector2D &v1, const Vector2D &v2);
};

Vector2D &operator+(Vector2D &v1, Vector2D &v2);
Vector2D &operator-(Vector2D &v1, Vector2D &v2);
Vector2D &operator/(Vector2D &v1, Vector2D &v2);
Vector2D &operator*(Vector2D &v1, Vector2D &v2);
std::ostream &operator<<(std::ostream &o, const Vector2D &v);

#endif