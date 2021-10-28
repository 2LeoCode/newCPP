/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 15:01:04 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

#define M(memberName) Cat::memberName

M(Cat)() {
	_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

void	M(makeSound)(void) const {
	std::cout << "Meow" << std::endl;
}

M(~Cat)() {
	std::cout << "Cat destructor called" << std::endl;
}
