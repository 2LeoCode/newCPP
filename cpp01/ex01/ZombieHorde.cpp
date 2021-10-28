/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:46:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/23 22:40:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*horde;

	try {
		horde = new Zombie[N];
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (nullptr);
	}
	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}
	return (horde);
}
