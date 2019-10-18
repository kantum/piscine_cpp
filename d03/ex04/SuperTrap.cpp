
#include <iostream>
#include <ctime>
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
{
}

SuperTrap::SuperTrap(std::string name)
{
	std::srand(std::time(0));
	std::cout << "A NINJ4-TP is born, his name is " << name;
	std::cout << std::endl;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;
}

SuperTrap::SuperTrap(SuperTrap const & src)
{
	std::cout << "copy of " << src.getName();
	std::cout << " to " << this->getName();
	std::cout << std::endl;
	*this = src;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs)
{
	std::cout << "assignation operator called" << std::endl;
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

SuperTrap::~SuperTrap(void)
{
}
