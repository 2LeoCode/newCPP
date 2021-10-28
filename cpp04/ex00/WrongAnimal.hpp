/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:38:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 17:06:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	public:

	WrongAnimal();
	virtual ~WrongAnimal();

	virtual void	makeSound(void) const;
	const std::string	&getType(void) const;

	protected:

	std::string	_type;
};

#endif //WRONGANIMAL_HPP
