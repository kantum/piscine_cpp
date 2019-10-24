#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>

template< typename T >
class Array
{
	private:
		T		*_array;
		size_t	_size;


	public:
		Array(void) : _array(NULL), _size(0) { };
		Array(unsigned int n) : _array(new T[n]), _size(n) { };
		Array(Array const & src) : _array(NULL), _size(0)
	{
		*this = src;
	}

		~Array(void)
		{
			if (this->_array != NULL)
				std::cout << "hello";
			else
				std::cout << "not null";
		}
		//Array & operator=(Array const & rhs);

		//class ArrayException : public std::exception
		//{
		//	public:
		//		ArrayException(void);
		//		ArrayException(ArrayException const &obj);
		//		virtual ~ArrayException(void) throw();
		//		ArrayException &operator=(ArrayException const &rhs);
		//		virtual const char* what() const throw();
		//};

//		size_t		size(void) const;
//		operator char(void) const;
		//operator int(void) const;
		operator T(void) const;
//		operator float(void) const;
//		operator double(void) const;
//
		T& operator[](std::size_t idx)             { return this->_array[idx]; }
		const T& operator[](std::size_t idx) const { return this->_array[idx]; }
};

template<typename T> std::ostream& operator<<(std::ostream &out, const Array<T> & a)
{
	//std::cout.precision(1);
	//out << setiosflags(std::ios::fixed);
	out << "Array (";
	out << a.getsize();
	out << ")";
};

#endif
