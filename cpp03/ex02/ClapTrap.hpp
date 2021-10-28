/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:30:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/15 22:16:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
	public:

	typedef	std::string	&exception_type;

	ClapTrap();
	virtual ~ClapTrap();

	ClapTrap(const ClapTrap &other);
	ClapTrap(std::string name);

	ClapTrap	&operator=(const ClapTrap &other);

	void	attack(std::string const &target);
	void	takeDamage(unsigned amount);
	void	beRepaired(unsigned amount);

	std::string	getName(void) const;
	int			getHp(void) const;
	int			getEp(void) const;
	int			getDmg(void) const;

	void		setName(std::string name);
	void		setHp(int hp);
	void		setEp(int ep);
	void		setDmg(int dmg);

	void	enableDebugInfos(void);
	void	debugInfo(void) const;


	protected:

	void	announceBegin(void) const;
	void	announceEnd(void) const;

	std::string	_type;

	std::string	_name;
	int			_hp;
	int			_ep;
	int			_dmg;
	bool		_debugInfo;
};

#endif //CLAPTRAP_HPP
