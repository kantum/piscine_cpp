#ifndef INTERN_HPP
# define INTERN_HPP
#include "Form.hpp"
#include <iostream>

class Bureaucrat;
class Intern
{
	private:
	const std::string	_name;

	public:

	Intern(void);
	Intern(std::string const & name);
	Intern(Intern const & src);
	virtual ~Intern(void);

	Intern & operator=(Intern const & rhs);
	std::string		getName() const;
	Form*			makeForm(std::string form, std::string target);

};

typedef struct		s_form
{
	std::string		form;
	Form*			(*fptr)(std::string target);
} 					t_form;

std::ostream& operator<<(std::ostream &out, const Intern& c);

#endif
