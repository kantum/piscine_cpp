#include "Spoon.hpp"
#include <iostream>
#include "AWeapon.hpp"

Spoon::Spoon(void) : AWeapon("Spoon", 10, 1)
{

}

Spoon::Spoon(Spoon const & src)
{
	*this = src;
}

Spoon::~Spoon(void)
{

}

Spoon & Spoon::operator=(Spoon const & rhs)
{
	if (this != &rhs)
		AWeapon::operator=(rhs);
	return *this;
}

void		Spoon::attack(void) const
{
	std::cout << "* spoon spoon *" << std::endl;
}
