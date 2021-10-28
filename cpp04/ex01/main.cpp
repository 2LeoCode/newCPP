/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:38:01 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 23:59:33 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "UniquePtr.hpp"
#include "UniqueArrPtr.hpp"

#include <iostream>
#include <sstream>

#ifdef COPYTEST

int	main(void) {
	UniquePtr< Cat > dstCat, srcCat;
	UniquePtr< Dog > dstDog, srcDog;

	try {
		srcCat = new Cat(), srcDog = new Dog();
		dstCat = new Cat(*srcCat), dstDog = new Dog(*srcDog);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	dstCat->makeSound();
	dstDog->makeSound();
	return (0);
}

#else

int	main(int argc, char **argv) {
	if (argc != 2 || std::string(argv[1]).find_first_not_of("0123456789")
	!= std::string::npos) {
		std::cout << "Usage: " << argv[0] << " <arraySize>" << std::endl;
		return 1;
	}
	unsigned	size;
	std::istringstream(argv[1]) >> size;
	UniqueArrPtr< UniquePtr< Animal > >	animalArr;

	try {
		animalArr = new UniquePtr< Animal >[size];
		for (unsigned i = 0; i < size / 2; ++i)
			animalArr[i] = new Cat();
		for (unsigned i = size / 2; i < size; ++i)
			animalArr[i] = new Dog();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	for (unsigned i = 0; i < size; ++i)
		animalArr[i]->makeSound();
	return 0;
}

#endif