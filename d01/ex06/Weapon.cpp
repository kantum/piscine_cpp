#include "Weapon.hpp"

#include <string>
#include <iostream>

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
}

std::string	const &Weapon::getType() const
{
	return this->_type;
}

void 		Weapon::setType(const std::string &type)
{
	this->_type = type;
}
