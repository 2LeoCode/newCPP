/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:13:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/26 16:20:39 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

#define M(memberName) AMateria::memberName

M(AMateria)() {
	std::cout << "AMateria constructor called" << std::endl;
}

M(~AMateria)() {
	std::cout << "AMateria destructor called" << std::endl;
}

M(AMateria)(const AMateria &other) : _type(other._type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria	&M(operator=)(const AMateria &other) {
	_type = other._type;
	return (*this);
}

const std::string	&M(getType)(void) const {
	return (_type);
}
