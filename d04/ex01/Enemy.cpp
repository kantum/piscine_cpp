#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(void)
{

}

Enemy::Enemy(int hp, std::string const & type)
{
	this->_hp = hp;
	this->_type = type;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy(void)
{

}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return *this;
}

std::string	Enemy::getType() const
{
	return this->_type;
}

int		Enemy::getHP() const
{
	return this->_hp;
}

void		Enemy::takeDamage(int damage)
{
	if (this->_hp >= 0)
		this->_hp -= damage;
}
