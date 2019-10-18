#include <iostream>
#include <ctime>
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
}

FragTrap::FragTrap(std::string name)
{
	std::srand(std::time(0));
	std::cout << "A FR4G-TP is born, his name is " << name;
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

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "copy of " << src.getName();
	std::cout << " to " << this->getName();
	std::cout << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "assignation operator called" << std::endl;
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called, " << this->_name << " dies !" << std::endl;
}

void			FragTrap::setHitPoints(int n)
{
	if (n <= this->getMaxHitPoints() && n >= 0)
		this->_hitPoints = n;
	else if (n < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints = this->getMaxHitPoints();
}

void			FragTrap::setEnergyPoints(int n)
{
	if (n <= this->getEnergyPoints() && n >= 0)
		this->_energyPoints = n;
	else if (n < 0)
		this->_energyPoints = 0;
	else
		this->_energyPoints = this->getMaxEnergyPoints();
}

void			FragTrap::setLevel(int n)
{
	this->_level = n;
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
	this->setHitPoints(this->getHitPoints() - amount + this->_armorDamageReduction);
	std::cout << "FR4G-TP " << this->_name << " takes " << amount << " of damage, he has now " << this->_hitPoints << " hit points..." << std::endl;
}

void		FragTrap::beRepaired(unsigned int amount)
{
	this->setHitPoints(this->_hitPoints + amount);
	std::cout << "FR4G-TP " << this->_name << " is being repaired by " << amount << " !" << std::endl;
}

void		A(std::string const & target)
{
	std::cout << " attacks " << target << " with a glass of wine" << std::endl;
}

void		B(std::string const & target)
{
	std::cout << " simply calls the police to arrest " << target << std::endl;
}

void		C(std::string const & target)
{
	std::cout << " uses his hair to attack " << target << std::endl;
}

void		D(std::string const & target)
{
	std::cout << " raises some dragons to attack " << target << " later ..." << std::endl;
}

void		E(std::string const & target)
{
	std::cout << " uses a mac keyboard and put it in the mouth of " << target << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_energyPoints < 25)
	{
		std::cout << "SC4V-TP ";
		std::cout << "You have not enough energy to run this attack..." << std::endl;
	}
	else
	{
		std::cout << "FR4G-TP " << this->_name;
		this->_energyPoints -= 25;
		void(*funcs[5])(std::string const & target) = { A, B, C, D, E};
		(funcs[std::rand() % 5])(target);
	}
}

void		FragTrap::showValues(void)
{
	std::cout << this->getName() << " is level ";
	std::cout << this->getLevel() << " has something like " ;
	std::cout << this->getHitPoints() << " hit points ";
	std::cout << this->getEnergyPoints() << " energy points and ";
	std::cout << this->getArmorDamageReduction() << " of armor damage reduction" << std::endl;
}
