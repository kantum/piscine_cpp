#ifndef WILDDOG_HPP
# define WILDDOG_HPP
#include <iostream>
#include "Victim.hpp"

class WildDog : public Victim
{
	public:
		WildDog(void);
		WildDog(std::string name);
		WildDog(WildDog const & src);
		virtual ~WildDog(void);
		
		WildDog& operator=(WildDog const & rhs);
		
		virtual void	getPolymorphed(void) const;
};

#endif
