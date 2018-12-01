// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:35 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:35 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &src);
	~PlasmaRifle(void);
	PlasmaRifle &operator=(PlasmaRifle const &src);

	void		attack(void) const;
};

#endif