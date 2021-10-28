/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:25:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/27 15:54:33 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int	main(void) {
	std::cout << "Creating an unnamed bureaucrat with grade 150" << std::endl;
	std::cout << "Creating bureaucrat jack with grade 150" << std::endl;
	std::cout << "Creating bureaucrat joe with grade 1" << std::endl;
	Bureaucrat	a, b("jack"), c("joe", 1);

	try {
		std::cout << "Creating bureaucrat dummy with grade 151" << std::endl;
		Bureaucrat	d("dummy", 151); // GradeTooLowException
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}
	try {
		std::cout << "Creating bureaucrat dummy with grade 0" << std::endl;
		Bureaucrat	e("dummy", 0); // GradeTooHighException
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}
	try {
		std::cout << "Upgrading " << a.getName() << std::endl;
		a.upgrade();
		std::cout << "Upgrading " << c.getName() << std::endl;
		c.upgrade(); // GradeTooHighException
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}
	try {
		std::cout << "Downgrading " << c.getName() << std::endl;
		c.downgrade();
		std::cout << "Downgrading " << b.getName() << std::endl;
		b.downgrade(); // GradeTooLowException
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}
	std::cout << a << std::endl << b << std::endl << c << std::endl;
	return 0;
}