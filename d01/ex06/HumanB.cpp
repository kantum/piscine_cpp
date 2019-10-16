#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB(void)
{
}

std::string	HumanB::getWeapon() const
{
	return this->_weapon->getType();
}

void 		HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
}

void 		HumanB::attack(void) const
{
	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << this->_weapon->getType();
	std::cout << std::endl;
}

