#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <string>
#include <iostream>

#include "Zombie.hpp"

class	ZombieEvent
{
	private:
		
	public:
		ZombieEvent(void);
		~ZombieEvent(void);

		void	setZombieType(Zombie *z, std::string type);
		Zombie* newZombie(std::string name, std::string type);
		Zombie	randomChump(void);
};

#endif
