#include "FragTrap.hpp"
#include <iostream>
#include <ctime>

FragTrap::FragTrap(std::string name)
{
	std::srand(std::time(0));
	std::cout << "A newborn has come, his name is " << name << std::endl;
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

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called, " << this->_name << " dies !" << std::endl;
}

void			FragTrap::setHitPoints(int n)
{
	this->_hitPoints = n;
}

void			FragTrap::setMaxHitPoints(int n)
{
	if (n < this->_maxHitPoints && n >= 0)
		this->_maxHitPoints = n;
}

void			FragTrap::setEnergyPoints(int n)
{
	if (n < this->_maxHitPoints && n >= 0)
		this->_energyPoints = n;
}

void			FragTrap::setMaxEnergyPoints(int n)
{
	this->_maxEnergyPoints = n;
}

void			FragTrap::setLevel(int n)
{
	this->_level = n;
}

void			FragTrap::setName(std::string s)
{
	this->_name = s;
}

void			FragTrap::setMeleeAttackDamage(int n)
{
	this->_meleeAttackDamage = n;
}

void			FragTrap::setRangedAttackDamage(int n)
{
	this->_rangedAttackDamage = n;
}

void			FragTrap::setArmorDamageReduction(int n)
{
	this->_armorDamageReduction = n;
}

int			FragTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int			FragTrap::getMaxHitPoints(void) const
{
	return this->_maxHitPoints;
}

int			FragTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int			FragTrap::getMaxEnergyPoints(void) const
{
	return this->_maxEnergyPoints;
}

int			FragTrap::getLevel(void) const
{
	return this->_level;
}

std::string			FragTrap::getName(void) const
{
	return this->_name;
}

int			FragTrap::getMeleeAttackDamage(void) const
{
	return this->_meleeAttackDamage;
}

int			FragTrap::getRangedAttackDamage(void) const
{
	return this->_rangedAttackDamage;
}

int			FragTrap::getArmorDamageReduction(void) const
{
	return this->_armorDamageReduction;
}

void		FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void		FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " takes " << amount << " of damage..." << std::endl;
	this->_hitPoints -= amount + this->_armorDamageReduction;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void		FragTrap::beRepaired(unsigned int amount)
{
	this->setHitPoints(this->_hitPoints + amount);
	std::cout << this->_name << "is being repaired by " << amount << " !" << std::endl;
}

void		A(std::string const & target)
{
	std::cout << " Banana attacks " << target << std::endl;
}

void		B(std::string const & target)
{
	std::cout << " simply call the police to arrest " << target << std::endl;
}

void		C(std::string const & target)
{
	std::cout << " use his hair to attack " << target << std::endl;
}

void		D(std::string const & target)
{
	std::cout << " raise some dragons to attack " << target << " later ..." << std::endl;
}

void		E(std::string const & target)
{
	std::cout << " use a mac keyboard and put it in the mouth of " << target << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_energyPoints < 25)
		std::cout << "You have not enough energy to run this attack..." << std::endl;
	else
	{
		std::cout << this->_name;
		this->_energyPoints -= 25;
		void(*funcs[5])(std::string const & target) = { A, B, C, D, E};
		(funcs[std::rand() % 5])(target);
	}
}
