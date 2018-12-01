// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/27 15:02:33 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/27 15:18:48 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
private:
	T		*array;
	size_t	size_;
public:
	Array<T>(void)
	{
		this->size_ = 0;
		this->array = new T[this->size_];
	}
	
	Array<T>(unsigned int n)
	{
		this->size_ = n;
		this->array = new T[this->size_];
	}
	
	Array<T>(Array const &src):Array(src.size())
	{
		for(size_t i = 0; i< src.size(); i++)
			this->array[i] = src[i];
	}
	
	Array<T>	&operator=(Array const &src)
	{
		delete[] (this->array);
		this->size_ = src.size();
		this->array = new T[this->size_];
		for(size_t i = 0; i < src.size(); i++)
			this->array[i] = src[i];
		return (*this);
	}

	T			&operator[](size_t i)
	{
		if (i < 0 || i > this->size_ - 1)
			throw (WrongIndexException());
		return (array[i]);
	}
	
	size_t	size(void) const
	{
		return (this->size_);
	}
	
	~Array<T>(void)
	{
		delete[] (this->array);
	}

	class WrongIndexException:public std::exception
	{
		const char *what() const throw()
			{
				return ("Wrong Index");
			}
	};
};

#endif
