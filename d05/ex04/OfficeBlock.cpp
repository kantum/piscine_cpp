#include <iostream>
#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

OfficeBlock::MissingElementException::MissingElementException() {}

OfficeBlock::MissingElementException::MissingElementException(MissingElementException const & src)
{
	*this = src;
}

OfficeBlock::MissingElementException::~MissingElementException() throw() {}

OfficeBlock::MissingElementException& OfficeBlock::MissingElementException::operator=(MissingElementException const & rhs)
{
	(void)rhs;
	return *this;
}

OfficeBlock::InternException::InternException() {}

OfficeBlock::InternException::InternException(InternException const & src)
{
	*this = src;
}

OfficeBlock::InternException::~InternException() throw() {}

OfficeBlock::InternException& OfficeBlock::InternException::operator=(InternException const & rhs)
{
	(void)rhs;
	return *this;
}

OfficeBlock::SignerException::SignerException() {}

OfficeBlock::SignerException::SignerException(SignerException const & src)
{
	*this = src;
}

OfficeBlock::SignerException::~SignerException() throw() {}

OfficeBlock::SignerException& OfficeBlock::SignerException::operator=(SignerException const & rhs)
{
	(void)rhs;
	return *this;
}

OfficeBlock::OfficeBlock(void)
{
	this->_intern = NULL;
	this->_signer = NULL;
	this->_executor = NULL;
}

OfficeBlock::OfficeBlock(Intern & intern, Bureaucrat & sign, Bureaucrat & exe)
{
        this->_intern = &intern;
	this->_signer = &sign;
	this->_executor = &exe;
}

OfficeBlock::~OfficeBlock(void)
{

}

void		OfficeBlock::setIntern(Intern & intern)
{
	this->_intern = &intern;
}

void		OfficeBlock::setSigner(Bureaucrat & sign)
{
	this->_signer = &sign;
}

void		OfficeBlock::setExecutor(Bureaucrat & exe)
{
	this->_executor = &exe;
}

void		OfficeBlock::doBureaucracy(std::string form, std::string target)
{
	if (this->_intern == NULL || this->_signer == NULL || this->_executor == NULL)
		throw OfficeBlock::MissingElementException();
	else
	{
		Form*	formToDo;
		
		formToDo = this->_intern->makeForm(form, target);
		if (formToDo == NULL)
			throw OfficeBlock::InternException();
		this->_signer->signForm(*formToDo);
		if (formToDo->getSigned() == false)
			throw OfficeBlock::SignerException();
		this->_executor->executeForm(*formToDo);
	}
}
