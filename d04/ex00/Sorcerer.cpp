#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer(std::string name, std::string title)
{
	this->_name = name;
	this->_title = title;
	std::cout << name << ", " << title << ", is born !" << std::endl; 
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl; 
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_title = rhs.getTitle();
	}
	return *this;
}

std::string	Sorcerer::getName(void) const
{
	return this->_name;
}

std::string	Sorcerer::getTitle(void) const
{
	return this->_title;
}
std::ostream&	operator<<(std::ostream &out, const Sorcerer& c)
{
	out << "I am " << c.getName() << ", " << c.getTitle() << ", and I like ponies !" << std::endl;
	return out;
}
void		Sorcerer::introduce(void)
{
	std::cout << "I am " << this->_name << ", " << this->_title << ", and I like ponies !" << std::endl; 
}

void		Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}
