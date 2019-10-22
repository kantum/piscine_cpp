#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy Request Form", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45)
{
	this->_target = target;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs) { }
	return *this;
}

void			RobotomyRequestForm::setTarget(std::string s)
{
	this->_target = s;
}

std::string		RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void	RobotomyRequestForm::executeFunction(void) const
{
		std::cout << "Driiiillllllllll Scrueuruweueuuuuuuuasf @!%#" << std::endl;
	if (rand() % 100 > 50)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " robotomization has failed" << std::endl;
}
