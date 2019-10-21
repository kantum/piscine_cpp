/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:52:36 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 22:59:14 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
	this->_xp = 0;
}

Ice::Ice(Ice const & src)
{
	*this = src;
}

Ice::~Ice(void)
{
}

Ice & Ice::operator=(Ice const & rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

std::string const &	getType(void) const
{
	return this->_type;
}

AMateria*		clone() const
{
	AMateria* copy = new Ice(*this);
	return copy;
}
