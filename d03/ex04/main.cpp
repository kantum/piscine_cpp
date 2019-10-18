#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main()
{
	FragTrap	*john = new FragTrap("John");
	FragTrap	*martine = new FragTrap("Martine");	
	ScavTrap	*boby = new ScavTrap("Boby");	

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

	std::cout << std::endl;
	john->vaulthunter_dot_exe(martine->getName());
	john->vaulthunter_dot_exe(martine->getName());
	john->vaulthunter_dot_exe(martine->getName());
	

	std::cout << std::endl;
	std::cout << std::endl;

	FragTrap	*copyOfJohn = new FragTrap(*john);

	std::cout << john->getName();
	std::cout << copyOfJohn->getName();
	std::cout << std::endl;

	std::cout << std::endl;
	boby->challengeNewcomer(john->getName());
	boby->challengeNewcomer(martine->getName());


	NinjaTrap	*ninja1 = new NinjaTrap("chi");	
	NinjaTrap	*ninja2 = new NinjaTrap("kong");	
	NinjaTrap	*ninja3 = new NinjaTrap("tchai");	

	std::cout << std::endl;
	ninja1->ninjaShoeBox();
	std::cout << std::endl;
	ninja1->ninjaShoeBox(*john);
	std::cout << std::endl;
	ninja2->ninjaShoeBox(*boby);
	std::cout << std::endl;
	ninja3->ninjaShoeBox(*ninja1);
	std::cout << std::endl;

	SuperTrap	*super = new SuperTrap("chuck noris");	

	std::cout << super->FragTrap::getHitPoints();
	std::cout << std::endl;
	super->FragTrap::rangedAttack(ninja1->getName());
	super->FragTrap::meleeAttack(ninja2->getName());
	std::cout << super->FragTrap::getLevel();
	std::cout << std::endl;

	delete john;
	delete martine;
	delete boby;
	delete ninja1;
	delete ninja2;
	delete ninja3;
	return 0;
}
