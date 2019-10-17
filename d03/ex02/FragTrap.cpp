#include <iostream>
#include <ctime>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::srand(std::time(0));
	std::cout << "A FR4G-TP is born, his name is " << name << std::endl;
}

//FragTrap::FragTrap(FragTrap const &)
//{
//}

//FragTrap::FragTrap& operator=(FragTrap const &)
//{
//}
//
//FragTrap::~FragTrap(void)
//{
//	std::cout << "FR4G-TP " << this->_name << " is now dead" << std::endl;
//}

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
