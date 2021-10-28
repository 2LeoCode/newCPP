#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:

	DiamondTrap();
	virtual ~DiamondTrap();

	DiamondTrap(std::string name);

	void		whoAmI(void) const;
	std::string	getName(void) const;

	private:

	void	constructMsg(void);

	std::string	_name;
	int			_scav_ep;
};

#endif //DIAMONDTRAP_HPP
