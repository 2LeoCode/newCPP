/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:00:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 15:19:39 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

#define M(memberName) Dog::memberName

M(Dog)() {
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

M(~Dog)() {
	std::cout << "Dog destructor called" << std::endl;
}

void	M(makeSound)(void) const {
	std::cout << "Bark" << std::endl;
}
