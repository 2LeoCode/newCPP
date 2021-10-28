/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:51:14 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 00:54:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

#define M(memberName) FragTrap::memberName

M(FragTrap)() {
	_hp = 100;
	_ep = 100;
	_dmg = 30;
	_type = "FragTrap";
	announceBegin();
}

M(~FragTrap)() {
	announceEnd();
}

M(FragTrap)(std::string name) : ClapTrap(name) {
	_hp = 100;
	_ep = 100;
	_dmg = 30;
	_type = "FragTrap";
	announceBegin();
}

void	M(highFiveGuys)(void) const {
	std::cout << '<' << _name <<
	"> I request a high five with positivity!" << std::endl;
}
