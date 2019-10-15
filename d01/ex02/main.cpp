#include <string>
#include <iostream>

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main(void)
{
	// Create a ZombieEvent instance
	ZombieEvent *ze = new ZombieEvent;

	// This is the master zombie on the stack
	Zombie z;
	z.setName("Robert");
	z.setType("BigBoss");
	z.announce();

	//Define a number of zombie to create on the heap
	unsigned int	znum = 3;
	Zombie *zArray = new Zombie[znum];
	// Let zombies annonces themselfs
	for(unsigned int i = 0; i < znum; i++)
		zArray[i].announce();

	// Kill array of heap zombies
	delete [] zArray;

	// Let's make some random zombies on the stack
	Zombie a = ze->randomChump();
	Zombie b = ze->randomChump();
	Zombie c = ze->randomChump();
	// And kill them :D
	std::cout << "Someone finally killed " << a.getName() << std::endl;
	a.~Zombie();
	Zombie d = ze->randomChump();
	Zombie e = ze->randomChump();
	std::cout << "Too much zombies let stop the game !" << std::endl;
}
