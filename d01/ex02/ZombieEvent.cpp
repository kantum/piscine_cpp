#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ZombieEvent.hpp"
#include "ZombieNames.hpp"
#include "ZombieTypes.hpp"

ZombieEvent::ZombieEvent(void) {
	// Seed for random generation
	std::srand(std::time(0));
}

ZombieEvent::~ZombieEvent(void)
{
}

void	ZombieEvent::setZombieType(Zombie *z, std::string type)
{
	z->setType(type);
}

Zombie* ZombieEvent::newZombie(std::string name, std::string type)
{
	Zombie *ret = new Zombie();
	ret->setName(name);
	ret->setType(type);
	return (ret);
}

Zombie	ZombieEvent::randomChump()
{
	Zombie			ret;
	unsigned int	r;

	r = std::rand() % N_NAMES;
	ret.setName(zombieNames[r]);
	r = std::rand() % N_TYPES;
	ret.setType(zombieTypes[r]);
	ret.announce();
	return (ret);
}
