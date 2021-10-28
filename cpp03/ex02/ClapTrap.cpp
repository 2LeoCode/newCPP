/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:30:09 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 21:13:35 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

#define SC static_cast
#define M(memberName) ClapTrap::memberName

M(ClapTrap)() : _type("ClapTrap"), _name("unnamed"), _hp(10), _ep(10), _dmg(0),
	_debugInfo(false) {
	announceBegin();
}

M(~ClapTrap)() {
	_type = "ClapTrap";
	announceEnd();
}

M(ClapTrap)(const ClapTrap &other) : _type("ClapTrap"), _name(other._name), _hp(other._hp),
	_ep(other._ep), _dmg(other._dmg), _debugInfo(false) {
	announceBegin();	
}

M(ClapTrap)(std::string name) : _type("ClapTrap"), _name(name), _hp(10), _ep(10), _dmg(0),
	_debugInfo(false) {
	announceBegin();
}

ClapTrap	&M(operator=)(const ClapTrap &other) {
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_dmg = other._dmg;
	return (*this);
}

void	M(attack)(std::string const &target) {
	if (!_hp) throw (_type + ' ' + _name + " is not operational.");
	if (!_ep) throw (_type + ' ' + _name + " is out of energy.");
	--_ep;
	std::cout << _type << ' ' << _name << " attacks " << target;
	std::cout << ", causing " << _dmg << " points of damage!" << std::endl;
	std::cout << '<' << _name << "> Yaaaaaah! 360 no-scope in your face!" << std::endl;
	if (_debugInfo) debugInfo();
}

void	M(takeDamage)(unsigned amount) {
	if (_hp <= 0) throw (_type + ' ' + _name + " has already been destroyed.");
	std::cout << _type << ' ' << _name << " took " << amount;
	std::cout << " points of damage!" << std::endl;
	std::cout << '<' << _name << "> Hey that hurts! ...wait, I'm a robot,"
	"I don't feel the pain, I'm invincible! MWAHAHAHAHAHA!" << std::endl;
	if (amount >= SC<unsigned>(_hp)) {
		std::cout << _type << ' ' << _name << " has been destroyed!";
		std::cout << std::endl;
		std::cout << '<' << _name << "> Segmentation fault. (core dumped)" << std::endl;
		_hp = 0;
	} else _hp -= amount;
	if (_debugInfo) debugInfo();
}

void	M(beRepaired)(unsigned amount) {
	if (_hp <= 0) throw (_type + ' ' + _name + " can't be saved anymore.");
	_hp += amount;
	std::cout << _type << ' ' << _name;
	std::cout << " has been repaired for " << amount << " HP!" << std::endl;
	std::cout << '<' << _name << "> Mmmmh... that feels good!" << std::endl;
	if (_debugInfo) debugInfo();
}

std::string	M(getName)(void) const {
	return (_name);
}

int	M(getHp)(void) const {
	return (_hp);
}

int	M(getEp)(void) const {
	return (_ep);
}

int	M(getDmg)(void) const {
	return (_dmg);
}

void	M(setName)(std::string name) {
	_name = name;
}

void	M(setHp)(int hp) {
	_hp = hp;
}

void	M(setEp)(int ep) {
	_ep = ep;
}

void	M(setDmg)(int dmg) {
	_dmg = dmg;
}

void	M(announceBegin)(void) const {
	std::cout << "Created " << _type << ' ' << _name << std::endl;
	std::cout << "HP:\t" << _hp << std::endl;
	std::cout << "EP:\t" << _ep << std::endl;
	std::cout << "DMG:\t" << _dmg << std::endl;
}

void	M(announceEnd)(void) const {
	std::cout << "Destroyed " << _type << ' ' << _name << std::endl;
}

void	M(enableDebugInfos)(void) {
	_debugInfo = true;
}

void	M(debugInfo)(void) const {
	std::cerr << '\"' << _type << ' ' << _name << "\": {" << std::endl;
	std::cerr << "\t\"healthPoints\": " << _hp << ',' << std::endl;
	std::cerr << "\t\"energyPoints\": " << _ep << ',' << std::endl;
	std::cerr << "\t\"attackDamage\": " << _dmg << std::endl;
	std::cerr << '}' << std::endl;
}
