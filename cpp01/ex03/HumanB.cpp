/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:49:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/16 18:05:33 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

#define M(memberName) HumanB::memberName

M(HumanB)(std::string name) : _name(name), _weapon(nullptr) { }

M(~HumanB)() { }

void	M(setWeapon)(Weapon &weapon) {
	_weapon = &weapon;
}

void	M(attack)(void) const {
	if (!_weapon) throw (std::runtime_error(_name + " has no weapon"));
	std::cout << _name << " attacks with his " << _weapon->getType();
	std::cout << std::endl;
}
