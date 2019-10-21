/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:09:09 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 23:23:03 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void)
{

}

Character::Character(std::string const & name)
{
	int	i;
	
	i = 0;
	this->_name = name;
	while (i++ < 4)
		this->_inventory[i] = NULL;
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
	}
	return *this;
}

std::string const &	getName(void) const
{
	return this->_name;
}

void			equip(AMateria* m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void			unequip(int indx)
{
	this->_inventory[indx] = NULL;
}

void			use(int indx, ICharacter& target)
{
	AMateria::use(target);
}
