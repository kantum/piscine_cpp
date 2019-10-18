#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		FragTrap& operator=(FragTrap const & rhs);
		~FragTrap(void);

		void		vaulthunter_dot_exe(std::string const & target);
		void		showValues(void);
};

#endif
