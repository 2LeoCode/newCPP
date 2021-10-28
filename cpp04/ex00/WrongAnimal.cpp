/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 17:11:34 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

#define M(memberName) WrongAnimal::memberName

M(WrongAnimal)() : _type("???") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

M(~WrongAnimal)() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	M(makeSound)(void) const {
	std::cout << "???" << std::endl;
}

const std::string	&M(getType)(void) const {
	return (_type);
}
