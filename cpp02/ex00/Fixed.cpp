/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:55:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/17 18:12:45 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

#define M(memberName) Fixed::memberName

const int	M(_nbBits)(8);

M(Fixed)() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

M(~Fixed)() {
	std::cout << "Destructor called" << std::endl;
}

M(Fixed)(const Fixed &src) : _rawBits(src._rawBits) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&M(operator=)(const Fixed src) {
	std::cout << "Assignation operator called" << std::endl;
	_rawBits = src._rawBits;
	return (*this);
}

int	M(getRawBits)(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	M(setRawBits)(int rawBits) {
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = rawBits;
}
