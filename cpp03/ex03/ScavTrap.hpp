/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:24:40 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 00:35:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
	public:

	ScavTrap();
	virtual ~ScavTrap();

	ScavTrap(std::string name);

	void	attack(std::string target);
	void	guardGate(void);
};

#endif //SCAVTRAP_HPP
