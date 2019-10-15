#include "Zombie.hpp"

Zombie::Zombie() : _name("noname"), _type("random zombie")
{
	std::cout << "A Zombie is born" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << 	" is dead" << std::endl;
	return;
}

void 		Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string	Zombie::getName() const
{
	return this->_name;
}

void 		Zombie::setType(std::string type)
{
	this->_type = type;
}

std::string	Zombie::getType() const
{
	return this->_type;
}

void		Zombie::announce()
{
   	std::cout << "<" << this->_name << " (" << this->_type << ")>";
   	std::cout << " Braiiiiiiinnnssss...";
	std::cout << std::endl;
}
