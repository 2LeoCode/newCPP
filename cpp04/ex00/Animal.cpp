/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 15:19:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

#define M(memberName) Animal::memberName

M(Animal)() : _type("???") {
	std::cout << "Animal constructor called" << std::endl;
}

M(~Animal)() {
	std::cout << "Animal destructor called" << std::endl;
}

void	M(makeSound)(void) const {
	std::cout << "???" << std::endl;
}

const std::string	&M(getType)(void) const {
	return (_type);
}
