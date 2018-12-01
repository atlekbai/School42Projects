// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/20 14:48:26 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/20 16:35:49 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>
class Fixed
{
public:
	Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const &src);
	~Fixed(void);

	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	float			toFloat(void) const;
	int				toInt(void) const;

	Fixed			&operator=(Fixed const &rhs);
	Fixed			operator+(Fixed const &rhs) const;
	Fixed			operator-(Fixed const &rhs) const;
	Fixed			operator/(Fixed const &rhs) const;
	Fixed			operator*(Fixed const &rhs) const;

	bool 			operator>(Fixed const &rhs) const;
	bool 			operator<(Fixed const &rhs) const;
	bool 			operator>=(Fixed const &rhs) const;
	bool 			operator<=(Fixed const &rhs) const;
	bool 			operator==(Fixed const &rhs) const;
	bool 			operator!=(Fixed const &rhs) const;

	Fixed			operator++(void);
	Fixed			operator++(int);
	Fixed			operator--(void);
	Fixed			operator--(int);

	static Fixed	&max(Fixed &a, Fixed &b);
	static Fixed	const &max(Fixed const &a, Fixed const &b);
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	const &min(Fixed const &a, Fixed const &b);


private:
	int					value;
	static const int	bits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
