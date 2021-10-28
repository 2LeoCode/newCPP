/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 17:06:41 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

#define M(memberName) WrongCat::memberName

M(WrongCat)() {
	_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

M(~WrongCat)() {
	std::cout << "WrongCat destructor called" << std::endl;
}
