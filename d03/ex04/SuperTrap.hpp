
#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public ClapTrap
{
	private:

	public:

		SuperTrap(void);
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const & src);
		SuperTrap& operator=(SuperTrap const & rhs);
		~SuperTrap(void);

};

#endif
