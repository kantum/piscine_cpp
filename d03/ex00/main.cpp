#include <iostream>
#include "FragTrap.hpp"

int		main()
{
	FragTrap	*John = new FragTrap("Ferguson");
	FragTrap	*Martine = new FragTrap("Jackeline");	

	John->takeDamage(4);
	John->takeDamage(5);
	John->takeDamage(6);

	Martine->rangedAttack(John->getName());	
	John->takeDamage(20);
	Martine->rangedAttack(John->getName());	
	John->takeDamage(20);
	Martine->meleeAttack(John->getName());	
	John->takeDamage(20);

	for (unsigned int i = 0; i < 6; i++)
		John->vaulthunter_dot_exe(Martine->getName());
	
	delete John;
	delete Martine;
	return 0;
}
