/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:29:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/23 21:48:30 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	public:

	Zombie();
	~Zombie();

	Zombie(const std::string name);
	void	announce(void);

	private:

	const std::string	_name;
};

#endif //ZOMBIE_HPP
