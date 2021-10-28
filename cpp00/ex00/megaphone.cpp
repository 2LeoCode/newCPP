/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 01:21:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/16 16:04:18 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>

typedef std::string::iterator	string_iterator;

namespace ft {
	int	toupper(char c) {
		return (std::toupper(static_cast<unsigned char>(c)));
	}
}

int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		std::string	msg;

		for (int i = 1; i < argc; ({ if (++i != argc) std::cout << ' '; })) {
			msg = argv[i];
			for (string_iterator it = msg.begin(); it != msg.end(); ++it)
				*it = ft::toupper(*it);
			std::cout << msg;
		}
	}
	std::cout << std::endl;
	return (0);
}
