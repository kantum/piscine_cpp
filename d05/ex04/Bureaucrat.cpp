#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(std::string const & name) : _name(name)
{
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const & rhs)
{
	if (this != &rhs) { }
	return *this;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const & rhs)
{
	if (this != &rhs) { }
	return *this;
}

void			Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

int				Bureaucrat::getGrade() const
{
	return this->_grade;
}

void			Bureaucrat::GradeUp()
{
	setGrade(this->_grade -= 1);
	std::cout << "grade up" << std::endl;
}

void			Bureaucrat::executeForm(Form & f)
{
	if (this->_grade <= f.getGradeToExecute())
	{
		std::cout << this->_name;
		std::cout << " execute ";
		std::cout << f.getName();
		std::cout << std::endl;
		f.execute(*this);
	}
	else
	{
		std::cout << this->_name;
		std::cout << " cannot execute ";
		std::cout << f.getName();
		std::cout << std::endl;
	}
}

void			Bureaucrat::signForm(Form & f)
{
	if (this->_grade <= f.getGradeToSign())
	{
		std::cout << this->_name;
		std::cout << " signs ";
		std::cout << f.getName();
		std::cout << std::endl;
		f.setSigned(TRUE);
	}
	else
	{
		std::cout << this->_name;
		std::cout << " cannot sign ";
		std::cout << f.getName();
		std::cout << std::endl;
	}
}

void			Bureaucrat::GradeDown()
{
	setGrade(this->_grade += 1);
	std::cout << "grade down" << std::endl;
}

std::string		Bureaucrat::getName() const
{
	return this->_name;
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade: " << b.getGrade() << std::endl;
	return out;
}
