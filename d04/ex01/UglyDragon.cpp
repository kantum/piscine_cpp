#include "UglyDragon.hpp"
#include <iostream>

UglyDragon::UglyDragon(void) : Enemy(170, "Ugly Dragon")
{
	std::cout << "ROAAAAAAAAAAAR !" << std::endl;
}

UglyDragon::UglyDragon(UglyDragon const & src)
{
	*this = src;
	std::cout << "ROAAAAAAAAAAAR !" << std::endl;
}

UglyDragon::~UglyDragon(void)
{
	std::cout << "Roar ..." << std::endl;
}

UglyDragon & UglyDragon::operator=(UglyDragon const & rhs)
{
	if (this != &rhs)
		Enemy::operator=(rhs);
	return *this;
}

void		UglyDragon::takeDamage(int damage)
{
	if (getHP() >= 0)
		Enemy::takeDamage(damage);
}
