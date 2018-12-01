// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/20 14:48:23 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 12:50:28 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.class.hpp"

Fixed::Fixed(void) : value(0){}

Fixed::~Fixed(void){}

Fixed::Fixed(int const value)
{
	this->value = value << Fixed::bits;
}

Fixed::Fixed(float const value)
{
	this->value = roundf(value * (1 << Fixed::bits));
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	this->value = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->value) / (1 << Fixed::bits));
}

int		Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}


Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed((float)(this->value + rhs.getRawBits()) / (1 << Fixed::bits)));
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed((float)(this->value - rhs.getRawBits()) / (1 << Fixed::bits)));
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	float val1 = (float)this->value / (1 << Fixed::bits);
	return (Fixed(val1 / rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	float val1 = (float)this->value / (1 << Fixed::bits);
	return (Fixed(val1 * rhs.toFloat()));
}

Fixed	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--*this;
	return (tmp);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{	
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}

Fixed	const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

Fixed	const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->value > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->value < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->value >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->value <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->value == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->value != rhs.getRawBits());
}
