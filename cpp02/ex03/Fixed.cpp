/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:55:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/20 22:24:22 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <climits>
#include <iomanip>

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

M(Fixed)() : _rawBits(0) { }

M(~Fixed)() { }

M(Fixed)(const Fixed &src) : _rawBits(src._rawBits) { }

M(Fixed)(const int value) {
	if (BYTE_ORDER == LITTLE_ENDIAN)
		_rawBits = (value << _nbBits);
	else if (BYTE_ORDER == BIG_ENDIAN)
		_rawBits = (value >> _nbBits);
}

M(Fixed)(const float value) {
	if (BYTE_ORDER == LITTLE_ENDIAN)
		_rawBits = std::roundf(value * (1 << _nbBits));
	else if (BYTE_ORDER == BIG_ENDIAN)
		_rawBits = std::roundf(value * (1 >> _nbBits));
}

Fixed	&M(operator=)(const Fixed src) {
	_rawBits = src._rawBits;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &nb) {
	out << nb.toFloat();
	return (out);
}

bool	operator>(Fixed a, Fixed b) {
	return (a.getRawBits() > b.getRawBits());
}

bool	operator<(Fixed a, Fixed b) {
	return (!(a >= b));
}

bool	operator>=(Fixed a, Fixed b) {
	return (a == b  || a > b);
}

bool	operator<=(Fixed a, Fixed b) {
	return (!(a > b));
}

bool	operator==(Fixed a, Fixed b) {
	return (a.getRawBits() == b.getRawBits());
}

bool	operator!=(Fixed a, Fixed b) {
	return (!(a == b));
}

Fixed	operator+(Fixed a, Fixed b) {
	Fixed	ret;

	ret.setRawBits(a.getRawBits() + b.getRawBits());
	return (ret);
}

Fixed	operator-(Fixed a, Fixed b) {
	Fixed	ret;


	ret.setRawBits(a.getRawBits() - b.getRawBits());
	return (ret);
}

Fixed	operator*(Fixed a, Fixed b) {
	Fixed	ret;

	if (BYTE_ORDER == LITTLE_ENDIAN)
		ret.setRawBits((a.getRawBits() * b.getRawBits()) >> a.getNbBits());
	else if (BYTE_ORDER == BIG_ENDIAN)
		ret.setRawBits((a.getRawBits() * b.getRawBits()) << a.getNbBits());
	return (ret);
}

Fixed	operator/(Fixed a, Fixed b) {
	Fixed	ret;

	if (BYTE_ORDER == LITTLE_ENDIAN)
		ret.setRawBits((a.getRawBits() << a.getNbBits()) / b.getRawBits());
	else if (BYTE_ORDER == BIG_ENDIAN)
		ret.setRawBits((a.getRawBits() >> a.getNbBits()) / b.getRawBits());
	return (ret);
}

Fixed	&M(operator++)(void) {

	++_rawBits;
	return (*this);
}

Fixed	M(operator++)(int) {
	Fixed	ret(*this);

	++*this;
	return (ret);
}

Fixed	&M(operator--)(void) {
	--_rawBits;
	return (*this);
}

Fixed	M(operator--)(int) {
	Fixed	ret(*this);

	--*this;
	return (ret);
}

int	M(getRawBits)(void) const {
	return (_rawBits);
}

void	M(setRawBits)(int rawBits) {
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

Fixed	&M(min)(Fixed &a, Fixed &b) {
	if (a > b) return (b);
	return (a);
}

const Fixed	&M(min)(const Fixed &a, const Fixed &b) {
	if (a > b) return (b);
	return (a);
}

Fixed	&M(max)(Fixed &a, Fixed &b) {
	if (a < b) return (b);
	return (a);
}

const Fixed	&M(max)(const Fixed &a, const Fixed &b) {
	if (a < b) return (b);
	return (a);
}
