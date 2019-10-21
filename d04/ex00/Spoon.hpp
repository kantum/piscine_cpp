#ifndef SPOON_HPP
# define SPOON_HPP
#include <iostream>
#include "Victim.hpp"

class Spoon : public Victim
{
	public:
		Spoon(void);
		Spoon(std::string name);
		Spoon(Spoon const & src);
		virtual ~Spoon(void);
		
		Spoon& operator=(Spoon const & rhs);
		
		virtual void	getPolymorphed(void) const;
};

#endif
