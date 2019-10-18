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
	std::cout << "FR4G-TP " << this->_name << " is now dead";
	std::cout << std::endl;
}

void		A(std::string const & target)
{
	std::cout << " attacks " << target << " with a glass of wine";
	std::cout << std::endl;
}

void		B(std::string const & target)
{
	std::cout << " simply calls the police to arrest " << target;
	std::cout << std::endl;
}

void		C(std::string const & target)
{
	std::cout << " uses his hair to attack " << target;
	std::cout << std::endl;
}

void		D(std::string const & target)
{
	std::cout << " raises some dragons to attack " << target << " later ...";
	std::cout << std::endl;
}

void		E(std::string const & target)
{
	std::cout << " uses a mac keyboard and put it in the mouth of " << target;
	std::cout << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_energyPoints < 25)
	{
		std::cout << "FR4G-TP ";
		std::cout << "You have not enough energy to run this attack...";
		std::cout << std::endl;
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
	std::cout << this->getArmorDamageReduction() << " of armor damage reduction";
	std::cout << std::endl;
}
