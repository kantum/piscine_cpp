#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main()
{
	try
	{
		Form *cerfa42 = new Form("cerfa", 84, 42);
		std::cout << *cerfa42;
		Form *cerfa230 = new Form("cerfa", 184, 42);
		std::cout << *cerfa230;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
		std::cout << std::endl;

	try
	{
		Bureaucrat *a = new Bureaucrat("Sylvestre");
		Form *cerfa42 = new Form("cerfa", 84, 42);

		a->setGrade(1);
		std::cout << *a;
		std::cout << *cerfa42;
		cerfa42->beSigned(*a);
		std::cout << *cerfa42;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
		std::cout << std::endl;

	try
	{
		Bureaucrat *a = new Bureaucrat("Hector");
		Form *cerfa42 = new Form("cerfa", 84, 42);

		a->setGrade(50);
		std::cout << *a;
		std::cout << *cerfa42;
		cerfa42->beSigned(*a);
		std::cout << *cerfa42;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
		std::cout << std::endl;

	try
	{
		Bureaucrat *a = new Bureaucrat("Boby");
		Form *cerfa42 = new Form("cerfa", 84, 42);

		a->setGrade(50);
		std::cout << *a;

		std::cout << *cerfa42;
		a->signForm(*cerfa42);
		std::cout << *cerfa42;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
		std::cout << std::endl;

	try
	{
		Bureaucrat *a = new Bureaucrat("Blaise");
		Form *cerfa42 = new Form("cerfa", 84, 42);

		a->setGrade(86);

		std::cout << *a;

		std::cout << *cerfa42;
		a->signForm(*cerfa42);
		std::cout << *cerfa42;

	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
	 
