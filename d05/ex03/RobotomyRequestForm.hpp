#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

class Bureaucrat;
class RobotomyRequestForm : public Form
{
	private:
		std::string _target;

	public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
	void		executeFunction(void) const;
	void		setTarget(std::string s);
	std::string getTarget(void) const;
};

//std::ostream& operator<<(std::ostream &out, const RobotomyRequestForm& c);

#endif
