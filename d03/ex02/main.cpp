#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int		main()
{
	FragTrap	*john = new FragTrap("John");
	FragTrap	*martine = new FragTrap("Martine");	
	ScavTrap	*boby = new ScavTrap("Boby");	

	std::cout << std::endl;
	john->showValues();

	std::cout << std::endl;
	john->vaulthunter_dot_exe(martine->getName());
	martine->vaulthunter_dot_exe(john->getName());
	john->vaulthunter_dot_exe(martine->getName());
	martine->vaulthunter_dot_exe(john->getName());

	std::cout << std::endl;

	std::cout << (john->getHitPoints()) << std::endl;
	martine->rangedAttack(john->getName());	
	john->takeDamage(martine->getRangedAttackDamage());
	std::cout << (john->getHitPoints()) << std::endl;

	martine->rangedAttack(john->getName());	
	john->takeDamage(martine->getRangedAttackDamage());
	std::cout << (john->getHitPoints()) << std::endl;

	martine->meleeAttack(john->getName());	
	john->takeDamage(martine->getRangedAttackDamage());
	std::cout << (john->getHitPoints()) << std::endl;

	john->beRepaired(42);
	std::cout << (john->getHitPoints()) << std::endl;

	john->beRepaired(42);
	std::cout << (john->getHitPoints()) << std::endl;

	std::cout << std::endl;

	john->vaulthunter_dot_exe(martine->getName());
	john->vaulthunter_dot_exe(martine->getName());
	john->vaulthunter_dot_exe(martine->getName());
	
	std::cout << std::endl;

	FragTrap	*copyOfJohn = new FragTrap(*john);

	std::cout << copyOfJohn->getName();
	std::cout << std::endl;
	copyOfJohn = martine;
	std::cout << copyOfJohn->getName();
	std::cout << std::endl;

	std::cout << std::endl;
	boby->challengeNewcomer(john->getName());
	boby->challengeNewcomer(martine->getName());

	delete john;
	delete martine;
	return 0;
}
