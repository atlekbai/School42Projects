// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:01 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:01 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main(void)
{
	Character atlekbai("Ali");
	Character otimofie("Lesha");
	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();
	Enemy *mutant = new SuperMutant();
	Enemy *scorp = new RadScorpion();

	std::cout << atlekbai << otimofie;
	
	atlekbai.attack(mutant);
	
	atlekbai.equip(pr);
	otimofie.equip(pf);
	
	std::cout << atlekbai << otimofie;
	
	atlekbai.attack(mutant);
	otimofie.attack(mutant);
	atlekbai.attack(mutant);
	atlekbai.attack(mutant);
	otimofie.attack(mutant);
	otimofie.attack(mutant);
	otimofie.attack(mutant);
	
	std::cout << atlekbai << otimofie;
	
	atlekbai.recoverAP();
	atlekbai.recoverAP();
	atlekbai.recoverAP();
	atlekbai.recoverAP();

	otimofie.recoverAP();
	otimofie.recoverAP();
	otimofie.recoverAP();
	otimofie.recoverAP();

	std::cout << atlekbai << otimofie;

	atlekbai.attack(scorp);
	otimofie.attack(scorp);
	atlekbai.attack(scorp);
	atlekbai.attack(scorp);
	otimofie.attack(scorp);

	std::cout << atlekbai << otimofie;
	return 0;
}