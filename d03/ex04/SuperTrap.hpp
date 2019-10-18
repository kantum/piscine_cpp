#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public ScavTrap, public FragTrap, public NinjaTrap
{
	protected:

		std::string	_name;

	public:

		SuperTrap(void);
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const & src);
		SuperTrap& operator=(SuperTrap const & rhs);
		~SuperTrap(void);

		std::string	getName() const;
};

#endif
