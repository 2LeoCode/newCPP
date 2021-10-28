/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:56:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/21 01:18:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int	main(int argc, char **argv) {
	std::string	option;

	if (argc == 2) option = argv[1];
	if (argc > 2 || (argc == 2 && option != "-d" && option != "--debug")) {
		std::cerr << "usage: " << argv[0] << " <-d|--debug>" << std::endl;
		return (-1);
	}
	ClapTrap	unnamed;
	ClapTrap	joe("joe");
	ClapTrap	steve("steve");
	
	if (argc == 2) {
		unnamed.enableDebugInfos();
		joe.enableDebugInfos();
		steve.enableDebugInfos();
	}
	std::cout << "ClapTrap " << unnamed.getName();
	std::cout << " wakes up, without knowing where he is" << std::endl;
	std::cout << "ClapTrap " << joe.getName();
	std::cout << " wakes up, without knowing where he is" << std::endl;
	std::cout << "ClapTrap " << steve.getName();
	std::cout << " wakes up, without knowing where he is" << std::endl;
	std::cout << '<' << steve.getName() << "> Hey! What's up!" << std::endl;
	std::cout << '<' << joe.getName() << "> Who are you ? Are you the dude who"
	" brought me here ?" << std::endl;
	std::cout << '<' << steve.getName() << "> I'm steve and no, I don't know"
	" where we are and I didn't brought us here." << std::endl;
	std::cout << '<' << joe.getName() << "> It's him! He's not talking!"
	" He's acting suspicious!" << std::endl;
	std::cout << '<' << unnamed.getName() <<
	"> Get away from me you jerk!" << std::endl;
	std::cout << '<' << steve.getName() << "> Me? A jerk? You want me to show"
	" you who's the jerk? What is your name anyway?" << std::endl;
	std::cout << '<' << unnamed.getName() <<
	"> I don't have one." << std::endl;
	std::cout << '<' << joe.getName() <<
	"> Are you f#$%@ kidding me?" << std::endl;
	std::cout << '<' << unnamed.getName() << "> I don't need a name,"
	" regular people need a name, but not me." << std::endl;
	std::cout << '<' << joe.getName() <<
	"> Let's just call you Billy then." << std::endl;
	std::cout << '<' << steve.getName() << "> Agree." << std::endl;
	unnamed.setName("Billy");
	std::cout << '<' << unnamed.getName() <<
	"> F#$! you! I didn't agree!" << std::endl;
	std::cout << '<' << steve.getName() <<
	"> Anyway, so, you, what is your name?" << std::endl;
	std::cout << '<' << joe.getName() << "> My name is Joe."
	" Joe the greatest of all..." << std::endl;
	std::cout << '<' << steve.getName() << "> Shut up! Did you"
	" hear that noise ?" << std::endl;
	std::cout << '<' << joe.getName() << "> What noise you dumb f#@!,"
	" stop interrupting before the end of my sent..." << std::endl;
	std::cout << "A giant two headed bear suddendly appears from nowhere and"
	" smashes " << joe.getName() << '!' << std::endl;
	try {
		joe.takeDamage(100);
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << '<' << unnamed.getName() <<
	"> NO! JOE! I'M COMING TO HELP YOU!" << std::endl;
	try {
		unnamed.attack("giant two headed bear");
		unnamed.attack("giant two headed bear");
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << '<' << steve.getName() << "> NOO! BILLY!!" << std::endl;
	std::cout << "The giant two headed bear punches " << unnamed.getName() <<
	'!' << std::endl;
	try {
		unnamed.takeDamage(9);
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << '<' << steve.getName() << "> Hold on Billy!" << std::endl;
	std::cout << steve.getName() << " is repairing " << unnamed.getName() <<
	'!' << std::endl;
	try {
		unnamed.beRepaired(5);
		unnamed.beRepaired(5);
		unnamed.beRepaired(5);
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << '<' << steve.getName() <<
	"> Run Billy! I'll hold him back!" << std::endl;
	std::cout << '<' << unnamed.getName() <<
	"> Why the hell do you even do that for me?"
	" You don't even know me!" << std::endl;
	std::cout << '<' << steve.getName() << "> Because your name is Billy,"
	" so I can't let you down here! Run !!!" << std::endl;
	std::cout << "The giant two headed bear jumps on " << steve.getName() <<
	" and litterally devours all his electrical components!" << std::endl;
	try {
		steve.attack("giant two headed bear");
		steve.takeDamage(9999);
		steve.beRepaired(99);
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << unnamed.getName() << " manages to escape!" << std::endl;
	std::cout << '<' << unnamed.getName() <<
	"> What a bunch of idiots.." << std::endl;
	return (0);
}