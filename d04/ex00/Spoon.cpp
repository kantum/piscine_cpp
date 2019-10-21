#include "Spoon.hpp"
#include <iostream>

Spoon::Spoon(void)
{

}

Spoon::Spoon(std::string name) : Victim(name)
{
	std::cout << name << " the spoon is born !" << std::endl;
}

Spoon::Spoon(Spoon const & src)
{
	*this = src;
	std::cout << this->_name << "the spoon is born !" << std::endl;
}

Spoon::~Spoon(void)
{
	std::cout << "Oh no..." << std::endl;
}

Spoon & Spoon::operator=(Spoon const & rhs)
{
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

void		Spoon::getPolymorphed(void) const
{
	std::cout << getName() << " has been turned into a fork !" << std::endl;
}
