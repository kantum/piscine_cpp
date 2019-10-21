#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{

}

PowerFist::PowerFist(PowerFist const & src)
{
	*this = src;
}

PowerFist::~PowerFist(void)
{

}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
	if (this != &rhs)
		AWeapon::operator=(rhs);
	return *this;
}

void		PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
