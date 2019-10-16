#include <string>
#include <iostream>

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int		main(void)
{
	// Horde of zombies allocated on the stack
	ZombieHorde z(4);
	z.announce();
}
