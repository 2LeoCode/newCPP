/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 23:41:00 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

#define M(memberName) Cat::memberName

M(Cat)() {
	static int	cnt = 0;
	_type = "Cat";
	_brain = new Brain;
	std::cout << "Cat constructor called " << ++cnt << std::endl;
}

M(~Cat)() {
	static int	cnt = 0;
	delete _brain;
	std::cout << "Cat destructor called " << ++cnt << std::endl;
}

M(Cat)(const Cat &other) {
	static int	cnt = 0;
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called " << ++cnt << std::endl;
}

void	M(makeSound)(void) const {
	std::cout << "Meow" << std::endl;
}
