#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void) { }

std::string	HumanA::getName() const
{
	return this->_name;
}

void 		HumanA::setName(std::string name)
{
	this->_name = name;
}

void 		HumanA::attack(void)
{
	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << this->_weapon.getType();
	std::cout << std::endl;
}
