#include "Victim.hpp"
#include <iostream>

Victim::Victim(void)
{

}

Victim::Victim(std::string name)
{
	this->_name = name;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim(Victim const & src)
{
	*this = src;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}


Victim & Victim::operator=(Victim const & rhs)
{
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

std::ostream&	operator<<(std::ostream &out, const Victim& c)
{
	out << "I'm " << c.getName() << " and I like otters !" << std::endl;
	return out;
}

void		Victim::introduce(void)
{
	std::cout << "I'm " << this->_name << " and I like otters !" << std::endl;
}

void		Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::string	Victim::getName(void) const
{
	return this->_name;
}
