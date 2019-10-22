#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "OfficeBlock.hpp"
#include <iostream>
#include <stdexcept>

int		main()
{
	std::srand(std::time(0));
	std::cout << "===== PDF MAIN EXAMPLE =====" << std::endl;
	try
	{
		Intern      idiotOne;
		Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 37);
		Bureaucrat  bob = Bureaucrat("Bobby Bobson", 123);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);

		ob.doBureaucracy("mutant pig termination", "Pigley");	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
	std::cout << std::endl;	
	std::cout << "===== TRYING TO DO BUREAUCRACY WITH ONLY 1 INTERN =====" << std::endl;
	try
	{
		Intern		intern;
		OfficeBlock	ob;

		ob.setIntern(intern);

		ob.doBureaucracy("presidential pardon", "Sucrette");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "===== TRYING TO DO BUREAUCRACY WITH UNQUALIFIED SIGNER =====" << std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	a = Bureaucrat("Georges", 112);
		Bureaucrat	b = Bureaucrat("Albert", 1);
		OfficeBlock	ob;

		ob.setIntern(intern);
		ob.setSigner(a);
		ob.setExecutor(b);

		ob.doBureaucracy("presidential pardon", "Sucrette");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "===== TRYING TO DO BUREAUCRACY WITH UNQUALIFIED EXECUTOR =====" << std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	a = Bureaucrat("Georges", 1);
		Bureaucrat	b = Bureaucrat("Albert", 145);
		OfficeBlock	ob;

		ob.setIntern(intern);
		ob.setSigner(a);
		ob.setExecutor(b);

		ob.doBureaucracy("schrubbery creation", "Sucrette");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "===== TRYING TO DO BUREAUCRACY SUCCESS =====" << std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	a = Bureaucrat("Georges", 1);
		Bureaucrat	b = Bureaucrat("Albert", 1);
		OfficeBlock	ob;

		ob.setIntern(intern);
		ob.setSigner(a);
		ob.setExecutor(b);

		ob.doBureaucracy("robotomy request", "Sucrette");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
