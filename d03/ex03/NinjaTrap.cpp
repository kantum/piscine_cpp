#include <iostream>
#include <ctime>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
}

NinjaTrap::NinjaTrap(std::string name)
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

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	std::cout << "copy of " << src.getName();
	std::cout << " to " << this->getName();
	std::cout << std::endl;
	*this = src;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs)
{
	std::cout << "assignation operator called" << std::endl;
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

NinjaTrap::~NinjaTrap(void)
{
}

void	NinjaTrap::ninjaShoeBox()
{
	std::cout << "The ninja " << this->getName();
	std::cout << " throw shoe boxes all around the room";
	std::cout << " pretending to be a gold rabbit";
	std::cout << std::endl;
}

void	NinjaTrap::ninjaShoeBox(FragTrap & f)
{
	std::cout << this->getName();
	std::cout << " send Addidas Shoe Box Attack on ";
	std::cout << f.getName();
	std::cout << std::endl;
}

void	NinjaTrap::ninjaShoeBox(ScavTrap & f)
{
	std::cout << this->getName();
	std::cout << " send New Balance Shoe Box Attack on ";
	std::cout << f.getName();
	std::cout << std::endl;
}

void	NinjaTrap::ninjaShoeBox(NinjaTrap & f)
{
	std::cout << this->getName();
	std::cout << " send Vans Shoe Box Attack on ";
	std::cout << f.getName();
	std::cout << std::endl;
}
