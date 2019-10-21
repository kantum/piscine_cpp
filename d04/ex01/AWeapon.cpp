#include "AWeapon.hpp"
#include <iostream>

AWeapon::AWeapon(void)
{

}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->_name = name;
	this->_apCost = apcost;
	this->_damagePoints = damage;
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon::~AWeapon(void)
{

}

AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_damagePoints = rhs.getDamage();
		this->_apCost = rhs.getAPCost();
	}
	return *this;
}

std::string const &	AWeapon::getName() const
{
	return this->_name;
}

int			AWeapon::getAPCost() const
{
	return this->_apCost;
}

int			AWeapon::getDamage() const
{
	return this->_damagePoints;
}
