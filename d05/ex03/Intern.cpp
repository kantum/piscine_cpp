#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void) : _name("form")
{
}

Intern::Intern(std::string const & name) : _name(name)
{
}

Intern::Intern(Intern const & src) : _name(src.getName())
{
	*this = src;
}

Intern::~Intern(void)
{
}

Intern & Intern::operator=(Intern const & rhs)
{
	if (this != &rhs) { }
	return *this;
}

std::string		Intern::getName() const
{
	return this->_name;
}

Form*		createShrubberyCreation(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form*		createRobotomyRequest(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form*		createPresidentialPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form*			Intern::makeForm(std::string form, std::string target)
{
	int	i;

	i = -1;
	//Form	array[3] = {
	//	createShrubberyCreation,
	//	createRobotomyRequest,
	//	createPresidentialPardon
	//};
	t_form array[3] = {
		{"shrubbery creation", createShrubberyCreation},
		{"robotomy request", createRobotomyRequest},
		{"presidential pardon", createPresidentialPardon}
 	};
	while (++i < 4)
	{
		if (array[i].form == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return array[i].fptr(target);
		}
	}
	std::cout << "Form " << form << " does not exists" << std::endl;
	return NULL;

}

std::ostream&	operator<<(std::ostream &out, const Intern& f)
{
	out << "Intern " << f.getName();
	out << " is fucked up";
	out	<< std::endl;
	return out;
}
