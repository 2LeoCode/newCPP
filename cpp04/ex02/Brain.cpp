/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:31:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 23:41:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

#define M(memberName) Brain::memberName

M(Brain)() {
	static int	cnt = 0;
	std::cout << "Brain constructor called " << ++cnt << std::endl;
}

M(~Brain)() {
	static int	cnt = 0;
	std::cout << "Brain destructor called " << ++cnt << std::endl;
}

M(Brain)(const Brain &other) {
	static int	cnt = 0;
	for (unsigned i = 0; i < 100; ++i) {
		_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy constructor called " << ++cnt << std::endl;
}

Brain	&M(operator=)(const Brain &other) {
	for (unsigned i = 0; i < 100; ++i) {
		_ideas[i] = other._ideas[i];
	}
	return (*this);
}
