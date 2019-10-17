#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

	public:

		ScavTrap(std::string name);
		~ScavTrap(void);

		void		beRepaired(unsigned int amount);
		void		challengeNewcomer(std::string const & target);
};

#endif
