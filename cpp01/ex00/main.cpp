/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:41:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 00:16:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "UniquePtr.hpp"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void) {
	{
		// BAD

		Zombie	*joe, *bob, *marco;

		joe = bob = marco = nullptr;
		try {
			joe = new Zombie("joe");
			bob = new Zombie("bob");
			marco = new Zombie("marco");
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			delete joe;
			delete bob;
			return (-1);
		}
		joe->announce();
		bob->announce();
		marco->announce();

		delete joe;
		delete bob;
		delete marco;
	}
	std::cout << std::endl;
	{
		// GOOD

		Zombie	joe("joe");
		Zombie	bob("bob");
		Zombie	marco("marco");

		joe.announce();
		bob.announce();
		marco.announce();
	}
	std::cout << std::endl;
	{
		// ALSO GOOD

		UniquePtr< Zombie >	joe, bob, marco;

		try {
			joe = new Zombie("joe");
			bob = new Zombie("bob");
			marco = new Zombie("marco");
			// I use a wrapper class to handle the pointer deletion for me
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (-1);
		}
		joe->announce();
		bob->announce();
		marco->announce();
	}
	std::cout << std::endl;
	randomChump("random");
	return (0);
}
