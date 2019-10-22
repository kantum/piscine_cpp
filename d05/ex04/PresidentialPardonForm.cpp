#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential Pardon Form", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs) { }
	return *this;
}

void			PresidentialPardonForm::setTarget(std::string s)
{
	this->_target = s;
}

std::string		PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void	PresidentialPardonForm::executeFunction(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.";
	std::cout << std::endl;
}
