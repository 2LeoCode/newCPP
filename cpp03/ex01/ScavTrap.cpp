#include "ScavTrap.hpp"

#include <iostream>

#define M(memberName) ScavTrap::memberName

M(ScavTrap)() : ClapTrap() {
	announceBegin();
	_hp = 100;
	_ep = 50;
	_dmg = 10;
	_type = "ScavTrap";
}

M(~ScavTrap)() {
	announceEnd();
}

M(ScavTrap)(std::string name) : ClapTrap(name) {
	_hp = 100;
	_ep = 50;
	_dmg = 10;
	_type = "ScavTrap";
	announceBegin();
}

void	M(guardGate)(void) {
	if (_ep < 2) throw (_type + ' ' + _name + " is out of energy.");
	_ep -= 2;
	std::cout << _type << ' ' << _name <<
	" has entered in Gate Keeper mode. BE AWARE" << std::endl;
	if (_debugInfo) debugInfo();
}
