/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:48:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/20 02:12:53 by Leo Suardi       ###   ########.fr       */
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

	int		getRawBits(void) const;
	void	setRawBits(int rawBits);
	int		getNbBits(void) const;
	int		toInt(void) const;
	float	toFloat(void) const;

	private:

	static const int	_nbBits;

	int					_rawBits;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &nb);

#endif
