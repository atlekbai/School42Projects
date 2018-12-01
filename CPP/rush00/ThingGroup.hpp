/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ThingGroup.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:37:45 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:33:06 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_FIELD_HPP
# define OBJECT_FIELD_HPP

#include "Rect.hpp"
#include "SpaceThing.hpp"


class ThingGroup
{
private:
	Rect		field_end;
	SpaceThing	**objects;
	int			n;

public:
	ThingGroup &operator=(ThingGroup const & rhs);

	ThingGroup(const ThingGroup& toCopy);
	ThingGroup(void);
	~ThingGroup(void);

	void update(void);
	void erase(unsigned);
	void setend(Rect);

	SpaceThing **getData(void) const;
	int			addData(SpaceThing *s);
	int			getN(void) const;
};

#endif