
#ifndef FORM_HPP
# define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>

#define	TRUE	1
#define	FALSE	0

class Bureaucrat;
class Form
{
	private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	public:
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
				return ("Form: GradeTooHighException");
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
				return ("Form: GradeTooLowException");
			}
	};

	Form(void);
	Form(std::string const & name,
			const int gradeToSign,
			const int gradeToExecute);
	Form(Form const & src);
	virtual ~Form(void);

	Form & operator=(Form const & rhs);
	std::string		getName() const;
	int				getGradeToSign(void) const;
	int				getGradeToExecute(void) const;
	bool			getSigned(void) const;
	bool			beSigned(Bureaucrat & b);
	void			setSigned(bool s);
	virtual void	executeFunction(void) const = 0;
	void			execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &out, const Form& c);

#endif
