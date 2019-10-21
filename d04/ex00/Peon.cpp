#include "Peon.hpp"
#include <iostream>

Peon::Peon(void)
{

}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & src)
{
	*this = src;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon & Peon::operator=(Peon const & rhs)
{
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

void		Peon::getPolymorphed(void) const
{
	std::cout << getName() << " has been turned into a pink pony !" << std::endl;
}
