#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

class Bureaucrat;
class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;

	public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
	void		executeFunction(void) const;
	void		setTarget(std::string s);
	std::string getTarget(void) const;
};

//std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm& c);

#endif
