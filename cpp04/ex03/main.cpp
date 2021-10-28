/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:23:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/26 20:17:41 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "UniquePtr.hpp"
#include "UniqueArrPtr.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#define DC dynamic_cast

AMateria	*newRandomMateria(void) {
	int	i = random() % 3;

	if (!i)
		return (new Ice);
	if (i == 1)
		return (new Cure);
	return nullptr;
}

int	main(void) {
	srandom(time(NULL));
	UniqueArrPtr< UniquePtr< ICharacter > >	characters;
	UniqueArrPtr< UniquePtr< AMateria > >	materias;
	UniquePtr< ICharacter >					dummy;

	try {
		dummy = new Character("dummy");
		characters = new UniquePtr< ICharacter >[3];
		materias = new UniquePtr< AMateria >[12];

		for (unsigned i = 0; i < 12; ++i) materias[i] = newRandomMateria();
		characters[0] = new Character("Josephin");
		characters[1] = new Character("Jean-Damien");
		characters[2] = new Character("Joceline");
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	for (unsigned i = 0; i < 3; ++i) {
		for (unsigned j = 0; j < 4; ++j)
			characters[i]->equip(materias[i * 4 + j].ptr());
	}
	for (unsigned i = 0; i < 3; ++i)
		for (unsigned j = 0; j < 4; ++j) characters[i]->use(j, *dummy);
	std::cout << "/****************************************************************\\" <<
	std::endl << "|************************COPY CONSTRUCTOR************************|" <<
	std::endl << "\\****************************************************************/" << std::endl;
	UniquePtr< ICharacter >					constructCpy, assignCpy;

	try {
		constructCpy = new Character(*characters[0]);
		assignCpy = new Character("foo");
		*assignCpy = *characters[1];
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	DC < Character* >(&*constructCpy)->deleteInventory();
	DC < Character* >(&*assignCpy)->deleteInventory();
	return 0;
}
