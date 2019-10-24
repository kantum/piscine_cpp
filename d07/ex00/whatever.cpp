#include <iostream>
#include <string>


template<typename T> void		swap(T &x, T &y)
{
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template<typename T> T const &	max( T const & x,  T const & y)
{
	return (x >= y ? x : y);
}

template<typename T> T const &	min(T const &  x, T const &  y)
{
	return (x <= y ? x : y);
}

int main(void)
{
	std::cout << "==== PDF CODE ====" << std::endl;
	int	a = 2;
	int	b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "==== FLOAT ====" << std::endl;
	float	e = 0.02;
	float	f = 0.03;
	::swap( e, f );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	std::cout << "==== BOOL ====" << std::endl;
	bool	g = 1;
	bool	h = 0;
	::swap( g, h );
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;

	return 0;
}
