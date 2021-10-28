/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/25 14:10:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

#define M(memberName) Animal::memberName

M(Animal)() {
	static int	cnt = 0;
	std::cout << "Animal constructor called " << ++cnt << std::endl;
}

M(~Animal)() {
	static int	cnt = 0;
	std::cout << "Animal destructor called " << ++cnt << std::endl;
}

const std::string	&M(getType)(void) const {
	return (_type);
}
