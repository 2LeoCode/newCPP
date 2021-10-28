/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:48:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/19 01:11:45 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define BYTE_ORDER !!(1 << 1)
# define BIG_ENDIAN 1
# define LITTLE_ENDIAN 0

# include <iostream>

class Fixed {
	public:
	
	Fixed();
	~Fixed();

	Fixed(const Fixed &src);
	Fixed(const int value);
	Fixed(const float value);

	Fixed	&operator=(const Fixed src);

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int rawBits);
	int		getNbBits(void) const;
	int		toInt(void) const;
	float	toFloat(void) const;

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

	private:

	static const int	_nbBits;

	int					_rawBits;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &nb);

Fixed	operator+(Fixed a, Fixed b);
Fixed	operator-(Fixed a, Fixed b);
Fixed	operator*(Fixed a, Fixed b);
Fixed	operator/(Fixed a, Fixed b);

bool	operator>(Fixed a, Fixed b);
bool	operator<(Fixed a, Fixed b);
bool	operator>=(Fixed a, Fixed b);
bool	operator<=(Fixed a, Fixed b);
bool	operator==(Fixed a, Fixed b);
bool	operator!=(Fixed a, Fixed b);

#endif
