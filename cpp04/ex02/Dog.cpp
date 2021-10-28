/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:00:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 23:40:03 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

#define M(memberName) Dog::memberName

M(Dog)() {
	static int	cnt = 0;
	_type = "Dog";
	_brain = new Brain;
	std::cout << "Dog constructor called " << ++cnt << std::endl;
}

M(~Dog)() {
	static int	cnt = 0;
	delete _brain;
	std::cout << "Dog destructor called " << ++cnt << std::endl;
}

M(Dog)(const Dog &other) {
	static int	cnt = 0;

	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called " << ++cnt << std::endl;
}

void	M(makeSound)(void) const {
	std::cout << "Bark" << std::endl;
}
