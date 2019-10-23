#ifndef SCALAR_HPP
# define SCALAR_HPP
#include <iostream>

class Scalar
{
	private:
		std::string _input;

	public:
		Scalar(void);
		Scalar(std::string input);
		Scalar(Scalar const & src);
		virtual ~Scalar(void);
		Scalar & operator=(Scalar const & rhs);

		class ScalarException : public std::exception
		{
			public:
				ScalarException(void);
				ScalarException(ScalarException const &obj);
				virtual ~ScalarException(void) throw();
				ScalarException &operator=(ScalarException const &rhs);
				virtual const char* what() const throw();
		};

		operator char(void) const;
		operator int(void) const;
		operator float(void) const;
		operator double(void) const;
};

std::ostream& operator<<(std::ostream &out, const Scalar& c);

#endif
