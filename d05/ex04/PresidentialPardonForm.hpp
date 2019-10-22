#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

class Bureaucrat;
class PresidentialPardonForm : public Form
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
		void	executeFunction(void) const;
		void		setTarget(std::string s);
		std::string getTarget(void) const;
};

std::ostream& operator<<(std::ostream &out, const PresidentialPardonForm& c);

#endif
