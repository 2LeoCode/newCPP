/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:24:51 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/17 01:20:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

# include <string>

class HumanA {
	public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack(void) const;

	private:

	std::string	_name;
	Weapon		&_weapon;
};

/*
** In this case, HumanA will always have a weapon, so we don't need to worry
** about the case where `_weapon` will be null. Still we need to use a
** reference to store the weapon as we want to be able to access it outside of
** the class.
*/

#endif
