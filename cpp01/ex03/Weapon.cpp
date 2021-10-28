/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:17:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/16 18:04:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#define M(memberName) Weapon::memberName

M(Weapon)(std::string type) : _type(type) { }

M(~Weapon)() { }

const std::string	&M(getType)(void) const {
	return (_type);
}

void	M(setType)(std::string newType) {
	_type = newType;
}
