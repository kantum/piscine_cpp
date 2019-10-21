#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int		main()
{
	std::srand(std::time(0));
	try
	{
		Bureaucrat *a = new Bureaucrat("Boris");
		ShrubberyCreationForm *cerfa42 = new ShrubberyCreationForm("home");
		PresidentialPardonForm *cerfa43 = new PresidentialPardonForm("Zaz");
		RobotomyRequestForm *cerfa44 = new RobotomyRequestForm("Bigorno");

		a->setGrade(86);
		std::cout << *a;
		std::cout << *cerfa42;
		a->signForm(*cerfa42);
		std::cout << *cerfa43;
		a->signForm(*cerfa43);
		std::cout << *cerfa44;
		a->signForm(*cerfa44);
		std::cout << *cerfa42;
		std::cout << *cerfa43;
		std::cout << *cerfa44;

		Bureaucrat *b = new Bureaucrat("Gilbert");
		b->setGrade(150);
		std::cout << *cerfa42;
		//cerfa42->execute(*b);
		b->setGrade(50);
		cerfa42->execute(*b);
		cerfa43->execute(*b);
		b->setGrade(5);
		b->signForm(*cerfa43);
		cerfa43->execute(*b);
		b->signForm(*cerfa44);
		for (int i = 0; i < 4; i++)
			b->executeForm(*cerfa44);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

