/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:30:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/26 20:06:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	public:

	Character();
	~Character();

	Character(const ICharacter &other);
	Character(std::string name);

	Character	&operator=(const ICharacter &other);

	virtual std::string const	&getName(void) const;
	virtual void				equip(AMateria *m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter &target);
	void						deleteInventory(void);

	private:

	std::string	_name;
	AMateria	*_inventory[4];
	unsigned	_itemCnt;
};

#endif //CHARACTER_HPP
