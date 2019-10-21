#include "Character.hpp"
#include "Enemy.hpp"
#include <iostream>

Character::Character(void)
{

}

Character::Character(std::string const & name)
{
	this->_name = name;
	this->_actionPoints = 40;
	this->_weaponPtr = NULL;
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character(void)
{

}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_actionPoints = rhs.getActionPoints();
		this->_weaponPtr = rhs.getWeaponPtr();
	}
	return *this;
}

std::string	Character::getName() const
{
	return this->_name;
}

int		Character::getActionPoints() const
{
	return this->_actionPoints;
}

AWeapon*	Character::getWeaponPtr() const
{
	return this->_weaponPtr;
}

void		Character::recoverAP()
{
	this->_actionPoints += 10;
	if (this->_actionPoints > 40)
		this->_actionPoints = 40;
}

void		Character::equip(AWeapon* weapon)
{
	this->_weaponPtr = weapon;
}

void		Character::attack(Enemy* enemy)
{
	if (this->getWeaponPtr() && getActionPoints() > this->getWeaponPtr()->getAPCost())
	{
		std::cout << getName() << " attacks " << enemy->getType() << " with a " << this->getWeaponPtr()->getName() << std::endl;
		this->_actionPoints -= this->getWeaponPtr()->getAPCost();
		this->getWeaponPtr()->attack();
		enemy->takeDamage(getWeaponPtr()->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}
	else
		std::cout << "Not enough action points to attack..." << std::endl;
}

std::ostream&	operator<<(std::ostream &out, const Character& c)
{
	if (c.getWeaponPtr())
	{
		out << c.getName() << " has " << c.getActionPoints() << " AP and wields a " << c.getWeaponPtr()->getName() << std::endl;
	}
	else
	{
		out << c.getName() << " has " << c.getActionPoints() << " AP and is unarmed" << std::endl;
	}
	return out;
}
