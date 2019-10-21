/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:39:53 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 23:24:54 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void)
{
}

AMateria(std::string const & type)
{
	this->_type = type;
	this->_xp = 0;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
	{
		this->_xp = rhs.getXP();
		this->_type = rhs.getType();	
	}
	return *this;
}

std::string const &	getType(void) const
{
	return this->_type;
}

unsigned int		getXP(void) const
{
	return this->_xp;
}

void		AMateria::use(ICharacter& target)
{
	this->_xp += 10;	
}
