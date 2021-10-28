/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:38:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/26 20:13:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

#include "Character.hpp"

#define M(memberName) Character::memberName
#define DC dynamic_cast
#define SC static_cast

M(Character)() : _name("unnamed"), _itemCnt() {
	std::cout << "Character constructor called" << std::endl;
}

M(~Character)() {
	std::cout << "Character destructor called" << std::endl;
}

M(Character)(const ICharacter &other) {
	const Character	&src = DC<const Character &>(other);

	_name = src._name;
	_itemCnt = src._itemCnt;
	for (unsigned i = 0; i < _itemCnt; ++i) {
		try {
			_inventory[i] = src._inventory[i]->clone();
		} catch (std::exception &e) {
			for (unsigned j = i; --j;) {
				delete _inventory[j];
			}
			throw (e);
		}
	}
}

M(Character)(std::string name) : _name(name), _itemCnt() {
	std::cout << "Character name constructor called" << std::endl;
}

Character	&M(operator=)(const ICharacter &other) {
	const Character	&src = DC<const Character &>(other);

	_name = src._name;
	_itemCnt = src._itemCnt;
	for (unsigned i = 0; i < _itemCnt; ++i) {
		try {
			_inventory[i] = src._inventory[i]->clone();
		} catch (std::exception &e) {
			for (unsigned j = i; --j != ~0U;) {
				delete _inventory[j];
			}
			throw (e);
		}
	}
	return (*this);
}

std::string const	&M(getName)() const {
	return (_name);
}

void				M(equip)(AMateria *m) {
	if (m && _itemCnt < 4)
		_inventory[_itemCnt++] = m;
}

void				M(unequip)(int idx) {
	if (idx >= 0 && idx < 4 && idx != SC< int >(--_itemCnt))
		memcpy(_inventory + idx, _inventory + idx + 1,
			(_itemCnt - idx) * sizeof(*_inventory));
}

void				M(use)(int idx, ICharacter &target) {
	if (idx >= 0 && idx < SC< int >(_itemCnt))
		_inventory[idx]->use(target);
}

void				M(deleteInventory)(void) {
	while (_itemCnt)
		delete _inventory[--_itemCnt];
}
