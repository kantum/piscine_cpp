#include "WildDog.hpp"
#include <iostream>

WildDog::WildDog(void)
{

}

WildDog::WildDog(std::string name) : Victim(name)
{
	std::cout << name << " the wild dog is born !" << std::endl;
}

WildDog::WildDog(WildDog const & src)
{
	*this = src;
	std::cout << this->_name << " the wild dog is born !" << std::endl;
}

WildDog::~WildDog(void)
{
	std::cout << "Wouf..." << std::endl;
}

WildDog & WildDog::operator=(WildDog const & rhs)
{
	if (this != &rhs)
		this->_name = rhs.getName();
	return *this;
}

void		WildDog::getPolymorphed(void) const
{
	std::cout << getName() << " has been turned into a cute cat !" << std::endl;
}
