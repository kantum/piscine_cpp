/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:59:30 by acompagn          #+#    #+#             */
/*   Updated: 2019/10/20 23:01:18 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("ice")
{
	this->_xp = 0;
}

Cure::Cure(Cure const & src)
{
	*this = src;
}

Cure::~Cure(void)
{
}

Cure & Cure::operator=(Cure const & rhs)
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
	AMateria* copy = new Cure(*this);
	return copy;
}
