// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/28 17:12:04 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/28 17:12:04 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <vector>

template<typename T>
class MutantStack
{
private:
	std::vector<T>	stack;
public:
	MutantStack<T>(void){}
	
	~MutantStack<T>(void){}
	
	MutantStack<T>(MutantStack<T> const &src)
	{
		*this = src;
	}

	MutantStack		&operator=(MutantStack const &src)
	{
		this->stack = src.getStack();
		return (*this);
	}

	void			push(T const &t)
	{
		stack.push_back(t);
	}

	void			pop(void)
	{
		stack.pop_back();
	}

	size_t			size(void) const
	{
		return (stack.size());
	}

	T				&top(void)
	{
		return (stack.back());
	}

	std::vector<T>	getStack(void) const
	{
		return (stack);
	}

	std::vector<T> 	&operator()(void)
	{
		return (stack);
	}

	class iterator
	{
	private:
		MutantStack &m;
		int			index;
	public:
		iterator(MutantStack &m):m(m), index(0){}
		iterator(MutantStack &m, bool):m(m), index(m.size() - 1){}

		T 		operator*(void)
		{
			return (m.getStack().at(index));
		}

		int		operator++(void)
		{
			return (m.getStack().at(++index));
		}

		int		operator--(void)
		{
			return (m.getStack().at(--index));
		}

		bool	operator!=(const iterator &c) const
		{
			return (index != c.getIndex());
		}

		int		getIndex(void) const
		{
			return (this->index);
		}
	};

	iterator		begin(void)
	{
		return (iterator(*this));
	}

	iterator		end(void)
	{
		return (iterator(*this, true));
	}
};

#endif