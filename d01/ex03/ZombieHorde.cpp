#include <string>
#include <iostream>

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(unsigned int n)
{
	std::cout << "Create the horde" << std::endl;
	std::cout << "There is " << n << " Zombies" << std::endl;
	this->horde = new Zombie[n];
}

ZombieHorde::~ZombieHorde(void)
{
	std::cout << "Delete the horde" << std::endl;
	delete [] this->horde;
}
