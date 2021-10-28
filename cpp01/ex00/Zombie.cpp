/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:35:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/23 21:51:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

#define M(memberName) Zombie::memberName

M(Zombie)() : _name("unnamed") { }

M(~Zombie)() {
	std::cout << "Zombie " << _name << " died" << std::endl;
}

M(Zombie)(const std::string name) : _name(name) { }

void	M(announce)(void) {
	std::cout << '<' << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
