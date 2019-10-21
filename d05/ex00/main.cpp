#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

int		main()
{
	try
	{
		Bureaucrat *a = new Bureaucrat("Sylvestre");
		a->setGrade(1);
		std::cout << *a;
		a->GradeUp();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *a = new Bureaucrat("Hector");
		a->setGrade(150);
		std::cout << *a;
		a->GradeDown();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *a = new Bureaucrat("Boby");
		a->setGrade(152);
		std::cout << *a;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *a = new Bureaucrat("Blaise");
		a->setGrade(0);

	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
	 
