/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:38:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 15:17:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	public:

	Animal();
	virtual ~Animal();

	virtual void	makeSound(void) const;
	const std::string	&getType(void) const;

	protected:

	std::string	_type;
};

#endif //ANIMAL_HPP
