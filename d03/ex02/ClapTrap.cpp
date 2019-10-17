#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::srand(std::time(0));
	std::cout << "A FR4G-TP is born, his name is " << name << std::endl;

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
	*this = src;
}
//
//ClapTrap::ClapTrap& operator=(ClapTrap const &)
//{
//}

ClapTrap::~ClapTrap(void)
{
	std::cout << "FR4G-TP " << this->_name << " is now dead" << std::endl;
}

void			ClapTrap::setHitPoints(int n)
{
	this->_hitPoints = n;
}

void			ClapTrap::setEnergyPoints(int n)
{
	if (n < this->_maxHitPoints && n >= 0)
		this->_energyPoints = n;
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
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP " << this->_name << " takes " << amount << " of damage, he has now " << this->_hitPoints << " hit points..." << std::endl;
	this->_hitPoints -= amount + this->_armorDamageReduction;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	this->setHitPoints(this->_hitPoints + amount);
	std::cout << "FR4G-TP " << this->_name << "is being repaired by " << amount << " !" << std::endl;
}

