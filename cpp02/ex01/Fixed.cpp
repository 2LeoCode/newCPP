/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:55:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/20 22:26:10 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <sstream>

#include <cmath>
#include <climits>
#include <cstring>

#define M(memberName) Fixed::memberName

#define ABS(x) (((x) < 0) ? -(x) : (x))

#define PRINT_BITS(var); {\
	for (unsigned i = sizeof(var) * 8 - 1; i != UINT_MAX; --i) {\
		if (i && (i + 1) != sizeof(var) * 8 && !((i + 1) % 4))\
			std::cout << ' ';\
		std::cout << !!((var) & (1 << i));\
	}\
	std::cout << std::endl;\
}
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

M(Fixed)(const int value) {
	std::cout << "int constructor called" << std::endl;
	if (BYTE_ORDER == LITTLE_ENDIAN)
		_rawBits = (value << _nbBits);
	else if (BYTE_ORDER == BIG_ENDIAN)
		_rawBits = (value >> _nbBits);
}

M(Fixed)(const float value) {
	std::cout << "float constructor called" << std::endl;
	if (BYTE_ORDER == LITTLE_ENDIAN)
		_rawBits = std::roundf(value * (1 << _nbBits));
	else if (BYTE_ORDER == BIG_ENDIAN)
		_rawBits = std::roundf(value * (1 >> _nbBits));
}

Fixed	&M(operator=)(const Fixed src) {
	std::cout << "Assignation operator called" << std::endl;
	_rawBits = src._rawBits;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &nb) {
	out << nb.toFloat();
	return (out);
}

int	M(getRawBits)(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	M(setRawBits)(int rawBits) {
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = rawBits;
}

int	M(getNbBits)(void) const {
	return (_nbBits);
}

int	M(toInt)(void) const {
	if (BYTE_ORDER == LITTLE_ENDIAN)
		return (_rawBits >> _nbBits);
	return (_rawBits << _nbBits);
}

float	M(toFloat)(void) const {
	if (BYTE_ORDER == LITTLE_ENDIAN)
		return (static_cast<float>(_rawBits) / (1 << _nbBits));
	return (static_cast<float>(_rawBits) / (1 >> _nbBits));
}
