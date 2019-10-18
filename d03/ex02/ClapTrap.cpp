#include <iostream>
#include <ctime>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
}

ClapTrap::ClapTrap(std::string name)
{
	std::srand(std::time(0));
	std::cout << "A CL4P-TP is born, his name is " << name;
	std::cout << std::endl;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "copy of " << src.getName();
	std::cout << " to " << this->getName();
	std::cout << std::endl;
	*this = src;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "assignation operator called" << std::endl;
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called, " << this->_name << " dies !" << std::endl;
}

void			ClapTrap::setHitPoints(int n)
{
	if (n <= this->getMaxHitPoints() && n >= 0)
		this->_hitPoints = n;
	else if (n < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints = this->getMaxHitPoints();
}

void			ClapTrap::setEnergyPoints(int n)
{
	if (n <= this->getEnergyPoints() && n >= 0)
		this->_energyPoints = n;
	else if (n < 0)
		this->_energyPoints = 0;
	else
		this->_energyPoints = this->getMaxEnergyPoints();
}

void			ClapTrap::setLevel(int n)
{
	this->_level = n;
}

void			ClapTrap::setMeleeAttackDamage(int n)
{
	this->_meleeAttackDamage = n;
}

void			ClapTrap::setRangedAttackDamage(int n)
{
	this->_rangedAttackDamage = n;
}

void			ClapTrap::setArmorDamageReduction(int n)
{
	this->_armorDamageReduction = n;
}

int			ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int			ClapTrap::getMaxHitPoints(void) const
{
	return this->_maxHitPoints;
}

int			ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int			ClapTrap::getMaxEnergyPoints(void) const
{
	return this->_maxEnergyPoints;
}

int			ClapTrap::getLevel(void) const
{
	return this->_level;
}

std::string			ClapTrap::getName(void) const
{
	return this->_name;
}

int			ClapTrap::getMeleeAttackDamage(void) const
{
	return this->_meleeAttackDamage;
}

int			ClapTrap::getRangedAttackDamage(void) const
{
	return this->_rangedAttackDamage;
}

int			ClapTrap::getArmorDamageReduction(void) const
{
	return this->_armorDamageReduction;
}

void		ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void		ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "CL4P-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	this->setHitPoints(this->getHitPoints() - amount + this->_armorDamageReduction);
	std::cout << "CL4P-TP " << this->_name << " takes " << amount << " of damage, he has now " << this->_hitPoints << " hit points..." << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	this->setHitPoints(this->_hitPoints + amount);
	std::cout << "CL4P-TP " << this->_name << " is being repaired by " << amount << " !" << std::endl;
}
