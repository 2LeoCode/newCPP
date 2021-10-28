/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:24:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/20 22:13:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	public:

	Point();
	~Point();

	Point(const Point &other);
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);

	Point	&operator=(const Point &other);

	const Fixed	getX(void) const;
	const Fixed	getY(void) const;

	private:

	const Fixed	_x;
	const Fixed	_y;
};

bool	operator==(const Point &a, const Point &b);

#endif //POINT_HPP
