#ifndef UGLYDRAGON_HPP
# define UGLYDRAGON_HPP
#include <iostream>
#include "Enemy.hpp"

class UglyDragon : public Enemy
{
	public:
		UglyDragon(void);
		UglyDragon(UglyDragon const & src);
		virtual ~UglyDragon(void);

		UglyDragon& operator=(UglyDragon const & rhs);
		
		virtual void		takeDamage(int);
};

#endif
