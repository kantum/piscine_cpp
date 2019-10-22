#include "Form.hpp"
#include <iostream>

Form::Form(void) : _name("form"), _signed(FALSE), _gradeToSign(0), _gradeToExecute(0)
{
}

Form::Form(std::string const & name,
		const int gradeToSign,
		const int gradeToExecute) :
	_name(name),
	_signed(FALSE),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	
	if (this->_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (this->_gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	*this = src;
}

Form::~Form(void)
{
}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs) { }
	return *this;
}

Form::GradeTooHighException::GradeTooHighException(void)
{
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

Form::GradeTooHighException & Form::GradeTooHighException::GradeTooHighException::operator=(Form::GradeTooHighException const & rhs)
{
	if (this != &rhs) { }
	return *this;
}

Form::GradeTooLowException::GradeTooLowException(void)
{
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

Form::GradeTooLowException & Form::GradeTooLowException::GradeTooLowException::operator=(Form::GradeTooLowException const & rhs)
{
	if (this != &rhs) { }
	return *this;
}

int			Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int			Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

std::string		Form::getName() const
{
	return this->_name;
}

void			Form::setSigned(bool s)
{
	this->_signed = s;
}

bool			Form::getSigned(void) const
{
	return this->_signed;
}

bool			Form::beSigned(Bureaucrat & b)
{
	if (b.getGrade() <= this->getGradeToSign())
	{
		this->_signed = TRUE;
		return TRUE;
	}
	else
	{
		throw Form::GradeTooLowException();
		return FALSE;
	}
}

void			Form::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == TRUE)
	{
		if (executor.getGrade() <= this->getGradeToExecute())
			this->executeFunction();
		else
			throw Form::GradeTooLowException();
	}
	else
	{
		std::cout << this->getName() << " is not signed" << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &out, const Form& f)
{
	out << "Form " << f.getName();
	out << " is ";
	if (f.getSigned() == FALSE)
		out << "not ";
	out << "signed";
	out	<< std::endl;
	out	<< "grade to signe: " << f.getGradeToSign();
	out	<< std::endl;
	out	<< "grade to execute: " << f.getGradeToExecute();
	out	<< std::endl;
	return out;
}

