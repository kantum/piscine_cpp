#include <iostream>
#include <string>
#include "Scalar.hpp" 

Scalar::Scalar(std::string input) : _input(input)
{
}

Scalar::Scalar(Scalar const & src)
{
	*this = src;
}

Scalar::~Scalar(void)
{
	return;
}

Scalar &Scalar::operator=(Scalar const &rhs) 
{
	if (this != &rhs)
	{
		this->_input = rhs._input;
	}
	return (*this);
}

Scalar::operator char(void) const
{
	int ret = 0;

	try
	{
		ret = std::stoi(this->_input);
	}
	catch (const std::exception &e)
	{
		throw (ScalarException());
	}
	return (static_cast<char>(ret));
}

Scalar::operator int(void) const
{
	int ret = 0;
	try
	{
		ret = std::stoi(this->_input);
	}
	catch (const std::exception &e)
	{
		throw (ScalarException());
	}
	return (ret);
}

Scalar::operator float(void) const
{
	float ret = 0.0;
	try
	{
		ret = std::stof(this->_input);
	}
	catch (const std::exception &e)
	{
		throw (ScalarException());
	}
	return (ret);
}

Scalar::operator double(void) const
{
	float ret = 0.0;
	try
	{
		ret = std::stof(this->_input);
	}
	catch (const std::exception &e)
	{
		throw (ScalarException());
	}
	return (ret);
}

Scalar::ScalarException::ScalarException(void)
{
}

Scalar::ScalarException::ScalarException(ScalarException const &obj)
{
	*this = obj;
}

Scalar::ScalarException::~ScalarException(void) throw()
{
	return;
}

Scalar::ScalarException &Scalar::ScalarException::operator=(ScalarException const &rhs) 
{
	if (this != &rhs) { }
	return (*this);
}

const char* Scalar::ScalarException::what() const throw()
{
	return ("impossible");
}
