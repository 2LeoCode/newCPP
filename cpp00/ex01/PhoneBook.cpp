/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:52:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/17 02:08:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>
#include <cstring>

#define M(memberName) PhoneBook::memberName

typedef std::string::iterator	string_iterator;

namespace ft {
	bool	isspace(char c) {
		return (std::isspace(static_cast<unsigned char>(c)));
	}
	bool	isdigit(char c) {
		return (std::isdigit(static_cast<unsigned char>(c)));
	}
	bool	isalpha(char c) {
		return (std::isalpha(static_cast<unsigned char>(c)));
	}
}

M(PhoneBook)() : _contactCnt(0) {
}

M(~PhoneBook)() {
	std::cout << "Destructor has been called" << std::endl;
}

static std::string	getInput(const char *msg) {
	std::string	inputLine;

	std::cout << msg << ": ";
	std::getline(std::cin, inputLine);
	return (inputLine);
}

static std::string	getWord(const char *msg) {
	std::string	inputLine;
	bool		validInput(false);

	while (!validInput) {
		std::cout << msg << " [a-z/A-Z]: ";
		std::getline(std::cin, inputLine);
		string_iterator	it(inputLine.begin());

		while (it != inputLine.end() && ft::isspace(*it)) ++it;
		while (it != inputLine.end() && ft::isalpha(*it)) ++it;
		while (it != inputLine.end() && ft::isspace(*it)) ++it;
		if (it == inputLine.end()) validInput = true;
		else std::cerr << "INVALID INPUT" << std::endl;
	}
	return (inputLine);
}

static std::string	getPhoneNumber(const char *msg) {
	std::string		finalStr;
	while (42) {
		std::string		inputLine;
	
		std::cout << msg << " [0-9]: ";
		std::getline(std::cin, inputLine);

		string_iterator it(inputLine.begin());
		unsigned		cnt(0);

		finalStr = "";
		while (it != inputLine.end()) {
			if (!ft::isspace(*it) && !ft::isdigit(*it)) break ;
			while (it != inputLine.end() && ft::isspace(*it)) ++it;
			while (it != inputLine.end() && ft::isdigit(*it)) {
				if (cnt && !(cnt % 2)) finalStr += ' ';
				if (++cnt > 10) goto end_loop;
				finalStr += *it++;
			}
		}
		end_loop:
		if (cnt == 10 && it == inputLine.end()) break ;
		else std::cout << "INVALID INPUT" << std::endl;
	}
	return (finalStr);
}

void	M(add)(void) {
	if (_contactCnt == MAX_CONTACTS) {
		std::cerr << "PHONEBOOK IS FULL" << std::endl;
		return ;
	}
	_contact[_contactCnt].firstName = getWord("FIRST NAME");
	_contact[_contactCnt].lastName = getWord("LAST NAME");
	_contact[_contactCnt].nickname = getInput("NICKNAME");
	_contact[_contactCnt].phoneNumber = getPhoneNumber("PHONE NUMBER");
	_contact[_contactCnt++].darkestSecret = getInput("DARKEST SECRET");
}

std::string	M(formatField)(unsigned field) {
	std::ostringstream	stream;

	stream << std::setw(10) << field << std::setw(0);
	return (stream.str());
}

std::string	M(formatField)(std::string &field) {
	std::ostringstream	stream;

	if (field.length() > 10)
		stream << std::string(field.begin(), field.begin() + 9) << '.';
	else stream << std::setw(10) << field << std::setw(0);
	return (stream.str());
}

std::string	M(formatField)(const char *field) {
	std::ostringstream	stream;

	if (std::strlen(field) > 10)
		stream << std::string(field, field + 9) << '.';
	else stream << std::setw(10) << field << std::setw(0);
	return (stream.str());
}

void	M(search)(void) {
	std::string	inputLine;
	int			nb(-1);

	if (!_contactCnt) {
		std::cout << "PHONEBOOK IS EMPTY" << std::endl;
		return ;
	}
	std::cout << formatField("ID") << '|';
	std::cout << formatField("FIRST NAME") << '|';
	std::cout << formatField("LAST NAME") << '|';
	std::cout << formatField("NICKNAME") << std::endl;
	for (unsigned i = 0; i < _contactCnt; ++i) {
		std::cout << formatField(i) << '|';
		std::cout << formatField(_contact[i].firstName) << '|';
		std::cout << formatField(_contact[i].lastName) << '|';
		std::cout << formatField(_contact[i].nickname) << std::endl;
	}
	while (nb < 0 || static_cast<size_t>(nb) >= _contactCnt) {
		std::cout << "ENTER A NUMBER (ID): ";
		std::getline(std::cin, inputLine);
		string_iterator	it(inputLine.begin());

		while (ft::isspace(*it)) ++it;
		if (!ft::isdigit(*it) || (nb = std::atoi(inputLine.c_str())) < 0
		|| static_cast<size_t>(nb) >= _contactCnt)
			std::cerr << "INVALID INPUT" << std::endl;
	}
	std::cout << "FIRST NAME: " << _contact[nb].firstName << std::endl;
	std::cout << "LAST NAME: " << _contact[nb].lastName << std::endl;
	std::cout << "NICKNAME: " << _contact[nb].nickname << std::endl;
	std::cout << "PHONE NUMBER: " << _contact[nb].phoneNumber << std::endl;
	std::cout << "DARKEST SECRET: " << _contact[nb].darkestSecret << std::endl;
}

void	M(execute)(const std::string &cmd) {
	if (cmd == "ADD") add();
	else if (cmd == "SEARCH") search();
	else if (cmd == "EXIT") std::exit(EXIT_SUCCESS);
}
