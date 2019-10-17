#include <iostream>
#include "FragTrap.hpp"

int		main()
{
	FragTrap	*John = new FragTrap("Little hoe");
	FragTrap	*Martine = new FragTrap("Bitch");	

	John->takeDamage(2);

	Martine->rangedAttack(John->getName());	
	Martine->rangedAttack(John->getName());	
	Martine->meleeAttack(John->getName());	

	John->vaulthunter_dot_exe(Martine->getName());
	John->vaulthunter_dot_exe(Martine->getName());
	John->vaulthunter_dot_exe(Martine->getName());
	
	delete John;
	delete Martine;
	return 0;
}
