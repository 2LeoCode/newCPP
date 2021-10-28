/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:24:58 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/20 22:14:54 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define M(memberName) Point::memberName

M(Point)() : _x(0), _y(0) { }

M(~Point)() { }

M(Point)(const Point &other) : _x(other._x), _y(other._y) { }

M(Point)(const float x, const float y) : _x(x), _y(y) { }

M(Point)(const Fixed x, const Fixed y) : _x(x), _y(y) { }

Point	&M(operator=)(const Point &other) {
	(void)other;
	return (*this);
}

bool	operator==(const Point &a, const Point &b) {
	return (a.getX() == b.getX() && a.getY() == b.getY());
}

const Fixed	M(getX)(void) const {
	return (_x);
}

const Fixed	M(getY)(void) const {
	return (_y);
}
