#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cstdio>
#include <iostream>

class Form;
class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(void);
			GradeTooHighException(std::string const & name);
			GradeTooHighException(GradeTooHighException const & src);
			virtual ~GradeTooHighException(void) throw();

			GradeTooHighException & operator=(GradeTooHighException const & rhs);
			virtual const char *what() const throw()
			{
				return ("Bureaucrat: GradeTooHighException");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(void);
			GradeTooLowException(std::string const & name);
			GradeTooLowException(GradeTooLowException const & src);
			virtual ~GradeTooLowException(void) throw();

			GradeTooLowException & operator=(GradeTooLowException const & rhs);

			virtual const char *what() const throw()
			{
				return ("Bureaucrat: GradeTooLowException");
			}
	};

	private:
	const std::string	_name;
	int					_grade;

	public:
	Bureaucrat(void);
	Bureaucrat(std::string const & name);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);

	Bureaucrat & operator=(Bureaucrat const & rhs);
	std::string		getName() const;
	int				getGrade() const;
	void			GradeUp();
	void			GradeDown();
	void			setGrade(int grade);
	void			signForm(Form & f);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& c);

#endif
