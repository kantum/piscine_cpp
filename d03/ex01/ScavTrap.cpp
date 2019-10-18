#include <iostream>
#include <ctime>

#include "ScavTrap.hpp"
#include "challenges.hpp"

ScavTrap::ScavTrap(void)
{
}

ScavTrap::ScavTrap(std::string name)
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
	std::cout << " to " << this->getName();
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

void			ScavTrap::setHitPoints(int n)
{
	if (n <= this->getMaxHitPoints() && n >= 0)
		this->_hitPoints = n;
	else if (n < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints = this->getMaxHitPoints();
}

void			ScavTrap::setEnergyPoints(int n)
{
	if (n <= this->getEnergyPoints() && n >= 0)
		this->_energyPoints = n;
	else if (n < 0)
		this->_energyPoints = 0;
	else
		this->_energyPoints = this->getMaxEnergyPoints();
}

void			ScavTrap::setLevel(int n)
{
	this->_level = n;
}

void			ScavTrap::setName(std::string s)
{
	this->_name = s;
}

void			ScavTrap::setMeleeAttackDamage(int n)
{
	this->_meleeAttackDamage = n;
}

void			ScavTrap::setRangedAttackDamage(int n)
{
	this->_rangedAttackDamage = n;
}

void			ScavTrap::setArmorDamageReduction(int n)
{
	this->_armorDamageReduction = n;
}

int			ScavTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int			ScavTrap::getMaxHitPoints(void) const
{
	return this->_maxHitPoints;
}

int			ScavTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int			ScavTrap::getMaxEnergyPoints(void) const
{
	return this->_maxEnergyPoints;
}

int			ScavTrap::getLevel(void) const
{
	return this->_level;
}

std::string			ScavTrap::getName(void) const
{
	return this->_name;
}

int			ScavTrap::getMeleeAttackDamage(void) const
{
	return this->_meleeAttackDamage;
}

int			ScavTrap::getRangedAttackDamage(void) const
{
	return this->_rangedAttackDamage;
}

int			ScavTrap::getArmorDamageReduction(void) const
{
	return this->_armorDamageReduction;
}

void		ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "SC4V-TP " << this->_name << " takes " << amount << " of damage, he has now " << this->_hitPoints << " hit points..." << std::endl;
	this->_hitPoints -= amount + this->_armorDamageReduction;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
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
