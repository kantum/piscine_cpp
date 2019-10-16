#include <string>
#include <iostream>
#include <ctime>

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include "ZombieNames.hpp"
#include "ZombieTypes.hpp"

ZombieHorde::ZombieHorde(unsigned int n)
{
	unsigned int	r;

	std::srand(std::time(0));

	this->nzombie = n;
	this->horde = new Zombie[n];
	std::cout << "Create the horde" << std::endl;
	std::cout << "There is " << n << " Zombies" << std::endl;
	for (unsigned int i = 0; i < n; i++)
	{
		r = std::rand() % N_NAMES;
		horde[i].setName(zombieNames[r]);
		r = std::rand() % N_TYPES;
		horde[i].setType(zombieTypes[r]);
	}
}

ZombieHorde::~ZombieHorde(void)
{
	std::cout << "Delete the horde" << std::endl;
	delete [] this->horde;
}

void	ZombieHorde::announce(void)
{
	for (unsigned int i = 0; i < this->nzombie; i++)
		this->horde[i].announce();
}

