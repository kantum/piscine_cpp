#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	private:

	public:

		NinjaTrap(void);
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const & src);
		NinjaTrap& operator=(NinjaTrap const & rhs);
		~NinjaTrap(void);

		void		ninjaShoeBox(void);
		void		ninjaShoeBox(FragTrap & f);
		void		ninjaShoeBox(ScavTrap & f);
		void		ninjaShoeBox(NinjaTrap & f);
};

#endif
