#ifndef SPOON_HPP
# define SPOON_HPP
#include <iostream>
#include "AWeapon.hpp"

class Spoon : public AWeapon
{
	public:
		Spoon(void);
		Spoon(Spoon const & src);
		virtual ~Spoon(void);

		Spoon& operator=(Spoon const & rhs);
		
		void		attack(void) const;
};

#endif
