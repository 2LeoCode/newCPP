/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:27:22 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/16 18:07:15 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

#define M(memberName) HumanA::memberName

M(HumanA)(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) { }

M(~HumanA)() { }

void	M(attack)(void) const {
	std::cout << _name << " attacks with his " << _weapon.getType();
	std::cout << std::endl;
}
