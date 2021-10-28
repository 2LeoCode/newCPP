/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:22:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/26 17:19:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Ice.hpp"

#define M(memberName) Ice::memberName

M(Ice)() {
	_type = "ice";
	std::cout << "Ice constructor called" << std::endl;
}

M(~Ice)() {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria	*M(clone)(void) const {
	return (new Ice);
}

void	M(use)(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
