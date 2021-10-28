/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:35:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/23 22:40:06 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

#define M(memberName) Zombie::memberName

M(Zombie)() : _name("unnamed") { }

M(Zombie)(std::string &name) : _name(name) { }

M(~Zombie)() {
	std::cout << "Zombie " << _name << " died" << std::endl;
}

Zombie	M(operator=)(const Zombie &src) {
	_name = src._name;
	return (*this);
}

void	M(announce)(void) {
	std::cout << '<' << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void M(setName)(std::string name) {
	_name = name;
}
