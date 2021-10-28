/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:58:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 00:16:54 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "UniqueArrPtr.hpp"

#include <iostream>

#include <cstdlib>
#include <ctime>

Zombie	*zombieHorde(int N, std::string name);

static int	randomBetween(int min, int max) {
	return (min + random() % (max - min + 1));
}

static void	unleashHorde(size_t hordeSize, UniqueArrPtr< Zombie > &horde) {
	for (size_t i = 0; i < hordeSize; ++i)
		horde[i].announce();
}

int	main(int argc, char **argv) {
	if (argc == 1) return (0);
	UniqueArrPtr< Zombie >	hordes[argc - 1];
	size_t	hordeSizes[argc - 1];

	srandom(std::time(NULL));
	for (int i = 1; i < argc; ++i) {
		hordeSizes[i - 1] = static_cast<size_t>(randomBetween(5, 20));
		std::cout << "Creating a horde with " << hordeSizes[i - 1];
		std::cout << " zombies named " << argv[i] <<  std::endl;
		try {
			hordes[i - 1] = zombieHorde(hordeSizes[i - 1], argv[i]);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (-1);
		}
	}
	std::cout << std::endl << std::endl << "Unleashing hordes" << std::endl;
	for (int i = 0; i < argc - 1; ++i) {
		unleashHorde(hordeSizes[i], hordes[i]);
		std::cout << std::endl;
	}
	std::cout << std::endl << "Destroying hordes" << std::endl;
	return (0);
}
