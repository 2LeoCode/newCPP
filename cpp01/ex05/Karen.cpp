/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:21:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/17 02:08:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <iostream>

#define M(memberName) Karen::memberName

std::string	M(_debugMsg)("I love to get extra bacon for my "
"XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!");

std::string	M(_infoMsg)("I cannot believe adding extra bacon cost more money."
"You don’t put enough! If you did I would not have to ask for it!");

std::string	M(_warningMsg)("I think I deserve to have some extra bacon for "
"free. I’ve been coming here for years and you just started working here last "
"month.");

std::string	M(_errorMsg)("This is unacceptable, I want to speak to the "
"manager now.");

const char		*M(_levelStr)[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

M(ComplainFun)	M(_levelFun)[4] = { &M(debug), &M(info), &M(warning), &M(error) };

M(Karen)() { }

M(~Karen)() { }

void	M(debug)(void) {
	std::cout << _debugMsg << std::endl;
}

void	M(info)(void) {
	std::cout << _infoMsg << std::endl;
}

void	M(warning)(void) {
	std::cout << _warningMsg << std::endl;
}

void	M(error)(void) {
	std::cout << _errorMsg << std::endl;
}

void	M(complain)(std::string level) {
	for (unsigned i = 0; i < 4; ++i)
		if (level == _levelStr[i]) (this->*_levelFun[i])();
}
