#include <iostream>
#include <ctime>

#include "ScavTrap.hpp"
#include "challenges.hpp"

ScavTrap::ScavTrap(void)
{
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::srand(std::time(0));
	std::cout << "A SC4V-TP is born, his name is " << name << std::endl;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "copy of " << src.getName();
	std::cout << std::endl;
	*this = src;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "assignation operator called" << std::endl;
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4V-TP " << this->_name << " is now dead" << std::endl;
}

void		ScavTrap::challengeNewcomer(std::string const & target)
{
	std::cout << "SC4V-TP ";
	std::cout << this->_name;
	std::cout << " challenges the new comer: ";
	std::cout << target << "! ";
	std::cout << challenges[std::rand() % N_CHALLENGES];
	std::cout << std::endl;
}
