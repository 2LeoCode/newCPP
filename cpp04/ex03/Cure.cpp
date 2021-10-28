/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:27:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/26 17:19:34 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cure.hpp"

#define M(memberName) Cure::memberName

M(Cure)() {
	_type = "cure";
	std::cout << "Cure constructor called" << std::endl;
}

M(~Cure)() {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria	*M(clone)(void) const {
	return (new Cure);
}

void	M(use)(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
