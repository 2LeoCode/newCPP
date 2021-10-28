/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:13:27 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/20 22:15:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define ABSF(x) ((x) < Fixed(0) ? Fixed(-1) * (x) : (x))

bool	bsp(const Point a, const Point b, const Point c, const Point p) {
	if (a == p || b == p || c == p) return (true);
	const Point	ap(Fixed(p.getX() - a.getX()), Fixed(p.getY() - a.getY())),
				bp(Fixed(p.getX() - b.getX()), Fixed(p.getY() - b.getY())),
				ab(Fixed(b.getX() - a.getX()), Fixed(b.getY() - a.getY())),
				ac(Fixed(c.getX() - a.getX()), Fixed(c.getY() - a.getY())),
				bc(Fixed(c.getX() - b.getX()), Fixed(c.getY() - b.getY()));

	bool	p_ab(ab.getX() * ap.getY() - ab.getY() * ap.getX() > Fixed(0)),
			p_ac(ac.getX() * ap.getY() - ac.getY() * ap.getX() > Fixed(0)),
			p_bc(bc.getX() * bp.getY() - bc.getY() * bp.getX() > Fixed(0));
	return (p_ab != p_ac && p_bc == p_ab);
}
