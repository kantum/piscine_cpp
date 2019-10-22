#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int		main()
{
	try
	{

	Intern		someRandomIntern;
	Form*		rrf;
	Bureaucrat	buro = Bureaucrat("Sylvie");
	buro.setGrade(1);

	std::cout << "===== PDF EXAMPLE =====" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	buro.signForm(*rrf);
	buro.executeForm(*rrf);

	std::cout << std::endl;

	std::cout << "===== OTHER EXAMPLES =====" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "home");
	buro.signForm(*rrf);
	buro.executeForm(*rrf);

	rrf = someRandomIntern.makeForm("presidential pardon", "Roco Sifredi");
	buro.signForm(*rrf);
	buro.executeForm(*rrf);


	std::cout << "===== INEXISTANT FORM =====" << std::endl;
	Form*		ppf = someRandomIntern.makeForm("blabla", "woup");
	(void)ppf;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;

	return (0);
}
