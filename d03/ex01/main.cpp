#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main()
{
	FragTrap	*john = new FragTrap("John");
	FragTrap	*martine = new FragTrap("Martine");	
	ScavTrap	*boby = new ScavTrap("Boby");	

	john->setLevel(23);
	john->setHitPoints(48);
	john->setEnergyPoints(83);
	john->setLevel(63);
	john->setMeleeAttackDamage(32);
	john->setArmorDamageReduction(2);

	martine->setLevel(45);
	martine->setHitPoints(28);
	martine->setEnergyPoints(100);
	martine->setLevel(63);
	martine->setMeleeAttackDamage(32);
	martine->setArmorDamageReduction(2);

	std::cout << std::endl;
	john->showValues();

	std::cout << std::endl;
	john->vaulthunter_dot_exe(martine->getName());
	john->vaulthunter_dot_exe(martine->getName());
	john->vaulthunter_dot_exe(martine->getName());
	martine->vaulthunter_dot_exe(john->getName());
	martine->vaulthunter_dot_exe(john->getName());
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

	john->beRepaired(42);
	std::cout << (john->getHitPoints()) << std::endl;
	john->setEnergyPoints(42);

	std::cout << std::endl;
	john->vaulthunter_dot_exe(martine->getName());
	john->vaulthunter_dot_exe(martine->getName());
	john->vaulthunter_dot_exe(martine->getName());
	
	std::cout << std::endl;
	boby->challengeNewcomer(john->getName());
	boby->challengeNewcomer(martine->getName());

	delete john;
	delete martine;
	return 0;
}
